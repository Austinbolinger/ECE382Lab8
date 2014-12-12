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


####B Functionality
The B functionality asked the robot to go through the maze and exit door two. I could not do this because my front sensor was not working. Without the front sensor, my robot would run into walls. It is near impossible to code something to follow walls if there is going to eventually be a wall in front of it.

####A Functionality
The A functionality asked the robot to go through the maze and exit door 3. I did not even attempt this without a front sensor.

####Debuggin Functionality
https://github.com/Austinbolinger/ECE382Lab8/tree/master/lab7Doesitwork

The first problem identified was sensor readings. I started with a simple if statement. I coded if my middle sensor reading was this hex value, then make the wheels move forward or else stop. I did this with all of the sensors in order to calibrate the sensors one at a time. I decided to originally go with just 3 thresholds, one for each sensor. I soon learned that the sensors changed dramatically when the lighting changed just a little. If the lights were all on or just a few on, if someone walked by or sat down, if the sensors where pointing in a different direction the sensors gave different results. After coming to accept that the sensors were not going to provide reliable results, I tried many different algorithms. I first started with go forward unless... I could not get that to work well. I tried moving my code from my libraries to the main code. But the results were the same, obviously. I then was suggested to visit Dr. Coulston's website and take a look at his code idea for sampling. I added that to my code. I am still not sure if that helped or not. But, it did not hurt so I kept it. After still more problems I asked around for ideas with algorithms. I tried wall following for both walls to little success. I also tried adjusting the PWM. That seemed successful at first but then it got too complicated to operate with finicky sensors. I tried many different things like making the default always look for a wall by turning constantly before moving forward and I tried to stay within a range from the wall. Nothing seemed to work. Then I asked around again to see if anyone had similar issues. Dr. Coulston asked if I was giving it too many cases at once. What this meant is that I was not using case statements and not cascading the if statements. That really seemed to be a big help. After I changed my code to cascading, I attacked the problem all over again. I tried wall following and all those options again. I still could not get them to work. On top of that, my robot kept giving me troubles. At one point I could not get my right sensor to work. After many attempts to find the problem, i decided on that I had burnt a pin on the MSP430. After I found a pin that worked, I ran into my middle sensor not responding. I immediately plugged in the VMM and all of a sudden it started to work. So I first thought oh my sensor is not grounded right, but all my connections checked out and the other sensors still worked. Than I thought about the resistance load on the VMM. I did not pursue the idea until Dr. York suggested the same thing. So my middle sensor only works with a 10M ohm resistor plugged in to it. However, I was still having problems finding a solution to the maze. So my next step was to consult someone who had finished. I talked with Wooden and decided to use the style he had for an algorithm. He said it was simple. Go forward and if you were too far from a wall turn towards it. If too close turn away. Else turn a corner. That algorithm seemed to actually work for me. I just had to find an appropriate range for the wall. I ended up with a 5 inch range. One way larger than I thought I would go with. After my tests, I had a working robot. It would consistently get required functionality. So I immediately tried to video tape it. When my camera was out, the sensors would not work right. I think the IR sensors were picking up something from my camera. After more tinkering I found out how to position my robot so that it started in the range of the wall. And, I also found out when trying to go for B and A functionality, that my front sensor had quit working. After showing my required functionality, I attempted to fix my front sensor. I determined that it was lost cause. I tried everything that I knew. I tried taking the resistor out, checking the VMM, and changing the range. I found out that the VMM was reading normal values sometimes and low values other times. And, sometimes the sensor would work at a specific range and the other times it would not work. I found that out when changing the threshold for the front sensor. I started with extremes. I narrowed it down to x80 and x7F. At x80 it did not register until the sensors were completely covered at 0inches. At x7F, the sensor was activated at 3 feet. This is when I gave up on the sensors. Because I could not detect a front wall, I was unable to attempt B or A functionality.

#### Documentation
Dr. Coulston's code for sampling the sensors.
Dr. York's Code for reading the sensors.
C2C Wooden for providing me with insight to a simple algorthim.

