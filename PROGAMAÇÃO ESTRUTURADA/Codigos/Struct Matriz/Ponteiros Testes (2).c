#include <stdio.h> 
	typedef struct{
		int horas; 
		int minutos; 
	}STR; 
	
	STR tempo; //Criado uma variavel tempo do tipo STR; 
	STR *tempo_ponteiro = &tempo; //Criando um ponteiro que vai apontar para um tipo struct tempo; Atribuição foi feita direta
	//Ja passei automaticamente o endereço para onde o ponteiro vai apontar na hora da declaração; 
	
int main (){
	tempo.horas = 20; 
	//tempo_ponteiro = &tempo;   //Colocando um valor para 
	
	//printf ("Retorno do ponteiro: %d\n", (*tempo_ponteiro).horas); //Quando eu tiver um ponteiro sendo passado como uma struct
	printf ("Retorno do ponteiro: %d\n", tempo_ponteiro->horas);  //Mesma coisa do que estar em cima; 
	printf ("Retorno da variavel: %d", tempo.horas); 
	
	return 0; 
}
/*
obs: Explicação sobre ponteiros no ---> Ponteiros Testes.c

1- Primeiro eu crio uma struct
2- Declaro uma variavel do tipo STR tempo; 
3- Tmb crio um ponteiro do que vai apontar para um endereço do tipo STR Tempo; 
4- Quando eu faço tempo.horas = 20; Estou declarando um valor para STR(Horas); 

OBS- Esse valor que foi atribuido para (tempo.horas = 20) é o valor da variavel (tempo.horas); 
Quando eu crio o ponteiro, na hora em que eu alterar o valor no ponteiro, deve mudar na variavel; 

5-  STR *tempo_ponteiro;      -----> Ponteiro que aponta para um tipo STR; 
	tempo_ponteiro = &tempo;  -----> Passando o endereço, para onde o ponteiro vai apontar; 
	 
	ou  STR *tempo_ponteiro = &tempo;   
*/