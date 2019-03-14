#include<avr/io.h>
#include<util/delay.h>
#include"infravermelho.h"
#include"movimento.h"
#include"ultrasom.h"

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