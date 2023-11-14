#메인 창

import sys
import os
from PyQt5.QtWidgets import *
from PyQt5.QtGui import *
from PyQt5.QtCore import *
from PyQt5 import uic
import images_rc

import serial
import time

def resource_path(relative_path):
    """Get the absolute path
    
    to the resource, works for dev and for PyInstaller"""
    try:
        # PyInstaller creates a temp folder and stores path in _MEIPASS
        base_path = sys._MEIPASS
    except Exception:
        base_path = os.path.abspath(".")
    return os.path.join(base_path, relative_path)


form_class1 = uic.loadUiType(resource_path('main_window.ui'))[0]
form_class2 = uic.loadUiType(resource_path('secondwindow.ui'))[0]
form_class3 = uic.loadUiType(resource_path('thrid_window.ui'))[0] 
form_class4 = uic.loadUiType(resource_path('fourth_window.ui'))[0]



vel1,vel2,vel3,vel4 = 0,0,0,0 
rad1,rad2,rad3,rad4 = 0,0,0,0
value1,value2,value3,value4,value5,value6,value7,value8,value9,value10 = 0,0,0,0,0,0,0,0,0,0
color_value = 0

total_vel = 0
total_rad = 0

global ardu



class MyWindow(QMainWindow, form_class1):  # 메인 페이지 창
    

    def __init__(self):
        super().__init__()
        self.setupUi(self)
        self.setFixedSize(800,455)
        self.changeLabelColor()
        
    
    def changeLabelColor(self):
        global color_value
        
        print(color_value)
        
        if color_value == 0:
            self.label_connect.setStyleSheet("color: red;")
            self.label_connect.setText("Disconnect")
        
        if color_value == 1:
            self.label_connect.setStyleSheet("color: green;")
            self.label_connect.setText("Connect")
    
    
    def page2(self):
        global vel1,vel2,vel3,vel4
        global rad1,rad2,rad3,rad4
        self.hide()

        self.second = secondwindow()
        self.second.exec()
        self.changeLabelColor()
        self.label1.setText("  Curve : %d, Vel : %d" %(self.second.rad_1,self.second.vel_1))
        self.label2.setText("  Curve : %d, Vel : %d" %(self.second.rad_2,self.second.vel_2))
        self.label3.setText("  Curve : %d, Vel : %d" %(self.second.rad_3,self.second.vel_3))
        self.label4.setText("  Curve : %d, Vel : %d" %(self.second.rad_4,self.second.vel_4))

        vel1 = self.second.vel_1
        vel2 = self.second.vel_2
        vel3 = self.second.vel_3
        vel4 = self.second.vel_4

        rad1 = self.second.rad_1
        rad2 = self.second.rad_2
        rad3 = self.second.rad_3
        rad4 = self.second.rad_4

        self.show()
     
     
    def page3(self):
        self.hide()
        self.thrid=thrid_window()
        self.thrid.exec()
        self.changeLabelColor()
        self.show()
        

    def page4(self):

        self.hide()
        
        self.fourth = fourth_window() 
        
        self.fourth.exec()
        self.changeLabelColor()
        self.show()
        
        
    def function1(self):
        global vel1, rad1, total_rad, total_vel
        
        self.label1.setStyleSheet("color : orange; border-bottom : 1px solid orange;")
        self.label2.setStyleSheet("color : white; border-bottom : 1px solid orange;")
        self.label3.setStyleSheet("color : white; border-bottom : 1px solid orange;")
        self.label4.setStyleSheet("color : white; border-bottom : 1px solid orange;")
        
        total_vel = vel1 
        total_rad = rad1 * 5
        
        print(total_rad,total_vel)



    def function2(self):
        global vel1, rad1, total_rad, total_vel

        self.label1.setStyleSheet("color : white; border-bottom : 1px solid orange;")
        self.label2.setStyleSheet("color : orange; border-bottom : 1px solid orange;")
        self.label3.setStyleSheet("color : white; border-bottom : 1px solid orange;")
        self.label4.setStyleSheet("color : white; border-bottom : 1px solid orange;")

        total_vel = vel2 
        total_rad = rad2 * 5
        
        print(total_rad,total_vel)

    def function3(self):
        global vel1, rad1, total_rad, total_vel

        self.label1.setStyleSheet("color : white; border-bottom : 1px solid orange;")
        self.label2.setStyleSheet("color : white; border-bottom : 1px solid orange;")
        self.label3.setStyleSheet("color : orange; border-bottom : 1px solid orange;")
        self.label4.setStyleSheet("color : white; border-bottom : 1px solid orange;")

        total_vel = vel3 
        total_rad = rad3 * 5
        
        print(total_rad,total_vel)

    def function4(self):
        global vel1, rad1, total_rad, total_vel

        self.label1.setStyleSheet("color : white; border-bottom : 1px solid orange;")
        self.label2.setStyleSheet("color : white; border-bottom : 1px solid orange;")
        self.label3.setStyleSheet("color : white; border-bottom : 1px solid orange;")
        self.label4.setStyleSheet("color : orange; border-bottom : 1px solid orange;")

        total_vel = vel4 
        total_rad = rad4 * 5
        
        print(total_rad,total_vel)

    def left(self):
        global total_rad, total_vel
        global value1,value2,value3,value4,value5,value6,value7,value8,value9,value10
        
        ft="l"
        data = f"{total_rad},{total_vel},{value1},{value2},{value3},{value4},{value5},{value6},{value7},{value8},{value9},{value10},{ft}\n"
        
        try:
            ardu.write(data.encode('utf-8'))
        except:
            pass
        print(total_rad,total_vel)

    def right(self):
        global total_rad, total_vel
        global value1,value2,value3,value4,value5,value6,value7,value8,value9,value10
        
        ft="r"
        data = f"{total_rad},{total_vel},{value1},{value2},{value3},{value4},{value5},{value6},{value7},{value8},{value9},{value10},{ft}\n"
        
        try:
            ardu.write(data.encode('utf-8'))
        except:
            pass
        
        print(total_rad,total_vel)
    
    def w(self):
        global total_rad, total_vel
        global value1,value2,value3,value4,value5,value6,value7,value8,value9,value10
        
        ft="w"
        data = f"{total_rad},{total_vel},{value1},{value2},{value3},{value4},{value5},{value6},{value7},{value8},{value9},{value10},{ft}\n"
        
        try:
            ardu.write(data.encode('utf-8'))
        except:
            pass
        
        print(total_rad,total_vel)

    def a(self):
        global total_rad, total_vel
        global value1,value2,value3,value4,value5,value6,value7,value8,value9,value10
        
        ft="a"
        data = f"{total_rad},{total_vel},{value1},{value2},{value3},{value4},{value5},{value6},{value7},{value8},{value9},{value10},{ft}\n"
        
        try:
            ardu.write(data.encode('utf-8'))
        except:
            pass
        
        print(total_rad,total_vel)
        
    def s(self):
        global total_rad, total_vel
        global value1,value2,value3,value4,value5,value6,value7,value8,value9,value10
        
        ft="s"
        data = f"{total_rad},{total_vel},{value1},{value2},{value3},{value4},{value5},{value6},{value7},{value8},{value9},{value10},{ft}\n"
        
        try:
            ardu.write(data.encode('utf-8'))
        except:
            pass
        
                                                                                                      
    def d(self):
        global total_rad, total_vel
        global value1,value2,value3,value4,value5,value6,value7,value8,value9,value10
        
        ft="d"
        data = f"{total_rad},{total_vel},{value1},{value2},{value3},{value4},{value5},{value6},{value7},{value8},{value9},{value10},{ft}\n"

        try:
            ardu.write(data.encode('utf-8'))
        except:
            pass
        
        print(total_rad,total_vel)    
    
    def home(self):
        global total_rad, total_vel
        global value1,value2,value3,value4,value5,value6,value7,value8,value9,value10
        
        ft="h"
        data = f"{total_rad},{total_vel},{value1},{value2},{value3},{value4},{value5},{value6},{value7},{value8},{value9},{value10},{ft}\n"

        try:
            ardu.write(data.encode('utf-8'))
        except:
            pass
        
        
class secondwindow(QDialog,QWidget, form_class2): # 뱀 로봇 설정 창
    
    global vel,rad,data,state
    vel = 0
    rad = 0
    state = 0
    data = [[0 for j in range(2)] for i in range(4)]

    def __init__(self):
        super(secondwindow,self).__init__()
        self.setupUi(self)
        self.setFixedSize(800,455)
        self.radius.repaint()
        self.velocity.repaint()
        self.changeLabelColor()
        self.show()




    def set_1(self):
        global data,state,rad,vel
        state =0
        rad = data[state][0]
        vel = data[state][1]
        
        self.pushButton.setIcon(QIcon(":/images/gui_png/btn1_1.png"))
        self.pushButton_2.setIcon(QIcon(":/images/gui_png/btn2.png"))
        self.pushButton_3.setIcon(QIcon(":/images/gui_png/btn3.png"))
        self.pushButton_4.setIcon(QIcon(":/images/gui_png/btn4.png"))
        
        self.radius.setText("%d" %data[state][0])
        self.velocity.setText("%d" %data[state][1])

    def set_2(self):
        global data,state,rad,vel
        state =1
        rad = data[state][0]
        vel = data[state][1]
        
        self.pushButton.setIcon(QIcon(":/images/gui_png/btn1.png"))
        self.pushButton_2.setIcon(QIcon(":/images/gui_png/btn2_1.png"))
        self.pushButton_3.setIcon(QIcon(":/images/gui_png/btn3.png"))
        self.pushButton_4.setIcon(QIcon(":/images/gui_png/btn4.png"))
        
        self.radius.setText("%d" %data[state][0])
        self.velocity.setText("%d" %data[state][1])


    def set_3(self):
        global data,state,rad,vel
        state =2
        rad = data[state][0]
        vel = data[state][1]
        
        self.pushButton.setIcon(QIcon(":/images/gui_png/btn1.png"))
        self.pushButton_2.setIcon(QIcon(":/images/gui_png/btn2.png"))
        self.pushButton_3.setIcon(QIcon(":/images/gui_png/btn3_1.png"))
        self.pushButton_4.setIcon(QIcon(":/images/gui_png/btn4.png"))
        
        self.radius.setText("%d" %data[state][0])
        self.velocity.setText("%d" %data[state][1])


    def set_4(self):
        global data,state,rad,vel
        state =3
        rad = data[state][0]
        vel = data[state][1]
        
        self.pushButton.setIcon(QIcon(":/images/gui_png/btn1.png"))
        self.pushButton_2.setIcon(QIcon(":/images/gui_png/btn2.png"))
        self.pushButton_3.setIcon(QIcon(":/images/gui_png/btn3.png"))
        self.pushButton_4.setIcon(QIcon(":/images/gui_png/btn4_1.png"))
        
        self.radius.setText("%d" %data[state][0])
        self.velocity.setText("%d" %data[state][1])


    def page1(self):

        global data

        self.rad_1 = data[0][0]
        self.vel_1 = data[0][1] 
        self.rad_2 = data[1][0]
        self.vel_2 = data[1][1]
        self.rad_3 = data[2][0]
        self.vel_3 = data[2][1]
        self.rad_4 = data[3][0]
        self.vel_4 = data[3][1]

        self.close()



    def rad_up(self):

        global vel,rad

        rad = rad + 1
        self.radius.setText("%d" %rad)



    def rad_down(self):

        global vel,rad

        rad = rad -1
        
        if rad < 0:
            rad = 0
        self.radius.setText("%d" %rad)



    def vel_up(self):

        global vel,rad

        vel = vel + 1
        self.velocity.setText("%d" %vel)



    def vel_down(self):

        global vel,rad

        vel = vel - 1
        
        if vel < 0:
            vel = 0
        self.velocity.setText("%d" %vel)



    def save(self):

        global data, rad, vel

        data[state][0] = rad
        data[state][1] = vel

        self.velocity.setText("%d" %vel)
        self.radius.setText("%d" %rad)
        
        
    def changeLabelColor(self):
        
        if color_value == 0:
            self.label_connect.setStyleSheet("color: red;")
            self.label_connect.setText("Disconnect")
        
        if color_value ==1:
            self.label_connect.setStyleSheet("color: green;")
            self.label_connect.setText("Connect")
            
            
class thrid_window(QDialog,QWidget, form_class3): # 모터 개별 작동 창
    
    
         
    def __init__(self):
        super(thrid_window,self).__init__()
        self.setFixedSize(800,455)
        self.initUI()
        self.show()


        
    def initUI(self):
        
        self.setupUi(self)
        self.changeLabelColor()
        
        self.dial1.setMinimum(0)
        self.dial1.setMaximum(180)
        self.dial1.valueChanged.connect(self.lcd1.display)
        
        
        self.dial2.setMinimum(0)
        self.dial2.setMaximum(180)
        self.dial2.valueChanged.connect(self.lcd2.display)
        
        self.dial3.setMinimum(0)
        self.dial3.setMaximum(180)
        self.dial3.valueChanged.connect(self.lcd3.display)
        
        self.dial4.setMinimum(0)
        self.dial4.setMaximum(180)
        self.dial4.valueChanged.connect(self.lcd4.display)
 
        self.dial5.setMinimum(0)
        self.dial5.setMaximum(180)
        self.dial5.valueChanged.connect(self.lcd5.display)
        
        self.dial6.setMinimum(0)
        self.dial6.setMaximum(180)
        self.dial6.valueChanged.connect(self.lcd6.display)
        
        self.dial7.setMinimum(0)
        self.dial7.setMaximum(180)
        self.dial7.valueChanged.connect(self.lcd7.display)
        
        self.dial8.setMinimum(0)
        self.dial8.setMaximum(180)
        self.dial8.valueChanged.connect(self.lcd8.display)
        
        self.dial9.setMinimum(0)
        self.dial9.setMaximum(180)
        self.dial9.valueChanged.connect(self.lcd9.display)     

        self.dial10.setMinimum(0)
        self.dial10.setMaximum(180)
        self.dial10.valueChanged.connect(self.lcd10.display)
    
    
    def send(self):
        global vel
        global total_vel, total_rad
        value1 =(self.lcd1.value())
        value2 =(self.lcd2.value())
        value3 =(self.lcd3.value())
        value4 =(self.lcd4.value())
        value5 =(self.lcd5.value())
        value6 =(self.lcd6.value())
        value7 =(self.lcd7.value())
        value8 =(self.lcd8.value())
        value9 =(self.lcd9.value())
        value10 =(self.lcd10.value())
        
        ft="g"
        data = f"{total_vel},{total_rad},{value1},{value2},{value3},{value4},{value5},{value6},{value7},{value8},{value9},{value10},{ft}\n"

        try:
            ardu.write(data.encode('utf-8'))
        except:
            pass

    
    def page1(self):
        self.close()
        

    def changeLabelColor(self):
        
        if color_value == 0:
            self.label_connect.setStyleSheet("color: red;")
            self.label_connect.setText("Disconnect")
        
        if color_value ==1:
            self.label_connect.setStyleSheet("color: green;")
            self.label_connect.setText("Connect")
        
class fourth_window(QDialog,QWidget, form_class4): # 통신 설정 창
    
    global serial_data
    
    def change(self):
        global combo
        combo = self.combo.currentText()
        print(combo)
        
    def __init__(self):
        super(fourth_window,self).__init__()
        self.initUI()
        self.setFixedSize(800,455)
        self.changeLabelColor()
        self.setting()
        self.show()

    def serial_connect(self):
        global ardu
        ardu.write(('1\n').encode())
    

    def initUI(self):
        self.setupUi(self)
        
    def connect(self):
        global ardu
        global combo
        global color_value
    
        try:
            ardu = serial.Serial(combo, 9600)
            color_value=1
            self.changeLabelColor()
            print("connect")
            print(color_value)

        except:
            color_value=0
            print('Cannot connect to the port')
            print(color_value)
            

    def changeLabelColor(self):
        global color_value
        
        print(color_value)
        
        if color_value == 0:
            self.label_connect.setStyleSheet("color: red;")
            self.label_connect.setText("Disconnect")
        
        if color_value == 1:
            self.label_connect.setStyleSheet("color: green;")
            self.label_connect.setText("Connect")
            
    def setting(self):
        self.combo.currentIndexChanged.connect(self.change)

    def page1(self):
        self.close()      


if __name__ =='__main__':
    app = QApplication(sys.argv)
    mywindow = MyWindow()

    mywindow.show()
    app.exec_()