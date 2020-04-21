#include<avr/io.h>
#include<util/delay.h>
void main()
{
DDRB=0xFF;
while(1){
   for(int i=0;i<8;i++)
   {
   PORTB=0B00000000;
   
   PORTB|=(1<<i);
   _delay_ms(500);
}

}
}
