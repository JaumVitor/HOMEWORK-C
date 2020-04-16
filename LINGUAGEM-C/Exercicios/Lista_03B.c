#include <stdio.h>

int main()
{
    float grausF, celcius;

    printf("\nDigite uma temperatura em Faharnheit (T-F): ");
    scanf("%f", &grausF);

    celcius = (float)5 / 9 * (grausF - 32);

    printf("O valor de (T-F) em Celcius E: %.2f\n\n", celcius);
    return 0;
}