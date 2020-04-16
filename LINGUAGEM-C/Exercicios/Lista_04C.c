#include <stdio.h> 

int main(){
    int ang1, ang2, ang3;

    printf ("ANGULO 1: ");
    scanf ("%d", &ang1);
    printf ("ANGULO 2: ");
    scanf ("%d",&ang2);
    printf ("ANGULO 3: ");
    scanf ("%d", &ang3); 

    if (ang1 == 90 || ang2 == 90 || ang3 == 90){
        printf ("TRIANGULO RETANGULO!\n");
    }
    if (ang1 > 90 || ang2 > 90 || ang3 > 90){
        printf ("TRIANGULO OBTUSO!\n");
    }
    if (ang1 < 90 && ang2 < 90 && ang3 < 90){
        printf ("TRIANGULO ACUTANGULO!\n");
    }
    return 0; 
}