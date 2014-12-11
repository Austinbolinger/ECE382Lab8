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

####B Functionality

####A Functionality


####Debuggin Functionality

####Debuggin B Functionality


####Debuggin A Functionality


#### Documentation


