#define F_CPU 14000000			    //14Mhz
#include <avr/io.h>					//Header file for AVR device specific I/O Definitions.
#include <avr/pgmspace.h>			//Header file for incorporating program space string utilities.
#include <avr/interrupt.h>			//Header file for incorportaing interrupt handling faclity (not used here).
#include <util/delay.h>				//Header file for incorporating delay routines.
#include"uart.h"

#define RATE 250					//Rate of scrolling.
void WaitMs(unsigned int ms);		//Declaration of delay routine used.


unsigned char c,value,i,lati_value[15],lati_dir, longi_value[15], longi_dir,latitude[8],longitude[8] ;
int main()
{

uart_init();
DDRB=0B111111111;


uart_string("hello");
while(1)
{	
	
	value=uart_read();
	if(value=='$')
	{	PORTB=0B11111111;
		value=uart_read();
		if(value=='G')
		{	
			value=uart_read();
			if(value=='P')
			{
				value=uart_read();
				if(value=='G')
				{
					value=uart_read();
					if(value=='G')
					{
						value=uart_read();
						if(value=='A')
						{		
							value=uart_read();
							if(value==',')
							{
								value=uart_read();
								while(value!=',')
								{	
									value=uart_read();
								}
								lati_value[0]=uart_read();
								value=lati_value[0];
								
								
								for(i=1;value!=',';i++)
								{	
									lati_value[i]=uart_read();
								
									value=lati_value[i];
								}
								lati_dir=uart_read();
								 
								 
							
								value=uart_read();
								
								longi_value[0]=uart_read();
								value=longi_value[0];
								
								for(i=1;value!=',';i++)
								{	
								
									
									longi_value[i]=uart_read();
									
								
									value=longi_value[i];
							
									
								}
								longi_dir=uart_read();
								
							

								_delay_ms(1000);
								

								for(i=0;i<10;i++)
								{
									if(lati_value[i]=='.')
									{	int temp=lati_value[i];
									lati_value[i]=lati_value[i-2];
									lati_value[i-2]=temp;
								}
								}
								//uart_string(lati_value);
								
									for(i=0;i<10;i++)
								{
									if(longi_value[i]=='.')
									{	int temp=longi_value[i];
									longi_value[i]=longi_value[i-2];
									longi_value[i-2]=temp;
								}
								}
								for(int i=0;i<8;i++)
								{
									longitude[i]=longi_value[i];
								}

								for(int i=0;i<8;i++)
								{
									latitude[i]=lati_value[i];
								}


									uart_string(longitude);
									_delay_ms(1000);
									uart_string(latitude);
									_delay_ms(3000);

								

								
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


 

