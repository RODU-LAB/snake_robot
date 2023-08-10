from PyQt5.QtGui import *
from PyQt5.QtWidgets import *
from PyQt5.QtCore import *
import sys
from enum import Enum
import serial
import time


ardu = serial.Serial('/dev/ttyACM1', 9600)


class Direction(Enum):
    Left = 0
    Right = 1
    Up = 2
    Down = 3

class Joystick(QWidget):
    def __init__(self, parent=None):
        super(Joystick, self).__init__(parent)
        self.setMinimumSize(179, 184)
        self.movingOffset = QPointF(0, 0)
        self.grabCenter = False
        self.__maxDistance = 92

    def paintEvent(self, event):
        painter = QPainter(self)
        bounds = QRectF(-self.__maxDistance, -self.__maxDistance, self.__maxDistance * 2, self.__maxDistance * 2).translated(self._center())
        painter.drawEllipse(bounds)
        painter.setBrush(QColor(249,145,18))
        painter.drawEllipse(self._centerEllipse())

    def _centerEllipse(self):
        if self.grabCenter:
            return QRectF(-49, -49, 98, 98).translated(self.movingOffset)
        return QRectF(-49, -49, 98, 98).translated(self._center())

    def _center(self):
        return QPointF(self.width()/2, self.height()/2)


    def _boundJoystick(self, point):
        limitLine = QLineF(self._center(), point)
        if (limitLine.length() > self.__maxDistance):
            limitLine.setLength(self.__maxDistance)
        return limitLine.p2()

    def joystickDirection(self):
        if not self.grabCenter:
            return 0
        normVector = QLineF(self._center(), self.movingOffset)
        currentDistance = normVector.length()
        angle = normVector.angle()

        distance = min(currentDistance / self.__maxDistance, 1.0)
        if 45 <= angle < 135:
            ft="Up"
            data = f"{ft},{distance},{0}\n"
            ardu.write(data.encode('utf-8'))
            return (Direction.Up, distance)
            
        elif 135 <= angle < 225:
            ft="Left"
            data = f"{ft},{distance},{0}\n"
            ardu.write(data.encode('utf-8'))
            
            return (Direction.Left, distance)
        elif 225 <= angle < 315:
            ft="Down"
            data = f"{ft},{distance},{0}\n"
            ardu.write(data.encode('utf-8'))
            
            return (Direction.Down, distance)
        ft="Right"
        data = f"{ft},{distance},{0}\n"
        ardu.write(data.encode('utf-8'))
            
        return (Direction.Right, distance)


    def mousePressEvent(self, ev):
        self.grabCenter = self._centerEllipse().contains(ev.pos())
        return super().mousePressEvent(ev)

    def mouseReleaseEvent(self, event):
        self.grabCenter = False
        self.movingOffset = QPointF(0, 0)
        self.update()

    def mouseMoveEvent(self, event):
        if self.grabCenter:
            print("Moving")
            self.movingOffset = self._boundJoystick(event.pos())
            self.update()
        print(self.joystickDirection())


