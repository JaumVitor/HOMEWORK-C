#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

void menu(int *esc); //Exibir meu de opções
void esc1_implementar(float *reg); //Adiona valor em registradora, (usando ponteiros)
void esc2_verificar(float *reg); //Verifica os valores armazenados em registradora 
void esc3_retirar(float *reg); //retirar uma quantia de registradores

void systemLinha(void); //Salta linha
void valorPositivo( float *validade);

int main(){
	int escolha; //Escolha opção, esta sendo implementada dentro da função
	float registradora; //Vai armazenar valor que o usuário tem registrado
	
	setlocale (LC_ALL,"portuguese");
	
	do{
		menu(&escolha);	
		switch (escolha){
			case 1:
				esc1_implementar(&registradora);
				system("pause");
				system("cls"); break;
			case 2: 
				esc2_verificar(&registradora);
				system("pause");
				system("cls"); break;	
			case 3: 
				esc3_retirar(&registradora);
				system("pause");
				system("cls"); break;	
			case 0:
				printf ("Obrigado por usar nossos serviços! Volte sempre!\n");
				break;	
		
			default: //Caso o usuário não informe nunhum valor, dos casos, uma mensagem divilgada
				system("cls");
				printf ("<$>ERRO, Digite um valor mencionado no MENU!\n\n");			
		}
	}while (escolha != 0);
	
	return 0;
}

void menu(int *esc){
	printf ("-=-=-= MENU DE OPÇÕES =-==-=-\n"
	"[1] INSERIR DINHERO\n"
	"[2] VERIFICAR CAIXA\n"
	"[3] RETIRAR DINHEIRO\n"
	"[0]ENCERRAR VERIFICAÇÃO\n"
	"-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	
	printf ("> Digite o a opção: ");
	scanf ("%d", esc);
	systemLinha();
}

void esc1_implementar(float *reg){
	float v;
	printf (">> Digite a quantidade que vai ser IMPLEMENTADA R$ ");
	valorPositivo(&v); //ler somente valores positivos
	*reg += v;	 	
	printf ("\t<#> Seu saldo atual é de R$%.2f\n\n", *reg );
}

void esc2_verificar(float *reg){
	printf ("\t<#>A caixa registradora posssui %.2f\n\n", *reg);
}

void esc3_retirar(float *reg){
	float v2; //Preciso da variavel fora da função, para receber valor que vai ser validado dentro dela 
	printf (">> Digite a quantidade que vai ser RETIRADA R$ ");
	valorPositivo(&v2);
	
	if (v2 > *reg){
		printf ("\n\t<$>ERRO, SALDO DA CAIXA REGISTRADORA INSUFICIENTE! ");
	}
	else{
		*reg -= v2; //retirando valor do registro 
	   	printf ("\t<#> valor RETIRADO com sucesso!\n");
	   	printf ("\t<#> Seu saldo atual é de %f\n", *reg);
	} 	
}

//Parte de funções auxiliares abaixo!
void valorPositivo( float *value){
	float validade; 
	
	scanf ("%f", &validade); //Lendo o valor na variavel aux, e dps que estiver ok passa pro ponteiro 
	if (validade < 0){
		printf ("Erro, valor negativo!\n");
		do{
			printf (">INFORME UM VALOR ADEQUADO: ");
			scanf ("%f", &validade);
		}while (validade < 0);
	}
	printf ("\t<#> valor armazenado com sucesso!\n");
	*value = validade; //Usando uma variavel auxiliadora
}

void systemLinha(){ //Função para utilizar como flexibilidade 
	printf ("\n");
}