#include <stdio.h>

int main(){
    float hora, convert_min;

    printf ("Informe as horas: "); 
    scanf ("%f", &hora); 

    convert_min = hora * 60; 
    printf ("Horas convertidas em minutos: %.f min", convert_min); 
    
    return 0; 
}