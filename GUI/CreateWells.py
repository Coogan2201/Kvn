from tkinter import *


def create_wells(self, size):
    well=[]
    self.des = Frame(self,width=350,height=350, bg='blue')
    self.des.grid()
    self.canvas = Canvas(self.des, width = 300, height = 300, border=2)
    self.canvas.grid()
    count = 0
    def _create_circle(x, y, r,**kwargs):
        return self.canvas.create_oval(x-r, y-r, x+r, y+r, **kwargs)
    
    cols=0
    rows=0
    wells=0
    
    if(size == '6'):
        cols=3
        rows=2
        wells=6
        self.canvas.create_rectangle(20, 150, 225, 20)
    if(size == '24'):
        cols=6
        rows=4
        wells=24
        self.canvas.create_rectangle(20, 150, 225, 20)
    if(size == '96'):
        cols=12
        rows=8
        wells=96        
        self.canvas.create_rectangle(20, 150, 225, 20)    
        
    def onObjectClick(event):
        self.wellFinder=(event.widget.find_closest(event.x, event.y))
        self.buttonFill = event.widget.itemcget(self.wellFinder,"fill")
        for x in range(0,wells):
            if self.wellFinder==(x,):
                if(self.buttonFill == "white"):
                    self.canvas.itemconfig(well[x-2],fill="green")
                if(self.buttonFill =="green"):
                    self.canvas.itemconfig(well[x-2],fill="white")
        self.buttonFill2 = event.widget.itemcget(self.wellFinder,"fill")

        

    for y in range(0,rows):
        for x in range(0,cols):
            well.append(_create_circle(100+x*60,100+y*60,25/cols,fill="white", activefill="cyan"))
            self.canvas.tag_bind(well[count],'<Double-1>',onObjectClick)
            count=count+1 
