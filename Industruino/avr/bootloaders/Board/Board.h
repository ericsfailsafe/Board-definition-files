/** ***************************************************************************
 * Description       : Definitions and functions for MattairTech USB AVR boards
 * Compiler          : GCC
 *
 * Updated April 15, 2013 by Justin Mattair
 *************************************************************************** **/

#ifndef __BOARD_H__
#define __BOARD_H__

/** Includes: **/
#include <avr/io.h>

/** Defines **/
#ifndef _INLINE_
#define _INLINE_ static inline __attribute__((always_inline))
#endif

#if defined(__AVR_ATmega32U2__) || defined(__AVR_AT90USB162__)
#define JUMPER		(1 << 7)
#define LED		(1 << 0)
#elif defined(__AVR_ATmega32U4__)
#define JUMPER		(1 << 2)
#define LED		(1 << 7)
#elif defined(__AVR_AT90USB646__) || defined(__AVR_AT90USB1286__)
#define JUMPER          (1 << 2)
#define LED             (1 << 7)
#else
#error unsupported board
#endif


/** Inline Functions: **/

#if defined(__AVR_ATmega32U2__) || defined(__AVR_AT90USB162__)
/* Jumper */
_INLINE_ void Jumper_Init(void)		// input with pullup
{
	DDRD  &= ~JUMPER;	// input
	PORTD |=  JUMPER;	// pullup
}

_INLINE_ uint8_t Jumper_GetStatus(void)		// returns 1 when pressed, 0 otherwise
{
	return ((PIND & JUMPER) ^ JUMPER);
}

/* LED */
_INLINE_ void LED_Init(void)	// default off (low)
{
	PORTD &= ~LED;		// low
	DDRD  |=  LED;		// output
}

_INLINE_ void LED_Disable(void)
{
	DDRD  &=  ~LED;		// input
	PORTD &=  ~LED;		// pullup off
}

_INLINE_ void LED_On(void)
{
	PORTD |= LED;
}

_INLINE_ void LED_Off(void)
{
	PORTD &= ~LED;
}

_INLINE_ void LED_Toggle(void)
{
	PORTD = (PORTD ^ (LED));
}

#elif defined(__AVR_ATmega32U4__)

/* Jumper */
_INLINE_ void Jumper_Init(void)		// input with pullup
{
	DDRE  &= ~JUMPER;	// input
	PORTE |=  JUMPER;	// pullup
}

_INLINE_ uint8_t Jumper_GetStatus(void)		// returns 1 when pressed, 0 otherwise
{
	return ((PINE & JUMPER) ^ JUMPER);
}

/* LED */
_INLINE_ void LED_Init(void)	// default off (low)
{
	PORTD &= ~LED;		// low
	DDRD  |=  LED;		// output
}

_INLINE_ void LED_Disable(void)
{
	DDRD  &=  ~LED;		// input
	PORTD &=  ~LED;		// pullup off
}

_INLINE_ void LED_On(void)
{
	PORTD |= LED;
}

_INLINE_ void LED_Off(void)
{
	PORTD &= ~LED;
}

_INLINE_ void LED_Toggle(void)
{
	PORTD = (PORTD ^ (LED));
}

#elif defined(__AVR_AT90USB646__) || defined(__AVR_AT90USB1286__)

/* Jumper */
_INLINE_ void Jumper_Init(void)         // input with pullup
{
        DDRE  &= ~JUMPER;       // input
        PORTE |=  JUMPER;       // pullup
}

_INLINE_ uint8_t Jumper_GetStatus(void)         // returns 1 when pressed, 0 otherwise
{
        return ((PINE & JUMPER) ^ JUMPER);
}

/* LED */
_INLINE_ void LED_Init(void)    // default off (low)
{
        PORTB &= ~LED;          // low
        DDRB  |=  LED;          // output
}

_INLINE_ void LED_Disable(void)
{
	DDRB  &=  ~LED;		// input
	PORTB &=  ~LED;		// pullup off
}

_INLINE_ void LED_On(void)
{
        PORTB |= LED;
}

_INLINE_ void LED_Off(void)
{
        PORTB &= ~LED;
}

_INLINE_ void LED_Toggle(void)
{
        PORTB = (PORTE ^ (LED));
}


#else
#error unsupported board
#endif

#endif
