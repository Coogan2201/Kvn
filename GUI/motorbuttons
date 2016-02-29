from tkinter import *

def create_buttons(self):
    self.varMotors = StringVar(self)
    self.motorsChoice = {'X': 'X','Y': 'Y', 'Z':'Z','EX1':'EX1','EX2':'EX2'}
    self.motorOption = OptionMenu(self, self.varMotors, *self.motorsChoice)
    self.varMotors.set('What motors do you want to move?')
    self.motorOption.grid(column = 0, row =0)

    self.varDirection = StringVar(self)
    self.directionChoice = {'HIGH':"1", "LOW":"0"}
    self.directionOption = OptionMenu(self,self.varDirection,*self.directionChoice)
    self.varDirection.set("What direction do you want to move?")
    self.directionOption.grid(column=1,row=0)
     
    self.distance = Label(self,text="How far: (cm)")
    self.distance.grid(row=0, column = 2)
    self.distance_ = Entry(self)
    self.distance_.grid(row = 0, column = 3, sticky = W)         
     
     

    self.ForwardButton=Button(self,text="Go to home")
    self.ForwardButton.grid(column=5,row=3)   
    self.ForwardButton.bind('<Button-1>', self.buttonPressing)
    
    self.ForwardButton=Button(self,text="6 well plate")
    self.ForwardButton.grid(column=4,row=4)   
    self.ForwardButton.bind('<Button-1>', self.buttonPressing)
    
    #Well plate selector
    self.varWells = StringVar(self)
    self.wellChoice = {'6': '6','12': '12', '24':'24','96':'96'}
    self.wellOption = OptionMenu(self, self.varWells, *self.wellChoice)
    self.varWells.set('What size plate are you using?')
    self.wellOption.grid(column = 3, row =5)
    
    #Protocol
    self.varProtocol = StringVar(self)
    self.protocolChoice = {'Aspirate': 'Aspirate','Media': 'Media', 'PBS':'PBS','Trypsin':'Trypsin','EthanolWash':'EthanolWash'}
    self.protocolOption = OptionMenu(self, self.varProtocol, *self.protocolChoice)
    self.varProtocol.set('What liquid do you want?')
    self.protocolOption.grid(column = 3, row =6)
