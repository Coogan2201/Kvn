from tkinter import *
from SrDes import wellCreator

def select_size(self):
    if(self.varWells.get() == '6'):
        self.des.grid_forget()
        self.des.destroy()
        wellCreator.create_wells(self,'6')
    if(self.varWells.get() == '24'):
        self.des.grid_forget()
        self.des.destroy()
        wellCreator.create_wells(self,'24')
    if(self.varWells.get() == '96'):
        self.des.grid_forget()
        self.des.destroy()
        wellCreator.create_wells(self,'96')
        
def create_buttons(self):

    self.SelectButton=Button(self,text="Select!",command=lambda:select_size(self)).grid(column = 1, row = 4)
    
    self.GoButton=Button(self,text="Move!")
    self.GoButton.grid(column=1,row=10)
    self.GoButton.bind('<Button-1>',self.buttonPressing)

    self.HomeButton=Button(self,text="Go to home")
    self.HomeButton.grid(column=5,row=3)   
    self.HomeButton.bind('<Button-1>', self.buttonPressing)

    self.MediaButton=Button(self,text="Change Media")
    self.MediaButton.grid(column=5,row=5)   
    self.MediaButton.bind('<Button-1>', self.buttonPressing)

    self.LeftButton=Button(self,text="Move Left")
    self.LeftButton.grid(column=7,row=7)   
    self.LeftButton.bind('<Button-1>', self.buttonPressing)        
    self.LeftButton.bind('<ButtonRelease-1>', self.buttonPressing)

    self.RightButton=Button(self,text="Move Right")
    self.RightButton.grid(column=9,row=7)   
    self.RightButton.bind('<Button-1>', self.buttonPressing)        
    self.RightButton.bind('<ButtonRelease-1>', self.buttonPressing) 
    
    self.BackButton=Button(self,text="Move Back")
    self.BackButton.grid(column=8,row=8)   
    self.BackButton.bind('<Button-1>', self.buttonPressing)        
    self.BackButton.bind('<ButtonRelease-1>', self.buttonPressing) 
    
    self.ForwardButton=Button(self,text="Move Forward")
    self.ForwardButton.grid(column=8,row=6)   
    self.ForwardButton.bind('<Button-1>', self.buttonPressing)        
    self.ForwardButton.bind('<ButtonRelease-1>', self.buttonPressing) 
    
    self.UpButton=Button(self,text="Move Up")
    self.UpButton.grid(column=9,row=6)   
    self.UpButton.bind('<Button-1>', self.buttonPressing)        
    self.UpButton.bind('<ButtonRelease-1>', self.buttonPressing) 
    
    self.DownButton=Button(self,text="Move Down")
    self.DownButton.grid(column=9,row=8)   
    self.DownButton.bind('<Button-1>', self.buttonPressing)        
    self.DownButton.bind('<ButtonRelease-1>', self.buttonPressing)         
    
    self.EtOHButton=Button(self,text="Ethanol Out")
    self.EtOHButton.grid(column=10,row=10)   
    self.EtOHButton.bind('<Button-1>', self.buttonPressing)        
    self.EtOHButton.bind('<ButtonRelease-1>', self.buttonPressing)         
    
    self.WasteButton=Button(self,text="Waste In")
    self.WasteButton.grid(column=10,row=11)   
    self.WasteButton.bind('<Button-1>', self.buttonPressing)        
    self.WasteButton.bind('<ButtonRelease-1>', self.buttonPressing)         
        
        
        
        #Well plate selector
    self.varWells = StringVar(self)
    self.wellChoice = {'6': '6', '24':'24','96':'96'}
    self.wellOption = OptionMenu(self, self.varWells, *self.wellChoice)
    self.varWells.set('What size plate are you using?')
    self.wellOption.grid(column = 1, row =5)
        
    #Protocol
#    self.varProtocol = StringVar(self)
#    self.protocolChoice = {'Aspirate': 'Aspirate','Media': 'Media', 'PBS':'PBS','Trypsin':'Trypsin','EthanolWash':'EthanolWash'}
#    self.protocolOption = OptionMenu(self, self.varProtocol, *self.protocolChoice)
#    self.varProtocol.set('What liquid do you want?')
#    self.protocolOption.grid(column = 3, row =6)
    
