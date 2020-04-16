#include <stdio.h>
void noNegativo(); 

int main()
{
    noNegativo(); 

return 0; 
}

void noNegativo(){
    int value; 
    do{
        scanf ("%d", &value); 
    }while (value < 0); 
}