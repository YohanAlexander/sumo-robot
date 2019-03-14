#include <avr/io.h>
#include <util/delay.h>

int infra(void){

  unsigned char pino7; 
  unsigned char pino6;  
  DDRD = DDRD|0b00111100;
  Serial.begin(9600);

  while(1){
  pino7 = (PIND & 128) >> 7;
  pino6 = (PIND & 64) >> 6;
  Serial.println(pino6, DEC); //Imprime o valor do pino em decimal

  if (pino7 == 1){PORTD = 0b00101000; return 7;}
  if (pino6 == 1){PORTD = 0b00010100; return 6;}
  if (pino6 == 0 && pino7 == 0){PORTD = 0b00111100; return 0;}
  }
}