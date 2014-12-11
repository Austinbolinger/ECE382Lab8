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


####Initiate Code Ideas

####Psuedo Code
The robot will start at the home spot. The left sensor will only look for a wall closer than 2 inches. The right sensor will be the main sensor. The robot will look for the RIGHT wall at all times. It will keep the right wall within 2 and 3 inches. I will ask it to adjust the right wheel or left wheel accordingly to keep it on the right wall. The robot will move forward until the front sensor senses a wall. When it senses a wall. I will look to see if there is a right wall or not. If there is a right wall and front wall, turn left 90 degrees. If there is no right wall and there is a front wall turn right 90 degrees. Notice how the red line is drawn close to the right wall. This is understanding for door 3. 

![Psuedo Code](https://github.com/Austinbolinger/ECE382Lab8/blob/master/psuedoCode.JPG?raw=true "psuedo Code" )

##Lab

####Functionality
The required functionality for this lab needed to exit through door 1. To do this I spent many a hours on trying to figure out my algorithm and troubleshooting my robots problems.

5 different algo.
sensor issues
cascading 
sensor resistor


####B Functionality
The B functionality asked the robot to go through the maze and exit door two. I could not do this because my front sensor was not working. Without the front sensor, my robot would run into walls. It is near impossible to code something to follow walls if there is going to eventually be a wall in front of it.

####A Functionality
The A functionality asked the robot to go through the maze and exit door 3. I did not even attempt this without a front sensor.

####Debuggin Functionality
https://github.com/Austinbolinger/ECE382Lab8/tree/master/lab7Doesitwork

The first problem identified was sensor readings. I started with a simple if statement. I coded if my middle sensor reading was this hex value, then make the wheels move forward or else stop. I did this with all of the sensors in order to calibrate the sensors one at a time. I decided to originally go with just 3 thresholds, one for each sensor. I soon learned that the sensors changed dramatically when the lighting changed just a little. If the lights were all on or just a few on, if someone walked by or sat down, if the sensors where pointing in a different 

#### Documentation


