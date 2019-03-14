#include <avr/io.h>
#include <util/delay.h>

float dist(void){
    const int trigger = 13;
    const int echo = 12;
    unsigned long duracao = 0;
    float distancia;
    DDRB = 0b11101111;
    Serial.begin(9600);
    Serial.println("Sensor de Ultrasom:\n");
    
    while (1){
        PORTB = 0b00000000; //Trigger
        delayMicroseconds(2);
        PORTB = 0b00100000;
        delayMicroseconds(10);
        PORTB = 0b00000000;
        duracao = 0; //detectar eco
        while (!(PINB & 16) >> 4);
        while ((PINB & 16) >> 4){duracao++;}
        if (duracao > 0){
            distancia = ((duracao * 0.00945) - 2); //calibracao com sensor
            Serial.println(distancia);
            return distancia;
        }
    }
}