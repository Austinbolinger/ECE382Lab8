#include "sensors.h"
#include <msp430g2553.h>
#include "motors.h"
/*
 * main.c
 */

int sensorReadingM;
int sensorReadingL;
int sensorReadingR;

int frontTH = 0x0188; //increase for closer reading
int leftTH1 = 0x021D; //close
int leftTH2 = 0x0160; //far
int rightTH1 = 0x0155; //slight turn
int rightTH2 = 0x0175; //turn

int main(void) {
	WDTCTL = WDTPW + WDTHOLD;                 // Stop WDT
	ADC10CTL0 = ADC10SHT_3 + ADC10ON + ADC10IE; // ADC10ON, interrupt enabled

	while (1) {

		sensorReadingM = middle();
		sensorReadingL = left();
		sensorReadingR = right();

//		if (sensorReadingM < frontTH) {
//			forward();
//		}
//		else{
//			stop();
//		}

		if (sensorReadingM < frontTH) {
			forward();
			P1DIR |= BIT6| BIT0;
			P1OUT &= ~(BIT6|BIT0);

			if (sensorReadingL > leftTH1) {
				turnRight();
			}
			if (sensorReadingL < leftTH2) {
				turnLeft();
			}
		} else {
			P1OUT |= BIT6;
			if (sensorReadingR < rightTH1) {
				turnRight();
				P1OUT |= BIT0;
			}
			__delay_cycles(150000);
		}



		//		if (sensorReadingM > frontTH) {
//			if (sensorReadingL > leftTH2) {
//				turnRight();
//			} else if (sensorReadingR > rightTH2) {
//				turnLeft();
//			}  else {
//
//				turnLeft();
//			}
//		} else {
//			if (sensorReadingL < leftTH2) {
//				decreaseSpeedL();
//				forward();
//			} else if (sensorReadingL > leftTH1) {
//				increaseSpeedL();
//				forward();
//			} else
//				if (sensorReadingR > rightTH1) {
//				decreaseSpeedL();
//				forward();
//			}else {
//				setSpeed();
//				forward();
//			} //end else
//		}//end else

//		if (sensorReadingM < frontTH) {
//			if (sensorReadingL > leftTH1) {
//				//stop();
//				turnLeftSlightly();
//			} else if (sensorReadingR > rightTH1) {
//				//stop();
//				turnRightSlightly();
//			} else {
//				forward();
//			}
//		} else {
//			if (sensorReadingL > leftTH2) {
//				turnRight();
//			}
//			if (sensorReadingR > rightTH2) {
//				turnLeft();
//			} else {
//				turnRight();
//			} //end else
//		} //end else

	}
//end while

}

