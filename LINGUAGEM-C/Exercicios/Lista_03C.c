#include <stdio.h>

int main()
{
    float gorjeta, custo_cliente;

    printf("\n----------------------------------------\n");
    printf ("Digite valor de consumo do cliente R$."); 
    scanf ("%f", &custo_cliente);

    gorjeta = 0.10 * custo_cliente; //Garsom recebe 10% 

    printf ("Retribuicao ao garsom = R$%.2f", gorjeta);
    printf("\n----------------------------------------\n");

    return 0;
}