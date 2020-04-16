//Calculo dos volumes
#include <stdio.h>
#include <math.h>
#define PI 3.14

int main()
{
    float raio, altura, vol1, vol2, vol3; 
    //vol1 -> esfera, vol2 -> cone, vol3 -> cilindro;

    printf("----------------------------\n");
    printf ("Informe o raio: "); 
    scanf ("%f",&raio); 
    printf ("Digite a altura: "); 
    scanf ("%f", &altura);
    printf ("----------------------------\n");

    vol1 = (4 * PI * pow(raio,3)) / 3; 
    vol2 = (PI * pow(raio,2) * altura) / 3; 
    vol3 = (PI * pow(raio,2) * altura); 

    printf ("VOLUME DOS OBJETOS:\nESFERA: %f\nCONE: %f\nCilindro: %f",vol1, vol2, vol3);
    printf("\n----------------------------\n\n");

    return 0;
}