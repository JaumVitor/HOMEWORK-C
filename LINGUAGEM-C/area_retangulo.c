#include <stdio.h>

int main(){
    //exercicio para calcular area

    //Variaveis
    float base, altura, area;

    printf ("Digite a base: ");
    scanf ("%f", &base); 
    printf ("Digite a altura: ");
    scanf ("%f", &altura); 

    area = base * altura;

    printf ("A area referente aos dados: %.2f cm",area); 

    return 0; 
}
