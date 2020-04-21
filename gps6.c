#define F_CPU 16000000			    //14Mhz
#include <avr/io.h>					//Header file for AVR device specific I/O Definitions.
#include <avr/pgmspace.h>			//Header file for incorporating program space string utilities.
#include <avr/interrupt.h>			//Header file for incorportaing interrupt handling faclity (not used here).
#include <util/delay.h>				//Header file for incorporating delay routines.
#include"uart.h"

#define RATE 250					//Rate of scrolling.
void WaitMs(unsigned int ms);		//Declaration of delay routine used.


unsigned char c,value,i,lati_value[15],lati_dir,longi_value[15],longi_dir;
int main()
{

uart_init();
DDRB=0B111111111;
_delay_ms(1000);
uart_string("AT+CWMODE=3\r\n");
_delay_ms(3000);
uart_string("AT+CWJAP=\"G\",\"vinnunikki\"\r\n");
_delay_ms(5000);

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
									if(longi_value[i]=='.')
									{	int sub=longi_value[i];
									longi_value[i]=longi_value[i-2];
									longi_value[i-2]=sub;
								}
								}
								for(i=0;i<10;i++)
								{
									if(lati_value[i]=='.')
									{	int temp=lati_value[i];
									lati_value[i]=lati_value[i-2];
									lati_value[i-2]=temp;
								}
								}
								
									for(int j=0;j<15;j++)
								{
									if(longi_value[j]==',')
									{
										longi_value[j]='\0';
										longi_value[j-1]='\0';
										longi_value[j-2]='\0';
										longi_value[j-2]='\0';
										longi_value[j-3]='\0';

										}
								}

								for(int j=0;j<15;j++)
								{
									if(lati_value[j]==',')
									{
										lati_value[j]='\0';
										lati_value[j-1]='\0';
										lati_value[j-2]='\0';
										lati_value[j-2]='\0';
										lati_value[j-3]='\0';

										}
								}
								_delay_ms(5000);
									 uart_string("AT+CIPSTART=\"TCP\",\"api.thingspeak.com\",80\r\n");
									_delay_ms(3000);
									uart_string("AT+CIPSEND=150\r\n");
									_delay_ms(100);
									uart_string("GET /update?api_key=SPVEA7A3J0OMKS96&field1=");
									uart_string(lati_value);
									uart_string("&field2=");
									uart_string(longi_value);
									
									uart_string("\r\n");
									_delay_ms(10000);
									uart_string("AT+CIPCLOSE\r\n");
									_delay_ms(6000);
									uart_string("\r\n");
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


 

