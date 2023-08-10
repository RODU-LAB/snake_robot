import sys
from PyQt5.QtWidgets import *
from PyQt5.QtGui import *
from PyQt5.QtCore import *
from PyQt5 import uic
from sub import secondwindow
import serial
import time
from enum import Enum
from joystick import *

form_class = uic.loadUiType('main_window.ui')[0]

ardu = serial.Serial('/dev/ttyACM1', 9600)


vel1,vel2,vel3,vel4 = 0,0,0,0 
rad1,rad2,rad3,rad4 = 0,0,0,0


class MyWindow(QMainWindow, form_class):
    def __init__(self):
        super().__init__()
        self.setupUi(self)


    def page2(self):
        global vel1,vel2,vel3,vel4
        global rad1,rad2,rad3,rad4
        self.hide()

        self.second = secondwindow()
        self.second.exec()
        self.label1.setText("반지름 : %d, 속도 : %d" %(self.second.rad_1,self.second.vel_1))
        self.label2.setText("반지름 : %d, 속도 : %d" %(self.second.rad_2,self.second.vel_2))
        self.label3.setText("반지름 : %d, 속도 : %d" %(self.second.rad_3,self.second.vel_3))
        self.label4.setText("반지름 : %d, 속도 : %d" %(self.second.rad_4,self.second.vel_4))

        vel1 = self.second.vel_1
        vel2 = self.second.vel_2
        vel3 = self.second.vel_3
        vel4 = self.second.vel_4

        rad1 = self.second.rad_1
        rad2 = self.second.rad_2
        rad3 = self.second.rad_3
        rad4 = self.second.rad_4

        self.show()


    def function1(self):
        global vel1, rad1
        ft="a"
        data = f"{ft},{vel1},{rad1}\n"
        ardu.write(data.encode('utf-8'))


    def function2(self):
        global vel2, rad2
        ft="b"
        data = f"{ft},{vel2},{rad2}\n"
        ardu.write(data.encode('utf-8'))



    def function3(self):
        global vel3, rad3
        ft="c"
        data = f"{ft},{vel3},{rad3}\n"
        ardu.write(data.encode('utf-8'))



    def function4(self):
        global vel4, rad4
        ft="d"
        data = f"{ft},{vel4},{rad4}\n"
        ardu.write(data.encode('utf-8'))




    def left(self):
        ft="l"
        data = f"{ft},{vel1},{rad1}\n"
        ardu.write(data.encode('utf-8'))

    


    def right(self):
        ft="r"
        data = f"{ft},{vel1},{rad1}\n"
        ardu.write(data.encode('utf-8'))




if __name__ =='__main__':
    app = QApplication(sys.argv)
    mywindow = MyWindow()

    mywindow.show()
    app.exec_()
