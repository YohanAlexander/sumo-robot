#include<avr/io.h>
#include<util/delay.h>

void direita(void){  
  PORTD = 0b00101000; //direita 1010
  _delay_ms(500);
}

void esquerda(void){ 
  PORTD = 0b00010100; //esquerda 0101
  _delay_ms(500);
}

void frente(void){ 
  PORTD = 0b00100100; //frente 1001
  _delay_ms(500);
}

void tras(void){
  PORTD = 0b00011000; //tras 0110
  _delay_ms(500);
}

void parar(void){
  PORTD = 0b00000000; //parar
  _delay_ms(500);
}

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

int main(void){
    while(1){
        //Charge
        if(dist() < 15 && infra() == 0){
            frente();
            parar();
        }
        //Limitação Infra
        if(infra() == 6){
            tras();
            esquerda();
            parar();
        }
        if(infra() == 7){
            frente();
            parar();
        }
        //Procurar
        if(dist() > 15){
            parar();
            esquerda();
            parar();
            if(dist() > 15){
                direita();
                direita();
                parar();
                if(dist() > 15){
                    esquerda();
                    parar();
                }
            }
        }    
    }
}