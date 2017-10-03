#define F_CPU 1000000UL  /* 1 MHz CPU clock */
 
#include <util/delay.h>
#include <avr/io.h>
 
int
main (void)
{
        DDRC = _BV (PC0);               /* PC0 is digital output */
 
        while (1)                       /* loop forever */
        {
                /* set PC0 on PORTC (digital high) and delay for 500mS */
                PORTC |= _BV(PC0);
                _delay_ms(500);
 
                /*  PC0 on PORTC (digital 0) and delay for 500mS */
                PORTC &= ~_BV(PC0);                
                _delay_ms(500);
        }
 
        return (0);
}
