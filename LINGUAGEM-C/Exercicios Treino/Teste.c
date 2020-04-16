#include <stdio.h>

int main (){
	int *x, y; 
	
	x = &y;
	y = 19; 
	printf ("%d %d", *x, y);
	return 0;
}