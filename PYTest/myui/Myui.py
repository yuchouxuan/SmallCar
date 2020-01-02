import curses
import uiStatic
from anabar import *
import time
from Bars import *



class Myui(object):
    """description of class"""
    scr  =0
    itm = {}
    def __init__(self,iscr,fun, *args, **kwargs):
        scr = iscr

        curses.init_pair(1, curses.COLOR_WHITE, curses.COLOR_BLACK)
        curses.init_pair(2,  curses.COLOR_BLACK, curses.COLOR_WHITE)

        curses.init_pair(3, curses.COLOR_BLACK, curses.COLOR_GREEN)
        curses.init_pair(4, curses.COLOR_BLACK, curses.COLOR_YELLOW)
        curses.init_pair(5, curses.COLOR_WHITE, curses.COLOR_RED)

        curses.init_pair(6, curses.COLOR_GREEN, curses.COLOR_BLACK)
        curses.init_pair(7, curses.COLOR_YELLOW, curses.COLOR_BLACK)
        curses.init_pair(8, curses.COLOR_RED, curses.COLOR_BLACK)

        curses.init_pair(15, curses.COLOR_WHITE, curses.COLOR_BLACK)
        self.setui(fun)

        return super().__init__(*args, **kwargs)
        
    def draw(self): 
        self.scr.clear()
        for i in self.itm.values() :
            i.src = self.scr
            i.draw()
        self.scr.refresh()
    
    def setui(self,func): #部件初始化
        func(self)


def uif(ui): #
    ui.itm['L']=anaBar(1,1,ititle="LE")
    ui.itm['R']=anaBar(1,2,ititle="RE")

    ui.itm['B1']=probarH(3,3,w=5,ititle="B1")
    ui.itm['B1'].w =7
    ui.itm['B2']=probarH(5,3,w=5,ititle="B2")
    ui.itm['B2'].w =7
    ui.itm['B3']=probarH(7,3,w=5,ititle="B3")
    ui.itm['B3'].w =7
    ui.itm['B4']=probarH(9,3,w=5,ititle="B3")
    ui.itm['B4'].w =7
  

def mainloop(stdscr) :
    
    ui = Myui(stdscr,uif)
    #try:
    ui.itm['L'].pos =10
    ui.itm['B1'].pos = 80
    ui.itm['B2'].pos = 90
    ui.itm['B3'].pos = 30
    ui.itm['B4'].pos = 70
    while True:
            ui.scr = curses.initscr()
            #stdscr.clear()
            ui.scr = stdscr
            ui.draw()
            time.sleep(0.2)
            if ui.itm['L'].pos > 150 : ui.itm['L'].pos =-150
            ui.itm['L'].pos+=10

            
   # except : pass
curses.wrapper(mainloop)

 
