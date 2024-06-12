import tkinter as tk
import calendar 
  
def showCal():
    root =tk.Tk() 
    root.config(background = "white") 
    root.title("CALENDER") 
    root.geometry("550x600") 
    fetch_year = int(year_field.get()) 
    cal_content = calendar.calendar(fetch_year) 
    cal_year =tk. Label(root, text = cal_content, font = "Consolas 10 bold") 
    cal_year.grid(row = 5, column = 1, padx = 20)  
    root.mainloop() 
if __name__ == "__main__" : 
    win = tk.Tk() 
    win.config(background = "white") 
    win.title("CALENDER") 
    win.geometry("250x140") 
    year = tk.Label(win, text = "Enter Year", bg = "light cyan") 
    year.grid(row = 2, column = 0) 
  
    year_field = tk.Entry(win,bg = "light cyan") 
    year_field.grid(row = 2, column = 1) 
  
    show = tk.Button(win, text = "Show Calendar", fg = "Black", bg = "light yellow", command = showCal) 
    show.grid(row = 5, column = 0) 

    exit = tk.Button(win, text = "Exit", fg = "Black", bg = "light yellow", command = exit) 
    exit.grid(row = 5, column = 1) 
    win.mainloop() 
     
