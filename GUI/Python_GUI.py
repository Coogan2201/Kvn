import serial
from tkinter import *
import time
from SrDes import motorbuttons
from SrDes import wellCreator
time.sleep(2)
arduinoData = serial.Serial('com14',9600)

Motor_control_window= Tk()

class PrinterGui(Frame):
    
    def __init__(self, master):
        Frame.__init__(self,master)
        self.grid()
        motorbuttons.create_buttons(self)
        Motor_control_window.title("Automated Cell Culturer")
        wellCreator.create_wells(self,'')
        

    def buttonPressing2(self, event):
        eventCode = int(event.type)        
        ids = self.canvas.find_closest(event.x, event.y)                     #Find out what button is pressed and if pressed or released
        buttonFill = event.widget.itemcget(ids,"fill")
        print(eventCode)
        print(buttonFill)
        if(buttonFill == "white"):
            print("Okay")
  
#  >     clicked_colors = ", ".join(canvas.itemcget(id, "fill") for id in ids)
  
    
    def buttonPressing(self, event):
        eventCode = int(event.type)                             #Find out what button is pressed and if pressed or released
        buttonText = event.widget.cget("text")

    
        if (buttonText=='Go to home'):
            if (eventCode == 4):
                arduinoData.write(bytes("A", "utf-8"))
                print(eventCode)
                print("Homing")
                
        
        if (buttonText=='Change Media'):
            if (eventCode == 4):
                if(self.varWells.get()=='6'):
                    arduinoData.write(bytes("B", "utf-8"))
                    print("Changing Media in a 6 well plate")
                if(self.varWells.get()=='24'):
                    arduinoData.write(bytes("C", "utf-8"))
                    print("Changing Media in a 24 well plate")
                if(self.varWells.get()=='96'):
                    arduinoData.write(bytes("D", "utf-8"))
                    print("Changing Media in a 96 well plate")


        if (buttonText=='Move Left'):
            if (eventCode == 4):
                arduinoData.write(bytes("F", "utf-8"))
                print("Moving Left")
            if (eventCode==5):
                arduinoData.write(bytes("G", "utf-8"))
                print("Stop moving Left")

        if (buttonText=='Move Right'):
            if (eventCode == 4):
                arduinoData.write(bytes("H", "utf-8"))
                print("Moving Right")
            if (eventCode==5):
                arduinoData.write(bytes("I", "utf-8"))
                print("Stop moving Right")

        if (buttonText=='Move Back'):
            if (eventCode == 4):
                arduinoData.write(bytes("J", "utf-8"))
                print("Moving Back")
            if (eventCode==5):
                arduinoData.write(bytes("K", "utf-8"))
                print("Stop moving Back")

        if (buttonText=='Move Forward'):
            if (eventCode == 4):
                arduinoData.write(bytes("L", "utf-8"))
                print("Moving Forward")
            if (eventCode==5):
                arduinoData.write(bytes("M", "utf-8"))
                print("Stop moving Forward")

        if (buttonText=='Move Up'):
            if (eventCode == 4):
                arduinoData.write(bytes("N", "utf-8"))
                print("Moving Up")
            if (eventCode==5):
                arduinoData.write(bytes("O", "utf-8"))
                print("Stop moving Up")

        if (buttonText=='Move Down'):
            if (eventCode == 4):
                arduinoData.write(bytes("P", "utf-8"))
                print("Moving Down")
            if (eventCode==5):
                arduinoData.write(bytes("Q", "utf-8"))
                print("Stop moving Down")
        
app = PrinterGui(Motor_control_window)



Motor_control_window.mainloop()

arduinoData.close()
