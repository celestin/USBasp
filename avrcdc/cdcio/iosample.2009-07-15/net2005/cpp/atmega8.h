#pragma once


//	ATmega8 Special Function Registers

#ifndef _ATMEGA8_
#define	_ATMEGA8_

enum SFR {

	TWBR	= 0x20,
	TWSR,
	TWAR,
	TWDR,
	ADCL,
	ADCH,
	ADCSRA,
	ADMUX,
	ACSR,
	UBRRL,
	UCSRB,
	UCSRA,
	UDR,
	SPCR,
	SPSR,
	SPDR,
	PIND,
	DDRD,
	PORTD,
	PINC,
	DDRC,
	PORTC,
	PINB,
	DDRB,
	PORTB,
	EECR	= 0x3c,
	EEDR,
	EEARL,
	EEARH,
	UCSRC,
	UBRRH	= 0x40,
	WDTCR,
	ASSR,
	OCR2,
	TCNT2,
	TCCR2,
	ICR1L,
	ICR1H,
	OCR1BL,
	OCR1BH,
	OCR1AL,
	OCR1AH,
	TCNT1L,
	TCNT1H,
	TCCR1B,
	TCCR1A,
	SFIOR,
	OSCCAL,
	TCNT0,
	TCCR0,
	MCUCSR,
	MCUCR,
	TWCR,
	SPMCR,
	TIFR,
	TIMSK,
	GIFR,
	GICR,

	SPL	= 0x5d,
	SPH,
	SREG
};

#endif
