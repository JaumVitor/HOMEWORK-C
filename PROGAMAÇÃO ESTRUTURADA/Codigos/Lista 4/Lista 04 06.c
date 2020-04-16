#include <stdio.h> 

int main(){
	float nota; 
	int quant, aluno= 1, i, soma= 0; 
	
	printf ("Quantos alunos pertecem a turma ? "); 
	scanf ("%d", &quant); 
	printf ("\n"); 
	
	for ( i=0; i<quant; i++ ){
		printf (">Nota do aluno %d: ", aluno); 
		scanf ("%f", &nota); 
		
			if ( nota > 10 || nota < 0){
				do{
					printf ("\t >>Erro: Digite a (0 <= nota <= 10)  ALUNO-%d: ", aluno); 
					scanf ("%f", &nota); 
				}while ( nota > 10 || nota < 0); 
			}

		aluno ++;
		if ( nota >= 7 )
			soma++; 
	}
	if ( soma == quant){
		printf ("%d Alunos obtveram nota acima de 7", soma); 
	}else
		printf ("Apenas %d alunos obtveram nota acima de 7", soma); 
	
	return 0; 
}