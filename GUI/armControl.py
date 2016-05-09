from tkinter import *


def buttons(self):

    canvasL = Canvas(self, bg='firebrick',width = 510, height=350,bd=10,highlightbackground='white')
    canvasL.grid(column=0,row=1)
    canvasL.place(y=530)

    w = Label(self, text="Arm functions", font=(16))
    w.grid(column=0, row=1)
    w.place(x=200,y=550)
    
    
    self.LeftButton=Button(self,text="Arm Forward")
    self.LeftButton.configure(width=12)
    self.LeftButton_w = canvasL.create_window(75,195,window=self.LeftButton)
    self.LeftButton.bind('<Button-1>', self.buttonPressing)        
    self.LeftButton.bind('<ButtonRelease-1>', self.buttonPressing)
    
    self.RightButton=Button(self,text="Arm Backward")
    self.RightButton.configure(width=12)
    self.RightButton_w = canvasL.create_window(275,195,window=self.RightButton)
    self.RightButton.bind('<Button-1>', self.buttonPressing)        
    self.RightButton.bind('<ButtonRelease-1>', self.buttonPressing)
    
    self.UpButton=Button(self,text="Arm Up")
    self.UpButton.configure(width=12)
    self.UpButton_w = canvasL.create_window(175,170,window=self.UpButton)
    self.UpButton.bind('<Button-1>', self.buttonPressing)        
    self.UpButton.bind('<ButtonRelease-1>', self.buttonPressing)
    
    self.DownButton=Button(self,text="Arm Down")
    self.DownButton.configure(width=12)
    self.DownButton_w = canvasL.create_window(175,220,window=self.DownButton)
    self.DownButton.bind('<Button-1>', self.buttonPressing)        
    self.DownButton.bind('<ButtonRelease-1>', self.buttonPressing)
    
    self.JointCWButton=Button(self,text="Joint Clockwise")
    self.JointCWButton.configure(width=20)
    self.JointCWButton_w = canvasL.create_window(450,120,window=self.JointCWButton)
    self.JointCWButton.bind('<Button-1>', self.buttonPressing)        
    self.JointCWButton.bind('<ButtonRelease-1>', self.buttonPressing)    
    
    self.JointCCWButton=Button(self,text="Joint Counter-Clockwise")
    self.JointCCWButton.configure(width=20)
    self.JointCCWButton_w = canvasL.create_window(450,170,window=self.JointCCWButton)
    self.JointCCWButton.bind('<Button-1>', self.buttonPressing)        
    self.JointCCWButton.bind('<ButtonRelease-1>', self.buttonPressing)

    self.BaseCWButton=Button(self,text="Base Clockwise")
    self.BaseCWButton.configure(width=20)
    self.BaseCWButton_w = canvasL.create_window(450,220,window=self.BaseCWButton)
    self.BaseCWButton.bind('<Button-1>', self.buttonPressing)        
    self.BaseCWButton.bind('<ButtonRelease-1>', self.buttonPressing)    
    
    self.BaseCCWButton=Button(self,text="Base Counter-Clockwise")
    self.BaseCCWButton.configure(width=20)
    self.BaseCCWButton_w = canvasL.create_window(450,270,window=self.BaseCCWButton)
    self.BaseCCWButton.bind('<Button-1>', self.buttonPressing)        
    self.BaseCCWButton.bind('<ButtonRelease-1>', self.buttonPressing)    
    
    self.HomeArmButton=Button(self,text="Home Arm")
    self.HomeArmButton.configure(width=12)
    self.HomeArmButton_w = canvasL.create_window(175,320,window=self.HomeArmButton)
    self.HomeArmButton.bind('<Button-1>', self.buttonPressing)        
    self.HomeArmButton.bind('<ButtonRelease-1>', self.buttonPressing)
    
    self.HomeArmButton=Button(self,text="Gripper Open")
    self.HomeArmButton.configure(width=12)
    self.HomeArmButton_w = canvasL.create_window(75,120,window=self.HomeArmButton)
    self.HomeArmButton.bind('<Button-1>', self.buttonPressing)        
    self.HomeArmButton.bind('<ButtonRelease-1>', self.buttonPressing)
    
    self.HomeArmButton=Button(self,text="Gripper Close")
    self.HomeArmButton.configure(width=12)
    self.HomeArmButton_w = canvasL.create_window(275,120,window=self.HomeArmButton)
    self.HomeArmButton.bind('<Button-1>', self.buttonPressing)        
    self.HomeArmButton.bind('<ButtonRelease-1>', self.buttonPressing)
    
    self.HomeArmButton=Button(self,text="Wrist Clockwise")
    self.HomeArmButton.configure(width=20)
    self.HomeArmButton_w = canvasL.create_window(80,270,window=self.HomeArmButton)
    self.HomeArmButton.bind('<Button-1>', self.buttonPressing)        
    self.HomeArmButton.bind('<ButtonRelease-1>', self.buttonPressing)
    
    self.HomeArmButton=Button(self,text="Wrist Counter-Clockwise")
    self.HomeArmButton.configure(width=20)
    self.HomeArmButton_w = canvasL.create_window(280,270,window=self.HomeArmButton)
    self.HomeArmButton.bind('<Button-1>', self.buttonPressing)        
    self.HomeArmButton.bind('<ButtonRelease-1>', self.buttonPressing)    
    
