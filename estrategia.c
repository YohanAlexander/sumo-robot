#include<avr/io.h>
#include<util/delay.h>
#include"motor.h"
#include"infra.h"
#include"ultra.h"

int main(void){

    while(1){

        if(infra() == 6){
            tras();
            esquerda();
            parar();
        }

        if(infra() == 7){
            frente();
            parar();
        }

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

        if(dist() < 15 && infra() == 0){
            frente();
            parar();
                }
            }
        }    
    }
}