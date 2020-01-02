import numpy as np
import matplotlib as mpl
import mpl_toolkits.mplot3d as d3
import math 
A = (0,0,0)
B = (2* math.sqrt(3), 0,0)
C = (-1*math.sqrt(3),3,0)
P = (0,0,4)

d = 0.005

dxx = 1
def distance(pa=(0,0,0) ,pb=(0,0,0)):
    dx =(pa[0]-pb[0])**2  +(pa[1]-pb[1])**2+(pa[2]-pb[2])**2
    return math.sqrt(dx)

def narx(li =[]):
    avg = 0 
    for num in li: avg +=num
    avg /= len(li)
    
    ma=0
    for num in li: ma +=(num - avg)**2
    ma /=len(li)
    return ma

mo =()
md = 100;

for ix  in range(0,1000):
    for iy in range(0,1000):
        for iz in range(0,1000):
            O =(1.7+ix*d,2.8+iy*d,1.8+iz*d) 
            da = distance(O,A) 
            db= distance(O,B) 
            dc = distance(O,C)
            dp = distance(O,P)   
            dpx = narx([da,db,dc,dp])                                   
            if dpx < md: 
                md = dpx
                ostr =  str(O)  +"   -dist-  "+ str(narx([da,db,dc,dp]))
                print(ostr )
                