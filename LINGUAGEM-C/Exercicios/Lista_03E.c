#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <ctype.h> 

int main() 
{
    setlocale(LC_ALL,"Portuguese"); 
    float dim1, dim2, area, powt; //dim --> Dimenção  powt --> Potência

    printf ("\nInforme as duas dimensoes em metro: ");
    scanf ("%f%f", &dim1, &dim2); 

    area = dim1 * dim2 ;
    powt = area * 18;

    printf ("A potência de iluminação é %.2fW\n", powt);

    return 0; 
}