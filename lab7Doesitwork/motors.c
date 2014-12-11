/*
 * motors.c
 *
 *  Created on: Dec 9, 2014
 *      Author: C16Austin.Bolinger
 */

#include <msp430.h>
#include "motors.h"

int speedR = 50;
int speedL = 52;
int SPD = 50;
int max = 55;
int min = 45;

void setSpeed() {
	speedR = SPD;
	speedL = SPD;
}

void increaseSpeedR() {
	if (speedR > max) {
		speedR++;
	} else {
		speedR = max;
	}
}
void increaseSpeedL() {
	if (speedL > max) {
		speedL++;
	} else {
		speedL = max;
	}
}
void decreaseSpeedR() {
	if (speedR < min) {
		speedR--;
	} else {
		speedR = min;
	}
}
void decreaseSpeedL() {
	if (speedL < min) {
		speedL--;
	} else {
		speedL = min;
	}
}

void stop() { //stop the PWMs
	P2DIR &= ~(BIT4 | BIT2);                // TA1CCR1 on P2.4 reversed

	P2DIR &= ~(BIT1 | BIT5);
	P2OUT &= ~(BIT1 | BIT5);					// P2.1&5 = GND

	TA1CTL &= ~MC1 | MC0;            // stop timer A1

	TA1CTL |= TACLR;                // clear timer A1
}

void forward() {
	P2DIR |= BIT4 | BIT2;                // TA1CCR1 on P2.4
	P2SEL |= BIT4 | BIT2;

	P2DIR |= BIT1 | BIT5;
	P2OUT &= ~(BIT1 | BIT5);					// P2.1 = GND

	TA1CTL &= ~MC1 | MC0;            // stop timer A1

	TA1CTL |= TACLR;                // clear timer A1

	TA1CTL |= TASSEL1;           // configure for SMCLK

	TA1CCR0 = 100;  // set signal period to 100 clock cycles (~100 microseconds)

	TA1CCR1 = speedR;
	TA1CCR2 = speedL;

	TA1CCTL1 |= OUTMOD_7;
	TA1CCTL2 |= OUTMOD_7;        // set TACCTL2 to Reset / Set mode

	TA1CTL |= MC0;                // count up
	__delay_cycles(2500);
}

void backward() {
	P2DIR |= BIT4 | BIT2;                // TA1CCR1 on P2.4
	P2SEL |= BIT4 | BIT2;

	P2DIR |= BIT1 | BIT5;
	P2OUT |= BIT1 | BIT5;				//P2.1 = high

	TA1CTL &= ~MC1 | MC0;            // stop timer A1

	TA1CTL |= TACLR;                // clear timer A1

	TA1CTL |= TASSEL1;           // configure for SMCLK

	TA1CCR0 = 100;  // set signal period to 100 clock cycles (~100 microseconds)

	TA1CCR1 = speedR;
	TA1CCR2 = speedL;

	TA1CCTL1 |= OUTMOD_3;
	TA1CCTL2 |= OUTMOD_3;        // set TACCTL2 to Set / Reset mode

	TA1CTL |= MC0;                // count up
}

void turnRight() {
	P2DIR |= BIT4 | BIT2;                // TA1CCR1 on P2.4
	P2SEL |= BIT4 | BIT2;

	P2DIR |= BIT1 | BIT5;
	P2OUT |= BIT5;				//P2.1 = high
	P2OUT &= ~BIT1;

	TA1CTL &= ~MC1 | MC0;            // stop timer A1

	TA1CTL |= TACLR;                // clear timer A1

	TA1CTL |= TASSEL1;           // configure for SMCLK

	TA1CCR0 = 100;  // set signal period to 100 clock cycles (~100 microseconds)
	speedR = SPD;
	speedL = SPD;
	TA1CCR1 = speedR;
	TA1CCR2 = speedL;

	TA1CCTL1 |= OUTMOD_3;
	TA1CCTL2 |= OUTMOD_7;        // set TACCTL2 to Set / Reset mode

	TA1CTL |= MC0;                // count up
	__delay_cycles(100000);
}

void turnRightSlightly() {
	P2DIR |= BIT4 | BIT2;                // TA1CCR1 on P2.4
	P2SEL |= BIT4 | BIT2;

	//P2DIR &= ~BIT2;

	P2DIR |= BIT1 | BIT5;
	//P2OUT |= BIT5 | BIT1;				//P2.1 = high
	P2OUT &= ~(BIT1 | BIT5);

	TA1CTL &= ~MC1 | MC0;            // stop timer A1

	TA1CTL |= TACLR;                // clear timer A1

	TA1CTL |= TASSEL1;           // configure for SMCLK

	TA1CCR0 = 100;  // set signal period to 100 clock cycles (~100 microseconds)
	speedR = SPD;
	speedL = SPD;
	TA1CCR1 = speedR;
	TA1CCR2 = speedL;

	TA1CCTL1 |= OUTMOD_7;
	TA1CCTL2 |= OUTMOD_7;        // set TACCTL2 to Set / Reset mode

	TA1CTL |= MC0;                // count up
	__delay_cycles(2500);
}

void turnLeft() {
	P2DIR |= BIT4 | BIT2;                // TA1CCR1 on P2.4
	P2SEL |= BIT4 | BIT2;

	P2DIR |= BIT1 | BIT5;
	P2OUT |= BIT1;				//P2.1 = high
	P2OUT &= ~BIT5;

	TA1CTL &= ~MC1 | MC0;            // stop timer A1

	TA1CTL |= TACLR;                // clear timer A1

	TA1CTL |= TASSEL1;           // configure for SMCLK

	TA1CCR0 = 100;  // set signal period to 100 clock cycles (~100 microseconds)
	speedR = SPD;
	speedL = SPD;
	TA1CCR1 = speedR;
	TA1CCR2 = speedL;

	TA1CCTL2 |= OUTMOD_3;
	TA1CCTL1 |= OUTMOD_7;        // set TACCTL2 to Set / Reset mode

	TA1CTL |= MC0;                // count up
	__delay_cycles(150000);
}

void turnLeftSlightly() {
	P2DIR |= BIT4 | BIT2;                // TA1CCR1 on P2.4
	P2SEL |= BIT4 | BIT2;

	//P2DIR &= ~BIT4;

	P2DIR |= BIT1 | BIT5;
	//P2OUT |= BIT1 | BIT5;				//P2.1 = high
	P2OUT &= ~(BIT1 | BIT5);

	TA1CTL &= ~MC1 | MC0;            // stop timer A1

	TA1CTL |= TACLR;                // clear timer A1

	TA1CTL |= TASSEL1;           // configure for SMCLK

	TA1CCR0 = 100;  // set signal period to 100 clock cycles (~100 microseconds)
	speedR = SPD;
	speedL = SPD;
	TA1CCR1 = speedR;
	TA1CCR2 = speedL;

	TA1CCTL2 |= OUTMOD_7;
	TA1CCTL1 |= OUTMOD_7;        // set TACCTL2 to Set / Reset mode

	TA1CTL |= MC0;                // count up
	__delay_cycles(2500);
}
void findWall() {
	P2DIR |= BIT4 | BIT2;                // TA1CCR1 on P2.4
	P2SEL |= BIT4 | BIT2;

	P2DIR |= BIT1 | BIT5;
	P2OUT &= ~(BIT1 | BIT5);					// P2.1 = GND

	TA1CTL &= ~MC1 | MC0;            // stop timer A1

	TA1CTL |= TACLR;                // clear timer A1

	TA1CTL |= TASSEL1;           // configure for SMCLK

	TA1CCR0 = 100;  // set signal period to 100 clock cycles (~100 microseconds)
	TA1CCR1 = speedR;
	TA1CCR2 = speedL;

	TA1CCTL1 |= OUTMOD_7;
	TA1CCTL2 |= OUTMOD_7;        // set TACCTL2 to Reset / Set mode

	TA1CTL |= MC0;                // count up
}
