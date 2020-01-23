#include<avr/io.h>
#include<util/delay.h>
#include"motor.c"
#include"infra.c"
#include"ultra.c"

int main(void){

    while(1){

        if(dist() < 40 && infra() == 0){
            frente();
            frente();
            tras();
        }

        if(infra() == 7){
            tras();
            esquerda();
            parar();
        }

        if(infra() == 6){
            frente();
            parar();
        }

        else if(dist() > 20){
            parar();
            esquerda();
            parar();

            if(infra() == 7){
            tras();
            esquerda();
            parar();
            }

            if(infra() == 6){
                frente();
                parar();
            }

            if(dist() > 20){

                if(infra() == 7){
                    tras();
                    esquerda();
                    parar();
                }

                if(infra() == 6){
                    frente();
                    parar();
                }

                direita();
                direita();
                parar();

            if(dist() > 20){

                if(infra() == 7){
                    tras();
                    esquerda();
                    parar();
                }

                if(infra() == 6){
                    frente();
                    parar();
                }

                esquerda();
                parar();
                }
            }
        }
    }
}