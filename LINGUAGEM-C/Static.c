#include <stdio.h>

#define constante 0

void funcao() {
    int variavel = constante; // se colocasse 0 aqui daria na mesma
    static int estatica = constante;
    variavel++;
    estatica++;
    printf("variavel = %d, estatica = %d\n", variavel, estatica);
    return; 
}

int i; 
int main(){
    for (i = 0; i < 10; ++i) {
        funcao();
    }
    return 0; 
}