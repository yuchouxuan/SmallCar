import curses
from uiStatic  import uiobj
from uiStatic  import STATIC_COLOR as cl
import math

class anaBar(uiobj):
    max =100
    min =-100
    mid = 0
    pos =0
    bb = 8
    titl = 7
    isInt = False 
    noNum = False
    def __init__(self, ix=0, iy=0,ipos=0, imax=100,imid =0,imin =-100, iw=20, iclc=[75,90],ibb=14 ,ititle='AnaBar' ,ititl = 7 ,icolor = [cl['WOB'],cl['BOG'],cl['BOY'],cl['WOR']], *args, **kwargs):
        self.bb = ibb
        self.titl = ititl
        self.pos = ipos
        self.max = imax
        self.mid = imid
        self.min = imin
        super().__init__(ix, iy, ititle, iw, iclc, icolor, *args, **kwargs)
    def _setpos(self,ipos):
        if type(ipos) != int and type(ipos) != float : ipos = self.pos
        pos = self.pos =ipos
        if pos > self.max : pos = self.max
        elif pos < self.min: pos = self.min
        hfw = int(self.w /2)
        if pos < self.mid : pos = hfw - math.fabs(hfw * pos /(self.mid -self.min))
        else : pos = hfw + math.fabs(hfw * pos /(self.max -self.mid))
        return int(pos)
       
    def draw(self, ipos='S'):
        pos = self._setpos(ipos)
        titout = ('{:<%d}:' %self.titl ).format(self.title) 
        if len(self.title) == 0: titout =''
        if not self.noNum :
            if self.isInt : titout += '%d' %int(self.pos)
            else : titout += '%.2f' %self.pos 
        if self.pos > self.max  or self.pos < self.min: 
            self.src.addstr(self.y,self.x,titout,curses.color_pair(cl['ROB']))
        else : 
            self.src.addstr(self.y,self.x,titout)
        if self.pos < self.min : self.src.addstr(self.y,self.bb,'<',curses.color_pair(self.color[2]))
        else :self.src.addstr(self.y,self.bb,'|')
        hfw = int(self.w /2)
        self.src.addstr(self.y,self.bb+1,'-'*(self.w+1),curses.color_pair(self.color[0]))
        self.src.addstr(self.y,self.bb+1+hfw,'+')
        if pos == hfw : self.src.addstr(self.y,self.bb+1+hfw,'+',curses.color_pair(self.color[1]) )
        elif pos < hfw : 
            for i in range(pos,hfw):
                self.src.addstr(self.y,self.bb+1+i,'-',curses.color_pair(self.color[2]) )
        elif pos > hfw :
            for i in range(hfw,pos):
              self.src.addstr(self.y,self.bb+1+i+1,'-',curses.color_pair(self.color[3]) )
  
        if self.pos > self.max : self.src.addstr(self.y,self.bb+2+self.w,'>',curses.color_pair(self.color[3]) )
        else :self.src.addstr(self.y,self.bb+2+self.w,'|')

class anaBarA(anaBar):
    block = '█'
    def __init__(self, ix = 0, iy = 0, ipos = 0, imax = 100, imid = 0, imin = -100, iw = 20, iclc = [], ibb = 14, ititle = 'AnaBar', ititl = 7, icolor = [cl['WOB'],cl['GOB'],cl['YOB'],cl['ROB']], *args, **kwargs):
        return super().__init__(ix, iy, ipos, imax, imid, imin, iw, iclc, ibb, ititle, ititl, icolor, *args, **kwargs)
    def draw(self, ipos = 'S'):
        pos = self._setpos(ipos)
        titout = ('{:<%d}:' %self.titl ).format(self.title) 
        if len(self.title) == 0: titout =''
        if not self.noNum :
            if self.isInt : titout += '%d' %int(self.pos)
            else : titout += '%.2f' %self.pos 
        self.src.addstr(self.y,self.x,titout)
        if self.pos < self.min : self.src.addstr(self.y,self.bb,'<',curses.color_pair(self.color[2]))
        else :self.src.addstr(self.y,self.bb,'|')
        hfw = int(self.w /2)
        self.src.addstr(self.y,self.bb+1,'-'*(self.w+1),curses.color_pair(self.color[0]))
        self.src.addstr(self.y,self.bb+1+hfw,'|')
        if pos == hfw : self.src.addstr(self.y,self.bb+1+hfw,self.block,curses.color_pair(self.color[1]) )
        elif pos < hfw : 
            for i in range(pos,hfw):
                self.src.addstr(self.y,self.bb+1+i,'━',curses.color_pair(self.color[2]) )
            self.src.addstr(self.y,self.bb+pos+1,self.block,curses.color_pair(self.color[2]) )
        elif pos > hfw :
            for i in range(hfw,pos):
              self.src.addstr(self.y,self.bb+1+i+1,'━',curses.color_pair(self.color[3]) )
            self.src.addstr(self.y,self.bb+pos,self.block,curses.color_pair(self.color[3]) )
        if self.pos > self.max : self.src.addstr(self.y,self.bb+2+self.w,'>',curses.color_pair(self.color[3]))
        else :self.src.addstr(self.y,self.bb+2+self.w,'|')

class anaBarH1(anaBar):
    def draw(self, ipos = 'S'):
       pos = self._setpos(ipos)
       hfw = int(self.w /2)
