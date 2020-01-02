import curses 
'''
      1:ACS_ULCORNER   ┌      2:ACS_LLCORNER   └     3:ACS_URCORNER   ┐

      4:ACS_LRCORNER   ┘      5:ACS_LTEE       ├     6:ACS_RTEE       ┤

      7:ACS_BTEE       ┴      8:ACS_TTEE       ┬     9:ACS_HLINE      ─

     10:ACS_VLINE      │     11:ACS_PLUS       ┼     12:ACS_S1         ⎺

     13:ACS_S9         ⎽      14:ACS_DIAMOND    ♦       15:ACS_CKBOARD    ▒

     16:ACS_DEGREE     °     17:ACS_PLMINUS    ±      18:ACS_BULLET     ·

     19:ACS_LARROW     ←     20:ACS_RARROW     →      21:ACS_DARROW     ↓

     22:ACS_UARROW     ↑     23:ACS_BOARD      ░       24:ACS_LANTERN    ¤

     25:ACS_BLOCK      █     26:ACS_S3         ⎻       27:ACS_S7         ⎼

     28:ACS_LEQUAL     ≤     29:ACS_GEQUAL     ≥      30:ACS_PI         π

     31:ACS_NEQUAL     ≠     32:ACS_STERLING   £       33:ACS_BSSB       ┌

     34:ACS_SSBB       └     35:ACS_BBSS       ┐     36:ACS_SBBS       ┘

     37:ACS_SBSS       ┤     38:ACS_SSSB       ├     39:ACS_SSBS       ┴

     40:ACS_BSSS       ┬     41:ACS_BSBS       ─     42:ACS_SBSB       │

     43:ACS_SSSS       ┼
'''

dic_ACS = {}
def idcinit():
    try : dic_ACS ["ACS_ULCORNER"]=curses.ACS_ULCORNER 
    except:pass
    try : dic_ACS ["ACS_LLCORNER"]=curses.ACS_LLCORNER    
    except:pass
    try : dic_ACS ["ACS_URCORNER"]=curses.ACS_URCORNER
    except:pass
    try : dic_ACS ["ACS_LRCORNER"]=curses.ACS_LRCORNER
    except:pass
    try : dic_ACS ["ACS_LTEE"]=curses.ACS_LTEE
    except:pass
    try : dic_ACS ["ACS_RTEE"]=curses.ACS_RTEE
    except:pass
    try : dic_ACS ["ACS_BTEE"]=curses.ACS_BTEE
    except:pass
    try : dic_ACS ["ACS_TTEE"]=curses.ACS_TTEE
    except:pass
    try : dic_ACS ["ACS_HLINE"]=curses.ACS_HLINE
    except:pass
    try : dic_ACS ["ACS_VLINE"]=curses.ACS_VLINE
    except:pass
    try : dic_ACS ["ACS_PLUS"]=curses.ACS_PLUS
    except:pass
    try : dic_ACS ["ACS_S1"]=curses.ACS_S1
    except:pass
    try : dic_ACS ["ACS_S9"]=curses.ACS_S9
    except:pass
    try : dic_ACS ["ACS_DIAMOND"]=curses.ACS_DIAMOND
    except:pass
    try : dic_ACS ["ACS_CKBOARD"]=curses.ACS_CKBOARD
    except:pass
    try : dic_ACS ["ACS_DEGREE"]=curses.ACS_DEGREE
    except:pass
    try : dic_ACS ["ACS_PLMINUS"]=curses.ACS_PLMINUS
    except:pass
    try : dic_ACS ["ACS_BULLET"]=curses.ACS_BULLET
    except:pass
    try : dic_ACS ["ACS_LARROW"]=curses.ACS_LARROW
    except:pass
    try : dic_ACS ["ACS_RARROW"]=curses.ACS_RARROW
    except:pass
    try : dic_ACS ["ACS_DARROW"]=curses.ACS_DARROW
    except:pass
    try : dic_ACS ["ACS_UARROW"]=curses.ACS_UARROW
    except:pass
    try : dic_ACS ["ACS_BOARD"]=curses.ACS_BOARD
    except:pass
    try : dic_ACS ["ACS_LANTERN"]=curses.ACS_LANTERN
    except:pass
    try : dic_ACS ["ACS_BLOCK"]=curses.ACS_BLOCK
    except:pass
    try : dic_ACS ["ACS_S3"]=curses.ACS_S3
    except:pass
    try : dic_ACS ["ACS_S7"]=curses.ACS_S7
    except:pass
    try : dic_ACS ["ACS_LEQUAL"]=curses.ACS_LEQUAL
    except:pass
    try : dic_ACS ["ACS_GEQUAL"]=curses.ACS_GEQUAL
    except:pass
    try : dic_ACS ["ACS_PI"]=curses.ACS_PI
    except:pass
    try : dic_ACS ["ACS_NEQUAL"]=curses.ACS_NEQUAL
    except:pass
    try : dic_ACS ["ACS_STERLING"]=curses.ACS_STERLING
    except:pass
    try : dic_ACS ["ACS_BSSB"]=curses.ACS_BSSB
    except:pass
    try : dic_ACS ["ACS_SSBB"]=curses.ACS_SSBB
    except:pass
    try : dic_ACS ["ACS_BBSS"]=curses.ACS_BBSS
    except:pass
    try : dic_ACS ["ACS_SBBS"]=curses.ACS_SBBS
    except:pass
    try : dic_ACS ["ACS_SBSS"]=curses.ACS_SBSS
    except:pass
    try : dic_ACS ["ACS_SSSB"]=curses.ACS_SSSB
    except:pass
    try : dic_ACS ["ACS_SSBS"]=curses.ACS_SSBS
    except:pass
    try : dic_ACS ["ACS_BSSS"]=curses.ACS_BSSS
    except:pass
    try : dic_ACS ["ACS_BSBS"]=curses.ACS_BSBS
    except:pass
    try : dic_ACS ["ACS_SBSB"]=curses.ACS_SBSB
    except:pass
    try : dic_ACS ["ACS_SSSS"]=curses.ACS_SSSS
    except:pass
   
  

def test(src = curses.initscr() ):

    curses.init_pair(1, curses.COLOR_RED, curses.COLOR_BLACK)
    idcinit()
    i=1
    for ks in dic_ACS :
         src.addstr('%7d:' %i + "{:<15}".format(ks)) 
         c = dic_ACS[ks];
         src.addch(c)    ;
         if i%3 == 0 :src.addstr("\n\n")
         i+=1
   
    src.refresh();
    src.getch()

curses.wrapper(test)

