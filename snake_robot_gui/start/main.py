import sys
from PyQt5.QtWidgets import *
from PyQt5 import uic


form_class = uic.loadUiType('main_window.ui')[0]

class MyWindow(QMainWindow, form_class):
    def __init__(self):
        super().__init__()
        self.setupUi(self)

    def page2():
        pass
if __name__ =='__main__':
    app = QApplication(sys.argv)
    mywindow = MyWindow()
    mywindow.show()
    app.exec_()
