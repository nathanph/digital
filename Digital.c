/*
 * Digital.c
 *
 * Created: 1/27/2014 6:26:48 PM
 *  Author: Nathan Hernandez
 */ 

#include "Digital.h"

/*int main(void)
{
	pinMode(13, OUTPUT);
    while(1)
    {
		digitalWrite(13,LOW);
        //TODO:: Please write your application code 
		
    }
}*/

int8_t pinMode(uint8_t pin, uint8_t mode) {
	if(pin>A5)
		return -1;
	if(mode>INPUT_PULLUP)
		return -1;
	switch(pin) {
		case D0:
		case D1:
		case D2:
		case D3:
		case D4:
		case D5:
		case D6:
		case D7:
			switch(mode) {
				case OUTPUT:
					DDRD |= (1<<pin);
					return 0;
				case INPUT:
					DDRD &= ~(1<<pin);
					PORTD &= ~(1<<pin);
					return 0;
				case INPUT_PULLUP:
					DDRD &= ~(1<<pin);
					PORTD |= (1<<pin);
					return 0;
			}
		case D8:
		case D9:
		case D10:
		case D11:
		case D12:
		case D13:
			switch(mode) {
				case OUTPUT:
					DDRB |= (1<<(pin-8));
					return 0;
				case INPUT:
					DDRB &= ~(1<<(pin-8));
					PORTB &= ~(1<<(pin-8));
					return 0;
				case INPUT_PULLUP:
					DDRB &= ~(1<<(pin-8));
					PORTB |= (1<<(pin-8));
					return 0;
			}
		case A0:
		case A1:
		case A2:
		case A3:
		case A4:
		case A5:
			switch(mode) {
				case OUTPUT:
					DDRC |= (1<<(pin-14));
					return 0;
				case INPUT:
					DDRC &= ~(1<<(pin-14));
					PORTC &= ~(1<<(pin-14));
					return 0;
				case INPUT_PULLUP:
					DDRC &= ~(1<<(pin-14));
					PORTC |= (1<<(pin-14));
					return 0;
			}
	}
	return 0;
}

int8_t digitalRead(uint8_t pin) {
	if(pin>A5)
		return -1;
	switch(pin) {
		case D0:
		case D1:
		case D2:
		case D3:
		case D4:
		case D5:
		case D6:
		case D7:
			return (PORTD & (1<<pin)) ? 1 : 0;
		case D8:
		case D9:
		case D10:
		case D11:
		case D12:
		case D13:
			return (PORTB & (1<<(pin-8))) ? 1 : 0;
		case A0:
		case A1:
		case A2:
		case A3:
		case A4:
		case A5:
			return (PORTC & (1<<(pin-14))) ? 1 : 0;
	}
	return 0;
}

int8_t digitalWrite(uint8_t pin, uint8_t value) {
	if(pin<D0 || pin>A5)
		return -1;
	switch(pin) {
		case D0:
		case D1:
		case D2:
		case D3:
		case D4:
		case D5:
		case D6:
		case D7:
			switch(value) {
				case HIGH:
					PORTD |= (1<<pin);
					return value;
				case LOW:
					PORTD &= ~(1<<pin);
					return value;
			}
		case D8:
		case D9:
		case D10:
		case D11:
		case D12:
		case D13:
			switch(value) {
				case HIGH:
					PORTB |= (1<<(pin-8));
					return value;
				case LOW:
					PORTB &= ~(1<<(pin-8));
					return value;
			}
		case A0:
		case A1:
		case A2:
		case A3:
		case A4:
		case A5:
			switch(value) {
				case HIGH:
					PORTC |= (1<<(pin-14));
					return value;
				case LOW:
					PORTC &= ~(1<<(pin-14));
					return value;
			}
	}
	return value;
}