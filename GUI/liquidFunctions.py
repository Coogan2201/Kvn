from tkinter import *


def liquid2Frame(self):

    canvasL = Canvas(self, bg='blue',width = 400, height=550)
    canvasL.grid(column=1,row=0)
    canvasL.place(x=550,y=10)

    self.MediaButton=Button(self,text="Media")
    self.MediaButton.configure(width=10)
    self.MediaButton_w = canvasL.create_window(150,150,window=self.MediaButton)
    self.MediaButton.bind('<Button-1>', self.buttonPressing)        
    self.MediaButton.bind('<ButtonRelease-1>', self.buttonPressing)
    
    self.PassageButton=Button(self,text="Trypsin")
    self.PassageButton.configure(width=10)
    self.PassageButton_w = canvasL.create_window(150,200,window=self.PassageButton)
    self.PassageButton.bind('<Button-1>', self.buttonPressing)        
    self.PassageButton.bind('<ButtonRelease-1>', self.buttonPressing)
    
    self.AspirateButton=Button(self,text="Waste")
    self.AspirateButton.configure(width=10)
    self.AspirateButton_w = canvasL.create_window(100,250,window=self.AspirateButton)
    self.AspirateButton.bind('<Button-1>', self.buttonPressing)        
    self.AspirateButton.bind('<ButtonRelease-1>', self.buttonPressing)
    
    self.DepositButton=Button(self,text="PBS")
    self.DepositButton.configure(width=10)
    self.DepositButton_w = canvasL.create_window(200,250,window=self.DepositButton)
    self.DepositButton.bind('<Button-1>', self.buttonPressing)        
    self.DepositButton.bind('<ButtonRelease-1>', self.buttonPressing)
    
    self.WashButton=Button(self,text="Ethanol")
    self.WashButton.configure(width=10)
    self.WashButton_w = canvasL.create_window(150,300,window=self.WashButton)
    self.WashButton.bind('<Button-1>', self.buttonPressing)        
    self.WashButton.bind('<ButtonRelease-1>', self.buttonPressing)
    
    
#    self.EtOHButton=Button(self,text="Ethanol Out")
#    self.EtOHButton.grid(column=10,row=10)   
#    self.EtOHButton.bind('<Button-1>', self.buttonPressing)        
#    self.EtOHButton.bind('<ButtonRelease-1>', self.buttonPressing)         
    
#    self.WasteButton=Button(self,text="Waste In")
#    self.WasteButton.grid(column=10,row=11)   
#    self.WasteButton.bind('<Button-1>', self.buttonPressing)        
#    self.WasteButton.bind('<ButtonRelease-1>', self.buttonPressing)   