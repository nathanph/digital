/*
 * Digital.h
 *
 * Created: 2/8/2014 2:58:32 PM
 *  Author: Nathan Hernandez
 */ 


#ifndef DIGITAL_H_
#define DIGITAL_H_

	//Pin Voltage
	#define LOW	 0x0
	#define HIGH 0x1

	//Pin Mode
	#define INPUT 0x0
	#define OUTPUT 0x1
	#define INPUT_PULLUP 0x2

	//Digital Pins
	#define D0 0
	#define D1 1
	#define D2 2
	#define D3 3
	#define D4 4
	#define D5 5
	#define D6 6
	#define D7 7
	#define D8 8
	#define D9 9
	#define D10 10
	#define D11 11
	#define D12 12
	#define D13 13

	//Analog Pins
	#define A0 14
	#define A1 15
	#define A2 16
	#define A3 17
	#define A4 18
	#define A5 19

	#include <avr/io.h>
	#include <inttypes.h>

	int8_t pinMode(uint8_t pin, uint8_t mode);
	int8_t digitalWrite(uint8_t pin, uint8_t value);
	int8_t digitalRead(uint8_t pin);
	
#endif /* DIGITAL_H_ */