/*
 * main.c
 *
 *  Created on: Jun 13, 2017
 *      Author: Mina G. Sadek
 */

#ifdef F_CPU
#undef F_CPU
#endif
#define F_CPU 1000000

#define TRIG_PIN 3
#define ECHO_PIN 2
#define TRIG_PORT PORTC
#define TRIG_DDR  DDRC
#define ECHO_IN   PIND
#define ECHO_DDR  DDRD

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdlib.h>
#include "lcd/lcdlib.h"
#include "MACROS.h"

static volatile int pulse_time = 0;

int main(void)
{
	unsigned int distance = 0;

	LCD_Init();
	_delay_ms(200);
	LCD_CmdWrite(_LCD_CLR);
	_delay_ms(10);
	lcd_write_string("ULTRASONIC V0.1");
	LCD_CmdWrite(0x80 + 0x40 + 0);		// move cursor 2nd row, first character
	lcd_write_string("    Welcome    ");
	_delay_ms(1000);
	LCD_CmdWrite(_LCD_CLR);
	_delay_ms(10);

	TRIG_DDR |= (1<<TRIG_PIN);
	ECHO_DDR &= (1<<ECHO_PIN);

	EIMSK |= (1<<INT0);	// enable INT0
	EICRA |= (1<<ISC00);// setting interrupt trigger on any change

	lcd_write_string("ULTRASONIC V0.1");
	sei();

	while(1)
	{
		TRIG_PORT |= (1<<TRIG_PIN);
		_delay_us(15);						// trigger the ultrasonic module for 15usec
		TRIG_PORT &= ~(1<<TRIG_PIN);

		distance = pulse_time * 0.0343 / 2;	// calculate the distance
		LCD_CmdWrite(0x80 + 0x40 + 0);		// move cursor 2nd row, first character
		lcd_write_string("DIST=");
		lcd_write_int(distance);
		lcd_write_string("  cm      ");
		LCD_CmdWrite(0x80 + 0); 			// go to first character in the row
	}
}

// This ISR is called automatically when a change on the INT0 pin happens due to the change of the echo pin from the ultrasonic module
ISR(INT0_vect)
{
	if ((ECHO_IN & (1<<ECHO_PIN)) == 0)
	{
		// echo changed from HIGH to LOW
		TCCR1B = 0;		//disabling counter
		pulse_time = TCNT1;	//count memory is updated to integer
		TCNT1 = 0;		//resetting the counter memory
	} else {
		// echo changed change from LOW to HIGH
		TCCR1B |= (1<<CS10);//enabling counter
	}
}
