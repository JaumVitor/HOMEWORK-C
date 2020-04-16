#include <stdio.h>
#include <ctype.h> 

int main(){
    char letra; 

    printf ("Informe a letra: ");
    scanf ("%c", &letra);
    printf ("A letra que voce digitou em maiuscula e: %c", toupper(letra));
    return 0 ;
}