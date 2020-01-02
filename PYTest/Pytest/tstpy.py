import sys

def ok(i):
   mask = int(1)
   cont = 0
   for a in range(6):
              if((i>>a)&mask)==1 :
                     cont +=1
   return (cont == 2)
                     
       
o = 0;
for  i in range(64) :
   if True:
          o+=1
          s = bin(128+i)
          s = s[4:]
          s=s.replace('1','| ')
          s=s.replace('0',': ')
          print("%2d"%o,'  ',s)

   