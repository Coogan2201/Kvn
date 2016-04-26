import serial
from tkinter import *
import time

from SrDes import wellCreator
from SrDes import needleControl
from SrDes import liquidFunctions
from SrDes import armControl
time.sleep(2)
arduinoData = ''#serial.Serial('com3',19200)

Motor_control_window= Tk()
class PrinterGui(Frame):
    
    def __init__(self, master):
        Frame.__init__(self,master)
        self.grid()
        master.minsize(width=1000,height=1000)
        button=Button(self,text="")
        button.grid(row=2,column=2)
        button.configure(width=101,height=101)

        Motor_control_window.title("Automated Cell Culturer")
        wellCreator.create_wells(self,'')
        needleControl.liquidFrame(self)
        liquidFunctions.liquid2Frame(self)
        armControl.buttons(self)
    
#######################################################################################
    def buttonPressing(self, event):
        eventCode = int(event.type)                             #Find out what button is pressed and if pressed or released
        buttonText = event.widget.cget("text")

        #Needle Functions
        if (buttonText=='Home Needle'):
            if (eventCode == 4):
                arduinoData.write(bytes("A", "utf-8"))
                arduinoData.write(bytes("6", "utf-8"))
        if (buttonText=='Move Left'):
            if (eventCode == 4):
                arduinoData.write(bytes("E", "utf-8"))
            if (eventCode == 5):
                arduinoData.write(bytes("6", "utf-8"))
        if (buttonText=='Move Right'):
            if (eventCode == 4):
                arduinoData.write(bytes("F", "utf-8"))
            if (eventCode == 5):
                arduinoData.write(bytes("6", "utf-8"))
        if (buttonText=='Move Backward'):
            if (eventCode == 4):
                arduinoData.write(bytes("G", "utf-8"))
            if (eventCode == 5):
                arduinoData.write(bytes("6", "utf-8"))
        if (buttonText=='Move Forward'):
            if (eventCode == 4):
                arduinoData.write(bytes("H", "utf-8"))
            if (eventCode == 5):
                arduinoData.write(bytes("6", "utf-8"))
        if (buttonText=='Move Up'):
            if (eventCode == 4):
                arduinoData.write(bytes("I", "utf-8"))
            if (eventCode == 5):
                arduinoData.write(bytes("6", "utf-8"))
        if (buttonText=='Move Down'):
            if (eventCode == 4):
                arduinoData.write(bytes("J", "utf-8"))
            if (eventCode==5):
                arduinoData.write(bytes("6", "utf-8"))
        if (buttonText=='Move!'):
            if (eventCode == 4):
                print(wellCreator.activeWell)

################################################################################################
                        
        #Arm Functions    
        if (buttonText=='Base Counter-Clockwise'):
            if (eventCode == 4):
                arduinoData.write(bytes("X", "utf-8"))
            if (eventCode==5):
                arduinoData.write(bytes("6", "utf-8"))       
        if (buttonText=='Base Clockwise'):
            if (eventCode == 4):
                arduinoData.write(bytes("Y", "utf-8"))
            if (eventCode==5):
                arduinoData.write(bytes("6", "utf-8"))
        if (buttonText=='Joint Clockwise'):
            if (eventCode == 4):
                arduinoData.write(bytes("x", "utf-8"))
            if (eventCode==5):
                arduinoData.write(bytes("6", "utf-8"))
        if (buttonText=='Joint Counter-Clockwise'):
            if (eventCode == 4):
                arduinoData.write(bytes("y", "utf-8"))
            if (eventCode==5):
                arduinoData.write(bytes("6", "utf-8"))
        if (buttonText=='Arm Backward'):
            if (eventCode == 4):
                arduinoData.write(bytes("d", "utf-8"))
            if (eventCode==5):
                arduinoData.write(bytes("6", "utf-8"))
        if (buttonText=='Arm Forward'):
            if (eventCode == 4):
                arduinoData.write(bytes("c", "utf-8"))
            if (eventCode==5):
                arduinoData.write(bytes("6", "utf-8"))
        if (buttonText=='Arm Up'):
            if (eventCode == 4):
                arduinoData.write(bytes("e", "utf-8"))
            if (eventCode==5):
                arduinoData.write(bytes("6", "utf-8"))
        if (buttonText=='Arm Down'):
            if (eventCode == 4):
                arduinoData.write(bytes("f", "utf-8"))
            if (eventCode==5):
                arduinoData.write(bytes("6", "utf-8"))
        if (buttonText=='Gripper Open'):
            if (eventCode == 4):
                arduinoData.write(bytes("a", "utf-8"))
                arduinoData.write(bytes("6", "utf-8"))
        if (buttonText=='Gripper Close'):
            if (eventCode == 4):
                arduinoData.write(bytes("b", "utf-8"))
                arduinoData.write(bytes("6", "utf-8"))
        if (buttonText=='Wrist Clockwise'):
            if (eventCode == 4):
                arduinoData.write(bytes("g", "utf-8"))
                arduinoData.write(bytes("6", "utf-8"))
        if (buttonText=='Wrist Counter-Clockwise'):
            if (eventCode == 4):
                arduinoData.write(bytes("h", "utf-8"))
                arduinoData.write(bytes("6", "utf-8"))
        if (buttonText=='Home Arm'):
            if (eventCode == 4):
                arduinoData.write(bytes("V", "utf-8"))
                arduinoData.write(bytes("6", "utf-8"))
################################################################################
                
        if (buttonText=='Waste'):
            if (eventCode == 4):
                arduinoData.write(bytes("1", "utf-8"))
            if (eventCode==5):
                arduinoData.write(bytes("6", "utf-8"))
        if (buttonText=='Trypsin'):
            if (eventCode == 4):
                arduinoData.write(bytes("2", "utf-8"))
            if (eventCode==5):
                arduinoData.write(bytes("6", "utf-8"))
        if (buttonText=='Media'):
            if (eventCode == 4):
                arduinoData.write(bytes("3", "utf-8"))
            if (eventCode==5):
                arduinoData.write(bytes("6", "utf-8"))
        if (buttonText=='PBS'):
            if (eventCode == 4):
                arduinoData.write(bytes("4", "utf-8"))
            if (eventCode==5):
                arduinoData.write(bytes("6", "utf-8"))
        if (buttonText=='Ethanol'):
            if (eventCode == 4):
                arduinoData.write(bytes("5", "utf-8"))
            if (eventCode==5):
                arduinoData.write(bytes("6", "utf-8"))
        if (buttonText=='Change Media'):
            if (eventCode == 4):
                arduinoData.write(bytes("C", "utf-8"))
            if (eventCode==5):
                arduinoData.write(bytes("6", "utf-8"))
        if (buttonText=='Passage cells'):
            if (eventCode == 4):
                arduinoData.write(bytes("K", "utf-8"))
            if (eventCode==5):
                arduinoData.write(bytes("6", "utf-8"))
#######################################################################################

app = PrinterGui(Motor_control_window)

Motor_control_window.mainloop()

#arduinoData.close()
