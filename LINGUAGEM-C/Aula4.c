#include <stdio.h>

/*  > int: armazena valores numéricos inteiros.
    > char: armazena caracteres.
    > float: armazena números com ponto flutuante (reais) com precisão simples.
    > double: armazena números com ponto flutuante, com precisão dupla, ou seja 
    normalmente possui o dobro da capacidade de uma variável do tipo float. */

int main (){
    /*Tipos de representções: 
        int   --> %d ou %i
        float --> %f
        char  --> %c
        char[] -> %s 
        double -> %lf
        
        %u Modulo de um numero
        %p Endereço de memoria 
        %e ou %E Para imprimir um numero em notação cientifica 
        %% para imprimir uma unica porcentagem*/ 

    int num_int = 34, n1 = -342; 
    float num_float =3.554;


    printf ("Um numero inteiro qualquer %i %u \n", num_int, n1);
    printf ("Um numero flutuante qualquer %.2f \n", num_float);

    return 0; 
}