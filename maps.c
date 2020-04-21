#define F_CPU 16000000UL
#include<avr/io.h>
#include<util/delay.h>
#include"uart.h"
void main()
{
	uart_init(); 
	//_delay_ms(1000);
//uart_string("AT+CWMODE=3\r\n");
//_delay_ms(3000);
//uart_string("AT+CWJAP=\"G\",\"vinnunikki\"\r\n");
//_delay_ms(5000);

while(1)
{
	uart_num(100);
	_delay_ms(1000);
	uart_string("AT+CIPSTART=\"TCP\",\"api.thingspeak.com\",80\r\n");
	_delay_ms(100);
	uart_string("AT+CIPSEND=70\r\n");
	_delay_ms(100);
	uart_string(" GET /update?api_key=SPVEA7A3J0OMKS96&field1=30");	
	uart_string("\r\n");
	_delay_ms(100);
	uart_string("AT+CIPCLOSE\r\n");
	_delay_ms(6000);



}












}
