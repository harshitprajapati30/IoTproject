#define F_CPU 16000000UL
#include<avr/io.h>
#include<util/delay.h>
#include"uart.h"
void main()
{
uart_init();
 uart_string("AT+RST\r\n");
_delay_ms(1000);
uart_string("AT+CWMODE=3\r\n");
_delay_ms(1000);
uart_string("AT+CWJAP=\"G\",\"vinnunikki\"\r\n");
_delay_ms(1000);
while(1)
{
uart_string("AT+CIPSTART=\"TCP\",\"api.thingspeak.com\",80\r\n");
_delay_ms(2000);
uart_string("AT+CIPSEND=80\r\n");
_delay_ms(500);
uart_string("GET /update?api_key=SPVEA7A3J0OMKS96&field1=100ield2=100");
_delay_ms(1000);
uart_string("AT+CIPCLOSE"); 
_delay_ms(6000);


}
}
