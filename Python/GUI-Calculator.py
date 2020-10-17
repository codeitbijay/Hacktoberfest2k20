from tkinter import *
w= Tk()
w.title('Calculator')
fr= LabelFrame(w, pady= 10)
fr.pack(padx =5, pady =5)
e= Entry(fr, width= 35, borderwidth= 4)
e.grid(column= 0, row=0, columnspan= 3, padx=10, pady=10)
ls=[]
def bc(n):
    current= e.get()
    e.delete(0, END)
    e.insert(0, str(current) + str(n))
def clear():
    e.delete(0, END)
def numop(op):
    if 'ERROR.....!!!' in e.get():
        clear()
        return
    if e.get().startswith('0') and len(e.get())!=1:
        num=eval(e.get()[1:])
    else:
        num=eval(e.get())
    e.delete(0, END)
    global ls
    ls.append(num)
    ls.append(op)
def eq():
    if 'ERROR.....!!!' in e.get():
        clear()
        return
    if e.get().startswith('0') and len(e.get())!=1:
        num= eval(e.get()[1:])
    else:
        num=eval(e.get())
    e.delete(0, END)
    global ls
    ls.append(num)
    e.insert(0,math(ls))
    ls.clear()
def math(l):
    bal= l[0]
    for i in range(1,len(l)):
        if l[i]=='+':
            bal+=l[i+1]
        elif l[i]=='-':
            bal-=l[i+1]
        elif l[i]=='x':
            bal*=l[i+1]
        elif l[i]=='/':
            try:
                bal/=l[i+1]
            except Exception as ex:
                print('Error',ex)
                return 'ERROR.....!!!'
    return bal
#Button defs

but_0= Button(fr, text='0', padx=40, pady=20, command=lambda: bc(0))
but_1= Button(fr, text='1', padx=40, pady=20, command=lambda: bc(1))
but_2= Button(fr, text='2', padx=40, pady=20, command=lambda: bc(2))
but_3= Button(fr, text='3', padx=40, pady=20, command=lambda: bc(3))
but_4= Button(fr, text='4', padx=40, pady=20, command=lambda: bc(4))
but_5= Button(fr, text='5', padx=40, pady=20, command=lambda: bc(5))
but_6= Button(fr, text='6', padx=40, pady=20, command=lambda: bc(6))
but_7= Button(fr, text='7', padx=40, pady=20, command=lambda: bc(7))
but_8= Button(fr, text='8', padx=40, pady=20, command=lambda: bc(8))
but_9= Button(fr, text='9', padx=40, pady=20, command=lambda: bc(9))

but_equ= Button(fr, text='=', padx=91, pady=20, command=eq)
but_clr= Button(fr, text='clear', padx=81, pady=20, command=clear)
# math
but_add= Button(fr, text='+', padx=39, pady=20, command=lambda: numop('+'))
but_sub= Button(fr, text='-', padx=41, pady=20, command=lambda: numop('-'))
but_mul= Button(fr, text='X',padx=40, pady=20, command=lambda: numop('x'))
but_div= Button(fr, text='/', padx=41, pady=20, command= lambda: numop('/'))
# layering
but_0.grid(row='4',column='0')

but_1.grid(row='3',column='0')
but_2.grid(row='3',column='1')
but_3.grid(row='3',column='2')

but_4.grid(row='2',column='0')
but_5.grid(row='2',column='1')
but_6.grid(row='2',column='2')

but_7.grid(row='1',column='0')
but_8.grid(row='1',column='1')
but_9.grid(row='1',column='2')

but_add.grid(row= 5,column=0)
but_equ.grid(row= 5,column=1,columnspan=2)
but_clr.grid(row= 4,column=1,columnspan=2)

but_sub.grid(row=6, column =0)
but_mul.grid(row=6, column=1)
but_div.grid(row=6, column=2)
w.mainloop()
