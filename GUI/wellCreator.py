from tkinter import *


def create_wells(self, size):
    well=[]
    self.canvas = Canvas(self,width = 530, height = 500,bg='blue')
    self.canvas.grid(row=0,column=0)
    w = Label(self, text="Well selector")
    w.grid(column=1, row=0)
    w.place(x=210,y=40)

    self.canvas.create_rectangle(15, 180, 515, 480, fill = "red")

    count = 0
    def _create_circle(x, y, r,**kwargs):
        return self.canvas.create_oval(x-r, y-r, x+r, y+r, **kwargs)

    cols=0
    rows=0
    wells=0
    
    def onObjectClick(event):
        self.wellFinder=(event.widget.find_closest(event.x, event.y))
        self.buttonFill = event.widget.itemcget(self.wellFinder,"fill")
        for x in range(0,wells+3):
            if self.wellFinder==(x,):
                if(self.buttonFill == "white"):
                    self.canvas.itemconfig(well[x-3],fill="green", tag="green")
                if(self.buttonFill =="green"):
                    self.canvas.itemconfig(well[x-3],fill="white", tag="white")
        self.buttonFill2 = event.widget.itemcget(self.wellFinder,"fill")
        self.activeWell = self.canvas.find_withtag("green")
        #print(activeWell)
        
    if(size == '6'):
        cols=3
        rows=2
        wells=6
        self.canvas.create_rectangle(15, 180, 515, 480, fill = "red")
        for y in range(0,rows):
            for x in range(0,cols):
                well.append(_create_circle(115+(145*x),265+(125*y),50,fill="white", activefill="cyan"))
                self.canvas.tag_bind(well[count],'<Double-1>',onObjectClick)
                count=count+1
        

    if(size == '24'):
        cols=6
        rows=4
        wells=24
        self.canvas.create_rectangle(15, 180, 515, 480, fill = "red")
        for y in range(0,rows):
            for x in range(0,cols):
                well.append(_create_circle(75+(75*x),220+(70*y),16,fill="white", activefill="cyan"))
                self.canvas.tag_bind(well[count],'<Double-1>',onObjectClick)
                count=count+1
                
    if(size == '96'):
        cols=12
        rows=8
        wells=96        
        self.canvas.create_rectangle(15, 180, 515, 480, fill = "red")
        for y in range(0,rows):
            for x in range(0,cols):
                well.append(_create_circle(60+(37*x),205+(35*y),9,fill="white", activefill="cyan"))
                self.canvas.tag_bind(well[count],'<Double-1>',onObjectClick)
                count=count+1
        

    self.varWells = StringVar(self)
    self.wellChoice = {'6': '6', '24':'24','96':'96'}
    self.varWells.set('What size plate are you using?')
    self.wellOption = OptionMenu(self, self.varWells, *self.wellChoice)
    self.wellOption_w=self.canvas.create_window(100,100,window=self.wellOption)
    self.wellOption.place(x=120,y=131)
    SelectButton=Button(self,text="Select!",command=lambda:select_size(self))
    SelectButton.grid()
    SelectButton.place(x=330,y=133)

        
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
            
            
