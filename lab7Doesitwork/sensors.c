#include <msp430.h>
#include "sensors.h"

int left() {

	unsigned short sample[16];					// Just to analyze the values
	unsigned char i = 0;

	ADC10CTL0 = ADC10SHT_3 + ADC10ON; // ADC10ON, interrupt enabled
	ADC10CTL1 = INCH_3;                       // input A2 (left sensor)
	ADC10AE0 |= BIT3;                         // PA.1 ADC option select
	ADC10CTL1 |= ADC10SSEL1 | ADC10SSEL0;                // Select SMCLK
	ADC10CTL0 |= ENC + ADC10SC;             // Sampling and conversion start

	while (ADC10CTL1 & ADC10BUSY)
		;

	sample[i] = ADC10MEM;
	i = (i+1) & 0xF;

	return ADC10MEM;
}

int middle() {

	unsigned short sample[16];					// Just to analyze the values
	unsigned char i = 0;

	ADC10CTL0 = ADC10SHT_3 + ADC10ON; // ADC10ON, interrupt enabled
	ADC10CTL1 = INCH_4;                       // input A2 (left sensor)
	ADC10AE0 |= BIT4;                         // PA.1 ADC option select
	ADC10CTL1 |= ADC10SSEL1 | ADC10SSEL0;                // Select SMCLK
	ADC10CTL0 |= ENC + ADC10SC;             // Sampling and conversion start

	while (ADC10CTL1 & ADC10BUSY)
		;

	sample[i] = ADC10MEM;
	i = (i+1) & 0xF;

	return ADC10MEM;
}

int right() {

	unsigned short sample[16];					// Just to analyze the values
	unsigned char i = 0;

	ADC10CTL0 = ADC10SHT_3 + ADC10ON; // ADC10ON, interrupt enabled
	ADC10CTL1 = INCH_6;                       // input A2 (left sensor)
	ADC10AE0 |= BIT6;                         // PA.1 ADC option select
	ADC10CTL1 |= ADC10SSEL1 | ADC10SSEL0;                // Select SMCLK
	ADC10CTL0 |= ENC + ADC10SC;             // Sampling and conversion start

	while (ADC10CTL1 & ADC10BUSY)
		;

	sample[i] = ADC10MEM;
	i = (i+1) & 0xF;

	return ADC10MEM;
}
