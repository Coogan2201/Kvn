from tkinter import *


def create_wells(self):

    des = Frame(self,width=350,height=350, bg='blue')
    des.grid()
    canvas = Canvas(des, width = 300, height = 300, border=2)
    canvas.grid()
    
    def onObjectClick(event):
        wellFinder=(event.widget.find_closest(event.x, event.y))
        if wellFinder==(1,):
            canvas.itemconfig(well1,fill="green")
        if wellFinder==(2,):
            canvas.itemconfig(well3,fill="green")
        if wellFinder==(3,):
            canvas.itemconfig(well5,fill="green")
        if wellFinder==(4,):
            canvas.itemconfig(well2,fill="green")
        if wellFinder==(5,):
            canvas.itemconfig(well4,fill="green")
        if wellFinder==(6,):
            canvas.itemconfig(well6,fill="green")
    
    def _create_circle(x, y, r,**kwargs):
        return canvas.create_oval(x-r, y-r, x+r, y+r, **kwargs)
    
    
    well1 = _create_circle(50,50,25,fill="white", activefill="red")
    well3 = _create_circle(120,50,25,fill="white", activefill="green")
    well5 = _create_circle(190,50,25,fill="white", activefill="blue")
    
    well2 = _create_circle(50,120,25,fill="white", activefill="white")
    well4 = _create_circle(120,120,25,fill="white", activefill="black")
    well6 = _create_circle(190,120,25,fill="white", activefill="cyan")
    canvas.create_rectangle(20, 150, 225, 20)
    
    canvas.tag_bind(well1,'<Double-1>',onObjectClick)
    canvas.tag_bind(well2,'<Double-1>',onObjectClick)
    canvas.tag_bind(well3,'<Double-1>',onObjectClick)
    canvas.tag_bind(well4,'<Double-1>',onObjectClick)
    canvas.tag_bind(well5,'<Double-1>',onObjectClick)
    canvas.tag_bind(well6,'<Double-1>',onObjectClick)
