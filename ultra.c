#include<avr/io.h>
#include<util/delay.h>
#include"ultra.h"

const int trigPin = 13;
const int echoPin = 12;

float dist(void){

  unsigned long duracao = 0;
  float distancia;
  DDRB = 0b11101111;

  while (1){

    // Trigger
    PORTB = 0b00000000;
    _delay_ms(2);
    PORTB = 0b00100000;
    _delay_ms(10);
    PORTB = 0b00000000;

    // detectar eco sem uso de biblioteca
    duracao = 0;
    while (!(PINB & 16)>> 4);
    while ((PINB & 16)>> 4){duracao++;}

    //calibracao com o sensor
    if (duracao > 0){
    distancia = ((duracao * 0.00945) - 2);
    return distancia;
    }
  }
}