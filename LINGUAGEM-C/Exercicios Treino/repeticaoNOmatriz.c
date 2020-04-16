#include <stdio.h> 
#define MAXL 3
#define MAXC 2

int main(){
	int v[MAXL][MAXC]; 
	int x,i,k,y, aux, repeat=0; 
	
	for (i=0; i<MAXL; i++){
		for (x=0; x<MAXC; x++){
			printf ("Digite o valor [lin %d] [col %d] ",i+1, x+1 ); 
			scanf ("%d", &v[i][x]); 
		}
	}
	
	for (i=0; i<MAXL; i++){
		for (x=0; x<MAXC; x++){
			printf ("%d ", v[i][x]); 
		}printf ("\n"); 
	}
	
	for (i=0; i<MAXL; i++){
		for (x=0; x<MAXC; x++){
			aux = v[i][x]; 
			for  (k=0; k<MAXL; k++){
				for (y=0; y<MAXC; y++){
					printf ("aux %d, %d = vetor1 %d, %d\n", i, x, k, y); 
					if (aux == v[k][y]){
						printf ("%d = %d\n", aux,v[k][y] ); 
						repeat++ ; 
					} 
				}
			}
		}
	}
	printf ("%d",repeat - MAXL * MAXC ); 
	return 0; 
}