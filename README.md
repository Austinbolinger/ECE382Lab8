ECE382Lab8
==========
Austin Bolinger

Dr. York

ECE 382

05 Dec 14


Description: Lab 8 is to make the robot navigate the maze. I know how to operate the sensors. Now I need to apply motor functions to what the sensor is reading.

Objective: During this lab, I will combine the previous laboratory assignments and program my robot to autonomously navigate through a maze. On the last day of the lab, each section will hold a competition to see who can solve the maze the fastest. The fastest time in ECE 382 will have their name engraved on a plaque in the CSD lab. Believe it or not, the main goal of this lab is for me to have some fun with computer engineering!

##Prelab

**Hardware Setup**
This is what the MSP430 looks like in picture form.

![MSP430]( https://github.com/Austinbolinger/ECE382Lab7/blob/master/MSP430.JPG?raw=true "MSP430" )

The pins I chose are important. As you can see below, they line up with A3, A4, & A5 which will be used in the coding.

![MSP430 diagram]( https://github.com/Austinbolinger/ECE382Lab7/blob/master/MSP430diagram.JPG?raw=true "MSP430 diagram" )

**Maze**

![Maze]( https://github.com/Austinbolinger/ECE382Lab8/blob/master/maze.JPG?raw=true "maze" )

####Psuedo Code
The robot will start at the home spot. The left sensor will only look for a wall closer than 2 inches. The right sensor will be the main sensor. The robot will look for 
