#include <stdio.h> 
//#include <locale.h>  Locale buga a aproximação dos nuemros 

int main() {
	//setlocale (LC_ALL, "Portuguese"); 
	
	double nota1, nota2, nota3, media;
	char conceito, key='T'; 
	
	printf ("Digite a primeira nota: ");
	scanf ("%lf",&nota1);
	printf ("Digite a segunda nota: ");
	scanf ("%lf",&nota2);
	printf ("Digite a terceira nota: ");
	scanf ("%lf",&nota3);
	
	if ((nota1 >= 0 && nota1 <= 10) && (nota2 >= 0 && nota2 <= 10) && (nota3 >= 0 && nota3 <= 10)){
		media = (nota1 + nota2*2 + nota3)/4;
		
		if (media >= 9)
			conceito = 'A'; 
		else if (media >= 7.5 && media < 9)
			conceito = 'B'; 
		else if (media >= 6 && media < 7.5)
			conceito = 'C'; 
		else if (media >= 4 && media < 6)
			conceito = 'D'; 
		else if (media < 4)
			conceito = 'E'; 
	}else{
		printf ("Erro: A uma das notas não está adequada\n");
		key = 'F';  //Chave para validação da meida, se ela for "T" = True, então ela vai ser printada
	} 				//Caso contrario não será printada na tela 

	if (key == 'T')
		printf ("MÉDIA > %.1lf\nCONCEITO > %c\n", media,conceito);
	 
	// finalização do progama
	if (conceito == 'A' || conceito == 'B' || conceito == 'C')
		printf ("O aluno esta APROVADO!");
	else 
		printf ("O aluno esta REPROVADO!");
	
	printf ("\n"); //ESTEICA DO PROGAMA 
	
	return 0;  
}