#include<avr/io.h>
#include<util/delay.h>

int direita(void){
  DDRD = 0b00111100;  
  PORTD = 0b00101000; //direita 1010
  _delay_ms(5);
}

int esquerda(void){
  DDRD = 0b00111100;  
  PORTD = 0b00010100; //esquerda 0101
  _delay_ms(5);
}

int frente(void){
  DDRD = 0b00111100;
  PORTD = 0b00100100; //frente 1001
  _delay_ms(5);
}

int tras(void){
  DDRD = 0b00111100;
  PORTD = 0b00011000; //tras 0110
  _delay_ms(5);
}

int parar(void){
  DDRD = 0b00111100;
  PORTD = 0b00000000; //parar
  _delay_ms(5);
}