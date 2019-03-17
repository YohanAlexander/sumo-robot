#include<avr/io.h>
#include<util/delay.h>

const int trigPin = 13;
const int echoPin = 12;

int direita(void){
  DDRD = 0b00111100;  
  PORTD = 0b00101000; //direita 1010
  _delay_ms(500);
}

int esquerda(void){
  DDRD = 0b00111100;  
  PORTD = 0b00010100; //esquerda 0101
  _delay_ms(500);
}

int frente(void){
  DDRD = 0b00111100;
  PORTD = 0b00100100; //frente 1001
  _delay_ms(500);
}

int tras(void){
  DDRD = 0b00111100;
  PORTD = 0b00011000; //tras 0110
  _delay_ms(500);
}

int parar(void){
  DDRD = 0b00111100;
  PORTD = 0b00000000; //parar
  _delay_ms(500);
}

float dist(void){

  unsigned long duracao = 0;
  float distancia;
  DDRB = 0b11101111;
  Serial.begin(9600);
  //Serial.println("Sensor Ultrasom");

  while (1){

    // Trigger
    PORTB = 0b00000000;  
    delayMicroseconds(2);   
    PORTB = 0b00100000;  
    delayMicroseconds(10);   
    PORTB = 0b00000000; 

    // detectar eco sem uso de biblioteca
    duracao = 0;
    while (!(PINB & 16)>> 4);
    while ((PINB & 16)>> 4){duracao++;}   

    if (duracao > 0){
    //Serial.println(duracao);  
    distancia = ((duracao * 0.00945) - 2); //calibracao com sensor
    //Serial.println(distancia);
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
  //Serial.println(pino6, DEC); //Imprime o valor do pino6 em decimal
  //Serial.println(pino7, DEC); //Imprime o valor do pino7 em decimal

  if (pino6 == 1 && pino7 == 1){PORTD = 0b11000011; return 1;}
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