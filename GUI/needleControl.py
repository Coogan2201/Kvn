from tkinter import *


def liquidFrame(self):

    canvasL = Canvas(self, bg='blue',width = 400, height=400)
  #  canvasL.place(x=100, y=150)
    canvasL.grid(row=1,column=1)
    canvasL.place(x=550,y=600)
    
    self.LeftButton=Button(self,text="Move Left")
    self.LeftButton.configure(width=10)
    self.LeftButton_w = canvasL.create_window(50,175,window=self.LeftButton)
    self.LeftButton.bind('<Button-1>', self.buttonPressing)        
    self.LeftButton.bind('<ButtonRelease-1>', self.buttonPressing)
    
    self.RightButton=Button(self,text="Move Right")
    self.RightButton.configure(width=10)
    self.RightButton_w = canvasL.create_window(200,175,window=self.RightButton)
    self.RightButton.bind('<Button-1>', self.buttonPressing)        
    self.RightButton.bind('<ButtonRelease-1>', self.buttonPressing)
    
    self.UpButton=Button(self,text="Move Up")
    self.UpButton.configure(width=10)
    self.UpButton_w = canvasL.create_window(125,140,window=self.UpButton)
    self.UpButton.bind('<Button-1>', self.buttonPressing)        
    self.UpButton.bind('<ButtonRelease-1>', self.buttonPressing)
    
    self.DownButton=Button(self,text="Move Down")
    self.DownButton.configure(width=10)
    self.DownButton_w = canvasL.create_window(125,205,window=self.DownButton)
    self.DownButton.bind('<Button-1>', self.buttonPressing)        
    self.DownButton.bind('<ButtonRelease-1>', self.buttonPressing)
    
    self.BackwardButton=Button(self,text="Move Backward")
    self.BackwardButton.configure(width=12)
    self.BackwardButton_w = canvasL.create_window(300,175,window=self.BackwardButton)
    self.BackwardButton.bind('<Button-1>', self.buttonPressing)        
    self.BackwardButton.bind('<ButtonRelease-1>', self.buttonPressing)
    
    self.ForwardButton=Button(self,text="Move Forward")
    self.ForwardButton.configure(width=12)
    self.ForwardButton_w = canvasL.create_window(300,125,window=self.ForwardButton)
    self.ForwardButton.bind('<Button-1>', self.buttonPressing)        
    self.ForwardButton.bind('<ButtonRelease-1>', self.buttonPressing)
    
    self.HomeNeedleButton=Button(self,text="Home Needle")
    self.HomeNeedleButton.configure(width=12)
    self.HomeNeedleButton_w = canvasL.create_window(300,225,window=self.HomeNeedleButton)
    self.HomeNeedleButton.bind('<Button-1>', self.buttonPressing)        
    self.HomeNeedleButton.bind('<ButtonRelease-1>', self.buttonPressing)