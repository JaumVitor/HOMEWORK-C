#include <stdio.h> 

int main(){
    char rsp; 

    printf ("Qual o gabarito ? ");
    scanf ("%c", &rsp); 

    if ((rsp == 'a') || (rsp == 'b') || (rsp == 'c') || (rsp == 'd') || (rsp == 'e')){
        printf ("RESPOSTA VALIDA!");
    }
    if (!(rsp == 'a') && !(rsp == 'b') && !(rsp == 'c') && !(rsp == 'd') && !(rsp == 'e')){
        printf ("RESPOSTA INVALIDA!");
    }
    return 0;  
}