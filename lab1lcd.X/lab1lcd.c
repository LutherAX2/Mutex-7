#include <p18f452.h>
#include "xlcd2.h"
#include <delays.h>

/* Set configuration bits for use with ICD2 */
#pragma config OSC = HS
#pragma config WDT = OFF
#pragma config LVP = OFF



#define _XTAL_FREQ 4000000

void DelayFor18TCY( void )
{
 Nop();
 Nop();
 Nop();
 Nop();
 Nop();
 Nop();
 Nop();
 Nop();
 Nop();
 Nop();
 Nop();
 Nop();
}
void DelayPORXLCD (void)
{
 Delay1KTCYx(15); // Delay of 15ms
 // Cycles = (TimeDelay * Fosc) / 4
 // Cycles = (15ms * 4MHz) / 4
 // Cycles = 15,000
 return;
}



void DelayXLCD (void)
{
 Delay1KTCYx(5); // Delay of 5ms
 // Cycles = (TimeDelay * Fosc) / 4
 // Cycles = (5ms * 4MHz) / 4
 // Cycles = 5,000
 return;
}



void init_XLCD( void )
{
 // configure external LCD
OpenXLCD(FOUR_BIT & LINES_5X7);
while( BusyXLCD() );
WriteCmdXLCD( FOUR_BIT & LINES_5X7 );
while( BusyXLCD() );
WriteCmdXLCD( BLINK_ON );
while( BusyXLCD() );
WriteCmdXLCD( SHIFT_DISP_LEFT );


}


void main(void)
{
 init_XLCD(); //Call the Initialize LCD display function
 while( BusyXLCD() );
 SetDDRamAddr(0x43); //shift cursor to fourth space of second line
 putrsXLCD("Hello World"); //Display "Hello World"
 while(1)
 {
 }
 }