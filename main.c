#define F_CPU 14000000			    //14Mhz
#include <avr/io.h>					//Header file for AVR device specific I/O Definitions.
#include <avr/pgmspace.h>			//Header file for incorporating program space string utilities.
#include <avr/interrupt.h>			//Header file for incorportaing interrupt handling faclity (not used here).
#include <util/delay.h>				//Header file for incorporating delay routines.
#include "lcd2.h"					//Header file for the LCD Module driver.

#define USART_BAUDRATE 9600
#define BAUD_PRESCALE (((F_CPU / (USART_BAUDRATE * 16UL))) - 1)
#define RATE 250					//Rate of scrolling.
void WaitMs(unsigned int ms);		//Declaration of delay routine used.

void usart_init();
unsigned int usart_getch();
 
unsigned char value,i,lati_value[15],lati_dir, longi_value[15], longi_dir ;
int main()
{
	lcd_init(LCD_DISP_ON);			//LCD Initialisation,  LCD turned on with cursor off.

	lcd_clrscr();					//LCD clear display routine.				//Variable to hold the length of the message stored.
	unsigned char i;		//Max width of the LCD Display.
lcd_gotoxy(0,0);
	
usart_init();
while(1)
{
	value=usart_getch();
	if(value=='$')
	{
		value=usart_getch();
		if(value=='G')
		{
			value=usart_getch();
			if(value=='P')
			{
				value=usart_getch();
				if(value=='G')
				{
					value=usart_getch();
					if(value=='G')
					{
						value=usart_getch();
						if(value=='A')
						{
							value=usart_getch();
							if(value==',')
							{
								value=usart_getch();
								while(value!=',')
								{
									value=usart_getch();
								}
								lati_value[0]=usart_getch();
								value=lati_value[0];
								lcd_gotoxy(1,0);
								lcd_putc(lati_value[0]);
								
								for(i=1;value!=',';i++)
								{
									lati_value[i]=usart_getch();
									lcd_putc(lati_value[i]);
									value=lati_value[i];
								}
								lati_dir=usart_getch();
								lcd_putc(lati_dir);
								value=usart_getch();
								lcd_gotoxy(0,1);
								longi_value[0]=usart_getch();
								value=longi_value[0];
								lcd_putc(longi_value[0]);
								for(i=1;value!=',';i++)
								{
									longi_value[i]=usart_getch();
									lcd_putc(longi_value[i]);
									value=longi_value[i];
								}
								longi_dir=usart_getch();
								lcd_putc(longi_dir);

								_delay_ms(1000);
							}
						}
					}
				}
			}
		}
	}
}
 

	return 0;						//End of main function.
}



void WaitMs(unsigned int ms)		//Generates a delay of ms millisecond.
{
	unsigned int i;

	for(i=0;i<=ms;i++)
	{
		_delay_ms(1);
	}
}


 
void usart_init()
{
   
UCSRB =  (1 << RXEN) | (1 << TXEN);   // Turn on the transmission and reception circuitry

UCSRC |= (1 << URSEL) | (1 << UCSZ0) | (1 << UCSZ1);   // Use 8-bit character sizes
UBRRL = BAUD_PRESCALE; // Load lower 8-bits of the baud rate value into the low byte of the UBRR register
UBRRH = (BAUD_PRESCALE >> 8); // Load upper 8-bits of the baud rate value into the high byte of the UBRR register
}
 
 
unsigned int usart_getch()
{
 
while (!(UCSRA & (1 << RXC))); // Do nothing until data have been recieved and is ready to be read from UDR
return(UDR); // return the byte
}
 
