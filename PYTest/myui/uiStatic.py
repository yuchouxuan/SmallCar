
STATIC_COLOR = {'WOB':1, 'BOW':2,  'BOG':3, 'BOY':4, 'WOR':5, 'GOB':6, 'YOB':7,'ROB':8}

class uiobj(object) :
    w = 20
    x = 0
    y = 0
    title = 'OBJ'
    src =0
    color = 0
    clc = [50,90] # GYR

    def __init__(self, ix,iy,ititle,iw, iclc, icolor,*args, **kwargs):
        self.x =ix
        self.y = iy
        self.w = iw
        self.color = icolor
        self.title = ititle
        self.clc = iclc
        self.f_change = uiobj.doNothing
        self.f_OnChange = uiobj.doNothing
        return super().__init__()
        
    def draw(self,*k):
        pass
    def Change(**kw):
        pass
    def OnChange(**kw):
        pass
    def doNothing(**kw):
        pass 