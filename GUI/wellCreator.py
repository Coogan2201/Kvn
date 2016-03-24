from tkinter import *


def create_wells(self, size):
    well=[]
    self.canvas = Canvas(self,width = 500, height = 500)
    self.canvas.grid(row=0,column=0)
    T = Text(self.canvas, height=1, width=25)
    T.insert(END, "Selective active wells")
    T.grid()
    T.place(x=175,y=50)
    
    SelectButton=Button(self,text="Select!",command=lambda:select_size(self))
    SelectButton.grid()
    SelectButton.place(x=175,y=20)
   # GoButton=Button(self,text="Move!")
   # GoButton.grid()
   # GoButton.bind('<Button-1>',self.buttonPressing)
    
    count = 0
    def _create_circle(x, y, r,**kwargs):
        return self.canvas.create_oval(x-r, y-r, x+r, y+r, **kwargs)
    
    cols=0
    rows=0
    wells=0
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
    
    if(size == '6'):
        cols=3
        rows=2
        wells=6
        self.canvas.create_rectangle(30, 200, 530, 500, fill = "red")
        for y in range(0,rows):
            for x in range(0,cols):
                well.append(_create_circle(100+(39*x),400+(39*y),17.5,fill="white", activefill="cyan"))
                self.canvas.tag_bind(well[count],'<Double-1>',onObjectClick)
                count=count+1
    if(size == '24'):
        cols=6
        rows=4
        wells=24
        self.canvas.create_rectangle(10, 500, 138, 200, fill = "red")
        for y in range(0,rows):
            for x in range(0,cols):
                well.append(_create_circle(100+(19*x),100+(19*y),8,fill="white", activefill="cyan"))
                self.canvas.tag_bind(well[count],'<Double-1>',onObjectClick)
                count=count+1
                
    if(size == '96'):
        cols=12
        rows=8
        wells=96        
        self.canvas.create_rectangle(10, 10, 138, 96, fill = "red")
        for y in range(0,rows):
            for x in range(0,cols):
                well.append(_create_circle(24+(9*x),22+(9*y),2.7,fill="white", activefill="cyan"))
                self.canvas.tag_bind(well[count],'<Double-1>',onObjectClick)
                count=count+1
        

    self.varWells = StringVar(self)
    self.wellChoice = {'6': '6', '24':'24','96':'96'}
    self.wellOption = OptionMenu(self, self.varWells, *self.wellChoice, command=select_size)
    self.varWells.set('What size plate are you using?')
    self.wellOption_w=self.canvas.create_window(100,100,window=self.wellOption)
    self.wellOption.place(x=175,y=150)


        
def select_size(self):
    if(self.varWells.get() == '6'):
        self.canvas.grid_forget()
        self.canvas.destroy()
        create_wells(self,'6')
    if(self.varWells.get() == '24'):
        self.canvas.grid_forget()
        self.canvas.destroy()
        create_wells(self,'24')
    if(self.varWells.get() == '96'):
        self.canvas.grid_forget()
        self.canvas.destroy()
        create_wells(self,'96')
            
            
