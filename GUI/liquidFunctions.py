from tkinter import *


def liquid2Frame(self):

    canvasL = Canvas(self, bg='firebrick',width = 400, height=500)
    canvasL.grid(column=1,row=0)
    canvasL.place(x=550,y=10)
    w = Label(self, text="Liquid functions")
    w.grid(column=1, row=0)
    w.place(x=700,y=75)

    self.MediaButton=Button(self,text="Media")
    self.MediaButton.configure(width=10)
    self.MediaButton_w = canvasL.create_window(200,150,window=self.MediaButton)
    self.MediaButton.bind('<Button-1>', self.buttonPressing)        
    self.MediaButton.bind('<ButtonRelease-1>', self.buttonPressing)
    
    self.PassageButton=Button(self,text="Trypsin")
    self.PassageButton.configure(width=10)
    self.PassageButton_w = canvasL.create_window(200,200,window=self.PassageButton)
    self.PassageButton.bind('<Button-1>', self.buttonPressing)        
    self.PassageButton.bind('<ButtonRelease-1>', self.buttonPressing)
    
    self.AspirateButton=Button(self,text="Waste")
    self.AspirateButton.configure(width=10)
    self.AspirateButton_w = canvasL.create_window(150,250,window=self.AspirateButton)
    self.AspirateButton.bind('<Button-1>', self.buttonPressing)        
    self.AspirateButton.bind('<ButtonRelease-1>', self.buttonPressing)
    
    self.DepositButton=Button(self,text="PBS")
    self.DepositButton.configure(width=10)
    self.DepositButton_w = canvasL.create_window(250,250,window=self.DepositButton)
    self.DepositButton.bind('<Button-1>', self.buttonPressing)        
    self.DepositButton.bind('<ButtonRelease-1>', self.buttonPressing)
    
    self.WashButton=Button(self,text="Ethanol")
    self.WashButton.configure(width=10)
    self.WashButton_w = canvasL.create_window(200,300,window=self.WashButton)
    self.WashButton.bind('<Button-1>', self.buttonPressing)        
    self.WashButton.bind('<ButtonRelease-1>', self.buttonPressing)
    
    self.ChangeMediaButton=Button(self,text="Change Media")
    self.ChangeMediaButton.configure(width=20)
    self.ChangeMediaButton_w = canvasL.create_window(200,350,window=self.ChangeMediaButton)
    self.ChangeMediaButton.bind('<Button-1>', self.buttonPressing)        
    self.ChangeMediaButton.bind('<ButtonRelease-1>', self.buttonPressing)
    
    self.PassageCellsButton=Button(self,text="Passage cells")
    self.PassageCellsButton.configure(width=20)
    self.PassageCellsButton_w = canvasL.create_window(200,400,window=self.PassageCellsButton)
    self.PassageCellsButton.bind('<Button-1>', self.buttonPressing)        
    self.PassageCellsButton.bind('<ButtonRelease-1>', self.buttonPressing)
