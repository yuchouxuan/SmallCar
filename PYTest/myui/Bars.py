import curses
from uiStatic  import uiobj
from uiStatic  import STATIC_COLOR as cl


class probar(uiobj):
    max = 100
    w = 20
    x = 0
    y = 0
    bb = 8
    title = 'ProcBar'
    color = 0
    clc = [50,90] # GYR
    band="||<>"
    pos = 50
    src =0
    min = 0 
    isInt = False 
    noNum = False
    def _PosInit(self,ipos) :
        if type(ipos) != int and type(ipos) != float : pos = self.pos
        else :pos = ipos
        self.pos =  pos
        if pos > self.max : pos = self.max
        
        return (pos , int((pos-self.min)*self.w/(self.max-self.min))) 
    def _SelColor(self) :
        colornow = self.color[1]
        if self.pos > self.clc[1] : colornow = self.color[3]
        elif self.pos > self.clc[0]: colornow = self.color[2]
        return colornow


    def __init__(self, ix,iy,ititle="ProcBar",imax=100,iw=30,ibb=8,ipos=50, iband = "[]<>", iclc=[75,90], icolor = [cl['WOB'],cl['BOG'],cl['BOY'],cl['WOR']], *args, **kwargs):
        uiobj.__init__(self, ix,iy,ititle,iw, iclc, icolor,*args, **kwargs)
        self.pos=ipos
        self.max = imax
        if 'min' in kwargs : self.min = kwargs['min']
        if len(ititle) == 0 : self.bb =0 
        else :self.bb = ibb
        self.band = iband
 
    def draw(self,ipos='S'):
        pos,prop = self._PosInit(ipos)
        if(self.bb > 0) :self.src.addstr(self.y,self.x,('{:>%d}' %(self.bb) ).format(self.title))
        if self.pos < self.min : self.src.addstr(self.y,self.x+self.bb,self.band[2],curses.color_pair(cl['WOR']))
        else: self.src.addstr(self.y,self.x+self.bb,self.band[0])
        strin = ("{:<%d.2f}+" %(self.w)).format(self.pos)

        if self.isInt : strin = ("{:<%d.0f}" %(self.w)).format(self.pos)
        if self.noNum : strin = " "* self.w
        colornow = self._SelColor()
        
        for i in range(self.w) :
            if i <=prop : self.src.addstr(self.y,self.x+self.bb+1+i,strin[i],curses.color_pair(colornow))
            else : self.src.addstr(self.y,self.x+self.bb+1+i,strin[i],curses.color_pair(self.color[0]))
        
        if self.pos > self.max:   self.src.addstr(self.y,self.x+self.bb+self.w+1,self.band[3],curses.color_pair(cl['WOR']))
        else:  self.src.addstr(self.y,self.x+self.bb+self.w+1,self.band[1])

class probarA(probar):
    titl = 7
    style = "{:-<%d}"
    block = '▌'
    
    def __init__(self, ix,iy,ititle="ProcBar",imax=100,iw=20,ibb=14, ititl = 7 ,ipos=50,iband = "[]<>", iclc=[75,90], icolor = [cl['WOB'],cl['GOB'],cl['YOB'],cl['ROB']], *args, **kwargs):
        probar.__init__(self,ix,iy,ititle,imax,iw,ibb,ipos, iband, iclc, icolor,*args, **kwargs)
        self.titl = ititl
        if len(self.title) == 0 :  self.bb=ititl+1

    def draw(self,ipos='S'):
        pos,prop = self._PosInit(ipos)
        titout = ('{:<%d}:' %self.titl ).format(self.title) 
        if len(self.title) == 0: titout =''
        if not self.noNum :
            if self.isInt : titout += '%d' %int(self.pos)
            else : titout += '%.2f' %self.pos 
        
        if self.pos > self.max  or self.pos <  self.min: 
            self.src.addstr(self.y,self.x,titout,curses.color_pair(cl['ROB']))
        else : 
            self.src.addstr(self.y,self.x,titout)
        self.src.addstr(self.y,self.x+self.bb,self.band[0])
        strin = (self.style %(self.w)).format(self.block * prop)
        
        colornow = self._SelColor()
        self.src.addstr(self.y,self.x+self.bb+1,strin,curses.color_pair(colornow))
        
        self.src.addstr(self.y,self.x+self.bb+self.w+1,self.band[1])

class probarAH1(probarA):
    block = '▇'
    def draw(self, ipos = -1):
        pos,prop = self._PosInit(ipos)
        colornow = self._SelColor()
        if self.pos > self.max :self.src.addstr(self.y ,self.x, '=',curses.color_pair(cl['ROB']))

        for i in range(self.w):
            if i >= self.w-prop :self.src.addstr(self.y+i+1,self.x,self.block,curses.color_pair(colornow)) 
            else : self.src.addstr(self.y+i+1,self.x,'|',curses.color_pair(self.color[0]) )
        if self.pos <  self.min :self.src.addstr(self.y +self.w+1,self.x, '=',curses.color_pair(cl['ROB']))
        pass


class probarAH(probarAH1):

     def draw(self, ipos='S'):
         for i in range(self.w):
            self.src.addstr(self.y+i+1,self.x,'| |' )
         self.x+=1
         probarAH1.draw(self,ipos)
         self.x-=1

class probarH1(probar):
    lines = [' ',' ','|','=','=']
    
    def draw(self,ipos='S'):
        pos,prop = self._PosInit(ipos)
        colornow = self._SelColor()

        if self.pos > self.max :self.src.addstr(self.y,self.x,self.lines[4],curses.color_pair(cl['ROB'])) 
        else : self.src.addstr(self.y,self.x,self.lines[1]) 

        for i in range(self.w):
            if i < self.w-prop : self.src.addstr(self.y+i+1,self.x,self.lines[2]) 
            else : self.src.addstr(self.y+i+1,self.x,self.lines[2],curses.color_pair(colornow)) 

        if self.pos <  self.min : self.src.addstr(self.y+self.w+1,self.x,self.lines[3],curses.color_pair(cl['ROB'])) 
        else : self.src.addstr(self.y+self.w+1,self.x,self.lines[0]) 

class  probarH(probarH1):
    def draw(self, ipos='S'):
        for i in range(self.w) :
            self.src.addstr(self.y+i+1,self.x,'| |')
        self.x +=1 
        probarH1.draw(self,ipos)
        self.x -=1 
        
