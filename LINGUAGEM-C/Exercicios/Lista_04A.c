#include <stdio.h>

int main(){
    double altura, peso; 

    printf ("Digite o peso: ");
    scanf ("%lf", &peso);
    printf ("Informe a altura: ");
    scanf ("%lf", &altura);

    if ((peso >= 100 && peso <= 200) || (altura >= 1.9 && altura <= 3)){
        printf ("CANDIDATO ACEITO!");
    }  
    if (!(peso >= 100 && peso <= 200) && !(altura >= 1.9 && altura <= 3)){
        printf("CANDIDATO INVALIDO!");
    }  
    return 0; 
}