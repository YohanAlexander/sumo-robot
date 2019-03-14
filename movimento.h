#include <avr/io.h>
#include <util/delay.h>

void direita(void){  
  PORTD = B00101000; //direita 1010
  _delay_ms(500);
}
void esquerda(void){ 
  PORTD = B00010100; //esquerda 0101
  _delay_ms(500);
}
void frente(void){ 
  PORTD = B00100100; //frente 1001
  _delay_ms(500);
}
void tras(void){
  PORTD = B00011000; //tras 0110
  _delay_ms(500);
}
void parar(void){
  PORTD = B00000000; //parar
  _delay_ms(1000);
}