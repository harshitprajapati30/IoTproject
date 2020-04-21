#define F_CPU 8000000UL // 8Mhz frequency
#include <avr/io.h>
#include <util/delay.h>
//IOT WORKSHOP Page 50
void character(unsigned char t) //function to transmit a character
{
while(!(UCSRA&(1<<UDRE))); //wait until UDR is empty
UDR=t; //transmit character
}
void number(unsigned int t)
{
while(!(UCSRA&(1<<UDRE)));
UDR=t;
}

void string(char a[])
{
while(!(UCSRA&(1<<UDRE)));
int i;
	for(i=0;a[i]!='\0';i++)
	character(a[i]);

}
void u_init() //function to initialize USART
{
UBRRL=51; // 9600 BAUD RATE
UCSRB|=(1<<TXEN); // transmit enable
UCSRC|=(1<<URSEL)|(1<<UCSZ0)|(1<<UCSZ1); //setting character size
}
int main(void)
{
u_init(); // initializing USART
character('A'); // transmit ‘A’
}
