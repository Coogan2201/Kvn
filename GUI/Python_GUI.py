import serial
from tkinter import *
import time
from SrDes import motorbuttons
from SrDes import wellCreator
time.sleep(2)
#arduinoData = serial.Serial('com3',9600)

Motor_control_window= Tk()

class PrinterGui(Frame):
    
    def __init__(self, master):
        Frame.__init__(self,master)
        self.grid()
        motorbuttons.create_buttons(self)
        Motor_control_window.title("Automated Cell Culturer")
        wellCreator.create_wells(self,'')

            
    def moveIndividual(self, event):
        print("Let's do this.")
                
        ids = self.canvas.find_closest(event.x, event.y)                     #Find out what button is pressed and if pressed or released
        buttonFill = event.widget.itemcget(ids,"fill")
        print(buttonFill)
    
    def buttonPressing(self, event):
        eventCode = int(event.type)                             #Find out what button is pressed and if pressed or released
        buttonText = event.widget.cget("text")

        if (buttonText=='Go to home'):
            if (eventCode == 4):
 #               arduinoData.write(bytes("A", "utf-8"))
                print(eventCode)
                print("Homing")
        
        if (buttonText=='Move!'):
            for x in range(0,6):
                if self.wellFinder==(x,):
                    if(self.buttonFill2 =="green"):
                        print("GREEN")
  #                      arduinoData.write(bytes("F","utf-8"))
                        print(x)
                    if(self.buttonFill2 =="white"):
                        print("WHITE")
                        print(x)


    
        
        
        
        if (buttonText=='Change Media'):
            if (eventCode == 4):
                if(self.varWells.get()=='6'):
   #                 arduinoData.write(bytes("B", "utf-8"))
                    print("Changing Media in a 6 well plate")
                if(self.varWells.get()=='24'):
    #                arduinoData.write(bytes("C", "utf-8"))
                    print("Changing Media in a 24 well plate")
                if(self.varWells.get()=='96'):
     #               arduinoData.write(bytes("D", "utf-8"))
                    print("Changing Media in a 96 well plate")

        if (buttonText=='Move Left'):
            if (eventCode == 4):
     #           arduinoData.write(bytes("F", "utf-8"))
                print("Moving Left")
            if (eventCode==5):
      #          arduinoData.write(bytes("G", "utf-8"))
                print("Stop moving Left")
                
        if (buttonText=='Ethanol Out'):
            if (eventCode == 4):
       #         arduinoData.write(bytes("R", "utf-8"))
                print("Eject Ethanol Left")
            if (eventCode==5):
        #        arduinoData.write(bytes("T", "utf-8"))
                print("Stop moving Left")
                
        if (buttonText=='Waste In'):
            if (eventCode == 4):
         #       arduinoData.write(bytes("S", "utf-8"))
                print("Removing Waste")
            if (eventCode==5):
          #      arduinoData.write(bytes("U", "utf-8"))
                print("Stop moving Left")                

        if (buttonText=='Move Right'):
            if (eventCode == 4):
 #               arduinoData.write(bytes("H", "utf-8"))
                print("Moving Right")
            if (eventCode==5):
  #              arduinoData.write(bytes("I", "utf-8"))
                print("Stop moving Right")

        if (buttonText=='Move Back'):
            if (eventCode == 4):
   #             arduinoData.write(bytes("J", "utf-8"))
                print("Moving Back")
            if (eventCode==5):
    #            arduinoData.write(bytes("K", "utf-8"))
                print("Stop moving Back")

        if (buttonText=='Move Forward'):
            if (eventCode == 4):
#                arduinoData.write(bytes("L", "utf-8"))
                print("Moving Forward")
            if (eventCode==5):
 #               arduinoData.write(bytes("M", "utf-8"))
                print("Stop moving Forward")

        if (buttonText=='Move Up'):
            if (eventCode == 4):
  #              arduinoData.write(bytes("N", "utf-8"))
                print("Moving Up")
            if (eventCode==5):
   #             arduinoData.write(bytes("O", "utf-8"))
                print("Stop moving Up")

        if (buttonText=='Move Down'):
            if (eventCode == 4):
    #            arduinoData.write(bytes("P", "utf-8"))
                print("Moving Down")
            if (eventCode==5):
     #           arduinoData.write(bytes("Q", "utf-8"))
                print("Stop moving Down")
        
app = PrinterGui(Motor_control_window)

Motor_control_window.mainloop()

arduinoData.close()
