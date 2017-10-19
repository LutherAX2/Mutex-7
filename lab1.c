/*9 Lab 1 first file ID number 96013952*/
#include <p18f452.h>

/*set configuration bits for use with ICD2*/
#pragma config OSC = HS
#pragma config WDT = OFF
#pragma config LVP = OFF


void main (void)
{
    
    char counter1;
    for(counter1=1;counter1 <= 15;counter1++)
    {
        TRISB = 0x00;
        PORTB = counter1;
    }
}