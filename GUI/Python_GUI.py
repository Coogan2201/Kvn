import serial
from tkinter import *
import time
import motorbuttons
import createWells
time.sleep(2)
#arduinoData = serial.Serial('com3',9600)

Motor_control_window= Tk()

class PrinterGui(Frame):
    
    def __init__(self, master):
        Frame.__init__(self,master)
        self.grid()
        motorbuttons.create_buttons(self)
        self.GoButton=Button(self,text="Move!",command=lambda:motor_move(self)).grid(column = 1, row = 1)
        Motor_control_window.title("Automated Cell Culturer")
        
        createWells.create_wells(self)
        
        
    def buttonPressing(self, event):
        eventCode = int(event.type)                             #Find out what button is pressed and if pressed or released
        buttonText = event.widget.cget("text")

    
        if (buttonText=='Go to home'):
            if (eventCode == 4):
                arduinoData.write(bytes("Home Axes", "utf-8"))
                print("Homing")
                
        if (buttonText=='6 well plate'):
            if (eventCode == 4):
                arduinoData.write(bytes("6 Well plate", "utf-8"))
                print("6 well plate")
  
app = PrinterGui(Motor_control_window)

def motor_move(self):
    a = [self.varMotors.get(),self.varDirection.get(),self.distance_.get()]
    byteString = bytes(a[0] + ": " +  a[1] + ": " + a[2], "utf-8")
    arduinoData.write(byteString)
    print(byteString)

Motor_control_window.mainloop()

arduinoData.close()
