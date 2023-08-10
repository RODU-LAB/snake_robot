import sys
from PyQt5.QtWidgets import *
from PyQt5 import uic


form_class = uic.loadUiType('secondwindow.ui')[0]

class secondwindow(QDialog,QWidget, form_class):

    global vel,rad,data,state
    vel = 0
    rad = 0
    state = 0
    data = [[0 for j in range(2)] for i in range(4)]

    def __init__(self):
        super(secondwindow,self).__init__()
        self.initUI()
        self.radius.repaint()
        self.velocity.repaint()
        self.show()


    def initUI(self):
        self.setupUi(self)


    def set_1(self):
        global data,state,rad,vel
        state =0
        rad = data[state][0]
        vel = data[state][1]
        self.radius.setText("%d" %data[state][0])
        self.velocity.setText("%d" %data[state][1])

    def set_2(self):
        global data,state,rad,vel
        state =1
        rad = data[state][0]
        vel = data[state][1]
        self.radius.setText("%d" %data[state][0])
        self.velocity.setText("%d" %data[state][1])


    def set_3(self):
        global data,state,rad,vel
        state =2
        rad = data[state][0]
        vel = data[state][1]
        self.radius.setText("%d" %data[state][0])
        self.velocity.setText("%d" %data[state][1])


    def set_4(self):
        global data,state,rad,vel
        state =3
        rad = data[state][0]
        vel = data[state][1]
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
        self.radius.setText("%d" %rad)



    def vel_up(self):

        global vel,rad

        vel = vel + 1
        self.velocity.setText("%d" %vel)



    def vel_down(self):

        global vel,rad

        vel = vel - 1
        self.velocity.setText("%d" %vel)



    def save(self):

        global data, rad, vel

        data[state][0] = rad
        data[state][1] = vel

        self.velocity.setText("%d" %vel)
        self.radius.setText("%d" %rad)


