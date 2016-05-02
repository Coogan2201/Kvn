# Kvn
Senior Design Project

Automated Cell Culturing system based off a Folger Tech RepRap 2020 Prusa i3
Software/Microcontrollers
 
2 x Arduino Mega 2560
2 x RAMPS 1.4
Master Arduino (Arm):
Components:
2 x Hitec RCD 31430S HS-430BH Deluxe High Voltage Ball Bearing Servo
4 x A4988 Stepstick Stepper Motor Driver Module + Heat Sinks
5 x NEMA 17 motors (59Ncm holding torque)
4 x Mechanical endstops
Code description:
Serial communication:
●	A serial communication line was open with a baud rate of 19200
●	Incoming communication was read as a single byte and stored in a variable incomingByte
●	The primary source of serial communication is sent to the Master Arduino through the graphic user interface

Motor control:
●	All motor step pins, direction pins, and enable pins were defined in a header file “pins.h”
●	All pins were set to a mode of OUTPUT
●	The enable pins were were set to low to place them in an idle state, only to be turned high prior to the motor being utilized, afterwards placed in a low state once again (in order to prevent the motors from overheating)
●	A motor control function was created with three inputs
○	1st input, motor, as a byte (‘X’, ’J’, ‘Z’, ‘B’) indicates which motor the user wants to control
○	2nd input, direction, as a byte indicates which direction (‘1’ or ‘0’)
○	3rd input, distance, as a float determines how many steps the motor will take
●	2 additional functions were created:
○	armHome: The Z-axis moves up until it hits the Z end stop, then moves down. Next the Y-axis moves all the way to the back of the system where it hits the corresponding endstop. It then moves towards the center so the base and joint end stops can be hit simultaneously.
○	movePlate: Starting from the home position the base and joints will swing counterclockwise as the plate moves forward in the Y direction. Afterwards the gripper will open and the Z axis will move down above the well plate. The gripper will then close on the well plate, move up in the Z axis, to the back in the Y direction. As this is occurring the plate from the liquid deposition system will move to the front of the system. The Base and Joint arms will again swing out to make the well plate straight, the Y and the Z axis will then move to bring the well plate to the liquid deposition plate. After the well plate is lowered, the arm moves away and returns to its home position.

Mechanical endstops:
●	4 end stops were positioned to record the location of the Base, Joint, Y-axis, and Z-axis motors
●	The status of these endstops was read with a digitalRead function
○	When the endstop was triggered a pulse of a 1 or 0 was sent to the microcontroller to determine where the arm components were in 3 dimensions.

Servo:
●	The <Servo.h> library was imported
●	2 servo objects were created. One for the gripper and one for the wrist servos
●	Using the servo.write function an angle value (0-180) was sent to the servo to control their positions

I2C Master:
●	Call the <wire.h> library
●	Start running the wire.begin function
●	Begin transmitting to slave arduino on Wire 9 (The same wire number must be the same on both Slave and Master)
●	Each byte received from the serial port on Master Arduino is forwarded to the Slave Arduino using the wire.write function.
○	The GUI sends a byte to the Master. The Master receives that byte over the serial port, forwards it to the Slave on the wire port. 
Slave Arduino (Liquid deposition):
Components:
3 x A4988 Stepstick Stepper Motor Driver Module + Heat Sink
3 x NEMA 17 2.6kg/cm
1 x NEMA 17 4.8kg/cm
3 x Mechanical endstops
5 x Peristaltic pumps from Adafruit
1 x Flat-tipped needle
5 x FQP30N06L N Channel Mosfet

Code description:
I2C Slave:
●	Call the <wire.h> library
●	Start running the wire.begin function on the corresponding wire from the Master Arduino
●	Read values as a byte from the Master Adruino using the wire.read function
●	These bytes will then be inputted into a switch statement

Peristaltic pumps:
●	All pumps were defined in “pins.h” on a pin that was able to output a pulse width modulation
●	A function, Pump, was created that takes in 4 inputs:
○	1st input indicates what plate size the user is working with (6,24,96)
○	2nd input indicates what pump is to be controlled (Ethanol, Media, etc)
○	3rd input indicates the speed at which the motor is running)
○	4th input indicates the duration of the pump running
●	Several manual functions were created that allow the user to run any pump for a set period of time
●	4 pumps had their polarity set in the circuit to allow them to take input from a reservoir and flow it through the manifold out of the needle. 1 pump was set so that liquid could be sucked through the needle and into its corresponding reservoir.

Motor control:
●	All motor step pins, direction pins, and enable pins were defined in a header file “pins.h”
●	All pins were set to a mode of OUTPUT
●	The enable pins were were set to low to place them in an idle state, only to be turned high prior to the motor being utilized, afterwards to placed in a low state once again (preventing the motors from overheating)
●	A motor control function was created with three inputs
○	1st input as a byte (‘X’, ’Y’, ‘Z’) indicates which motor the user wants to control [motor]
○	2nd input as a byte indicates which direction (‘1’ or ‘0’) [direction]
○	3rd input as a flight determines how many steps the motor will take [distance]
●	4 additional functions were created:
○	home: The X motor which controls the needle moves to the right until it hits the endstop, the plate moves to the back until it hits its endstop, the Z carriage moves down until it hits the final endstop then moves up so the needle can clear the well plates
○	changeMedia & cellPassage: Both functions take an input of which well plate size is being used. This value determines the geometric positions of the individual wells, the appropriate time for the pumps to be turned on, and the duration of the motors. Each function corresponds to a protocol described in the Liquid Deposition Fabrication and Assembly section.
○	relMover: takes 2 inputs corresponding to a 2D grid of X and Y positions. This function allows the motors to record it’s current location and move to a desired location.
Graphic User Interface
The GUI was coded in Python 3.x with three external libraries for communication with the Arduinos and to create the interface. serial.py and time.py were required to open a serial communication over USB to the Master Arduino. tkinter.py was used to create the graphics.
First a tkinter object was created and this was passed into a class PrinterGUI.
4 Cavas’ were created in the frame, each belonging to their own class:
●	wellCreator: The northwest quadrant of the GUI includes a drop down menu and a selection button which allows the user to select the size of the well plate that is being used. Initialization of the canvas creates a red rectangle which is populated with wells that correspond to the item in the drop down menu that the user selected. Each of the wells are interactive, regardless of the plate well size.
○	create_wells: takes an input corresponding to the size of the well plate the user is interested in. The size of the well plate determines the number and positioning of the rows and columns and generates a corresponding number of circles on the rectangle (to simulate a well plate in the GUI).
○	onObjectClick: takes an input corresponding to the location of the wells the user has clicked. If the well is in it’s original configuration (not being clicked) it will turn cyan when hovered over, and green when double-clicked. These values are stored in an array which can be called upon in the future so that the system can move to these specific wells.
●	needleControl: The configuration of the liquid deposition subsystems enable 6 directions, up, down, left, right, forward, and backward. Therefore 6 buttons were created to enable this movement. When these buttons are clicked the motors move in the corresponding direction until the button is released. An additional button was created to Home the three motors by sending a byte to the Slave Arduino (through the Master Arduino). The Move! serves to take the array created by selecting the wells in the wellCreator class and move the motors to the corresponding locations. This button is not currently functional in this iteration.
●	armControl: As with the needleControl, this class enables independent control of each arm motor, along with the 2 servos, by sending corresponding bytes to the Master Arduino.
●	liquidFunctions: The system includes 5 peristaltic pumps, each having their own liquid reservoir. The five liquids include Trypsin, PBS, Ethanol, Cell media, and Waste. Each of these five pumps are controlled by a button on the GUI. The buttons are labeled as to what pumps they control and when the button is clicked it sends a byte to the Master Arduino (releasing the button sends a byte to end the function). Along with the five manual pump control buttons, two other buttons were created to send bytes that initiate the Change Media and Passage Cells functions.
Power:
Source: 
12V, 30amp
Drains:
9 x NEMA 17 @ 1.68A = 15A
5 x peristaltic pumps @ .3A = 1.5A
2 x HS-311 Servos @ .16A = .32A

If the system were to ever run at it’s maximum load it would consume 16.8 amps of current which is 56% of what the power source can supply. Realistically no more than two motors from each system will be running at any given time, so our max current draw is 6.72 amps (22%). The reason this power supply was chosen was to give us plenty of room for safety reason so that we never exceed a safe amount of current consumption. Secondly, our system is extremely modular. We began with a Folgertech 2020 Prusa i3 3D printer, and expanded upon that to include pumps, and additional stepper motors, and servos, with each addition requiring more current. If future groups expand upon this design, power consumption should not be an issue.
