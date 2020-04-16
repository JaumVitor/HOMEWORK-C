//Os scanf
//nome na parte do cadastro

#include <stdio.h> 
#include <stdlib.h>
#include <conio.h> 
#include <locale.h>
#include <windows.h>
#include <string.h> 
#define MAX_C 100

	typedef struct {
		char nome[50]; 
		char cpf[12]; 
		char end[50]; 
		int telefone; 
		char email[50]; 
		int quant_contas; 
	}cliente;
	
	typedef struct {
		int numAgencia; 
		int numConta;
		float saldo; 
		char cpf[12]; 
	}conta; 

void buffer (void); //Faz a limpeza do buffer no progama
void systemLinha (void); //Salta um linha quando é chamada
void sublinhado (void); //Faz um traço pontilhado

void carregamento (void); //Animação de carregamento na tela do usuário
int validarCpf (int *pos, char auxCliente[], cliente listaCliente[]); 
int validarConta (int *cont, int numAgencia, int numConta, conta listaConta[]);
int return_id (int *pos, char auxCliente[], cliente listaCliente[]);
int return_id_conta (int *cont, int *numAgencia, int *numConta, conta listaConta[]);
		
void inf_Cliente (cliente listaCliente[], int *pos, int *cont);
void inf_Conta (cliente listaCliente[], conta listaConta[], int *pos, int *cont);

void menuAlt (int *esc); 
void menuPrincipal (int *esc); //Faz a exibição do menu principal e retorna uma opação escolhida pelo usuário
void menuCliente (int *esc1); //Faz uma exibição do menu cliente e retorna a opção escolhida 
void menuConta (int *esc);
void menuAltConta (int *esc); 

void CadastrarCliente (cliente listaCliente[MAX_C], int *pos, int *cont); 
void CadastrarConta(cliente listaCliente[MAX_C],conta listaConta[], int *pos, int *cont);
void AlterarCliente (cliente listaCliente[], int *pos); 
void AlterarConta (cliente listaCliente[MAX_C],conta listaConta[], int *pos, int *cont, int *numAgencia, int *numConta); 

int main (){
	setlocale (LC_ALL, "portuguese"); 
	cliente listaCliente[MAX_C]; //Lista de clientes do tipo (Clientes) 
	conta listaConta[MAX_C]; //Lista de contas 
	
	int pos=0; //Posição de controle do numero de clientes 
	int cont=0; //Quandidade de contas que estão sendo registradas 
	int esc; 
	
	//O progama so termina sua execução após digitar zero, no menuPrincipal 
	do{
		menuPrincipal (&esc);
		switch (esc){
		case 1: 
			system("cls"); inf_Cliente (listaCliente, &pos, &cont);	
			break ; 
		case 2:
			system("cls"); inf_Conta (listaCliente, listaConta, &pos, &cont);
			break ; 
		case 0: 
			break ; 
		default: 
			printf ("\nOPS, VALOR DIGITADO NÃO ESTA NO MENU :(\n\n"); 	
			system("pause"); system("cls"); 
		}
	}while (esc != 0); 
	
	return 0; 
}
//---------------------------------------------------------------------------------------------------------
/*						FUNÇÕS AUXILIARES: 
		CADA UMA DESSAS FUNÇÕES VAI AUXILIAR NO DESENVOLVIMENTO DO PROGAMA
		ALGUMAS, NÃO SÃO DE MUITA IMPORTACIA PARA O FUNCIONAMENTO DO SISTEMA       */ 
		
void subinhado(void){
	printf ("+===================================+\n");
}

void carregamento(void){
	Sleep(1000); printf ("."); Sleep(1000); printf ("."); Sleep(1000); printf (".");
}
void systemLinha (void){
	printf ("\n"); 
}

void buffer(void){
	char c; 
	while ((c = getchar()) != '\n' && c != EOF); 
}

int validarCpf (int *pos, char auxCliente[], cliente listaCliente[]){
	//Retorna 0; Se os valores de cpf forem iguais
	//Retorna 1; Se não existir cpf repetido
    int i; 
   	for (i=0; i<*pos; i++){
		if (strcmp (listaCliente[i].cpf, auxCliente) == 0){
	   	   	return 0;
		}
    }
	return 1;  
}

int validarConta (int *cont, int numAgencia, int numConta, conta listaConta[]){
	//Retorna 0; se tiver valores de contas iguais.....retorna 1; caso contrario
    int i; 
   	for (i=0; i<*cont; i++){
		if (listaConta[i].numAgencia == numAgencia && listaConta[i].numConta == numConta){
	   	   	return 0; 
		}
    }
	return 1; 
}

int return_id (int *pos, char auxCliente[], cliente listaCliente[]){
	//Retorna o indice, se existir cpf igual, nesse caso só funciona caso os valores da lista não se repetirem
    int i; 
   	for (i=0; i<*pos; i++){
		if (strcmp (listaCliente[i].cpf, auxCliente) == 0){
	   	   	return i;
		}
    } 
	return 0;  
}

int return_id_conta (int *cont, int *numAgencia, int *numConta, conta listaConta[]){
	//Retorna o indice, onde existe conta igual
    int i; 
   	for (i=0; i<*cont; i++){
		if (listaConta[i].numAgencia == *numAgencia && listaConta[i].numConta == *numConta){
	   	   	return i;
		}
    } 
	return 0;  
}
//-----------------------------------------------------------------------------------------------------------
/*						FUNÇÕES DE MENU: 
		CADA UMA DESSAS FUNÇÕES PRINTA NA TELA UM MENU COM OPÇÕE:
		PARAMETRO: PONTEIRO ESCOLHA
		PONTEIRO APONTA PARA VARIAVEL ESCOLHA, CRIADA ANTES DE CHAMAR A FUNÇÃO MENU 	*/ 

void menuPrincipal (int *esc){
	subinhado(); 
	printf ("\tMENU PRINCIPAL\n"); 
	printf ("-------------------------------------\n");
	printf ("1. CLIENTE\n2. CONTA\n3. MOVIMENTO\n4. RELATORIO\n0. SAIR\n"); 	
	subinhado(); 
	printf ("\t+ Digite sua escolha: "); 
	scanf ("%d", esc); 
}

void menuCliente (int *esc1){
		subinhado(); 
	 	printf ("\tMENU CLIENTE\n"); 
	   	printf ("-------------------------------------\n");
		printf ("1. CADASTRAR CLIENTE\n2. ALTERAR CLIENTE\n0. VOLTAR\n"); 	
		subinhado(); 
		printf ("\t> Qual opção? "); 
		scanf ("%d", esc1); 
}

void menuAlt(int *esc){
		subinhado(); 
	 	printf ("/Cadastrar Cliente > ALTERAR CLIENTE\n"); 
	   	printf ("-------------------------------------\n");
		printf ("1. NOME\n2. CPF\n3. ENDEREÇO\n4. TELEFONE\n5. EMAIL\n0. VOLTAR\n"); 
		subinhado(); 
		printf ("\t> Qual opção? "); 
		scanf ("%d", esc); 
}



void menuConta (int *esc){
		subinhado(); 
	 	printf ("\tMENU CONTA\n"); 
	   	printf ("-------------------------------------\n");
		printf ("1. CADASTRAR\n2. ALTERAR CONTA\n3. REMOVER CONTA\n0. VOLTAR\n"); 
		subinhado(); 
		printf ("\t> Qual opção? "); 
		scanf ("%d", esc); 
}

void menuAltConta (int *esc){
		subinhado(); 
	 	printf ("/Conta > ALTERAR CONTA\n"); 
	   	printf ("-------------------------------------\n");
		printf ("1. NUMERO AGENCIA\n2. NUMERO DA CONTA\n3. CPF\n0. VOLTAR\n"); 
		subinhado(); 
		printf ("\t> Qual opção? "); 
		scanf ("%d", esc); 
}
//--------------------------------------------------------------------------------------------------------
/*						FUNÇÕES PRINCIPAIS
		FUNÇÕES PRINCIPAIS SÃO AS QUE SERÃO ESCOLHIDAS DENTRO DO MENU PRINCIPAL	
		TEM A ACESSO PARA CHAMAR OUTRAS FUNÇÕES, CASO ELAS PRECISEM DE OUTRO MENU	
		PARAMETRO: struct listaCliente, int *pos									     	*/ 
				
void inf_Cliente (cliente listaCliente[], int *pos, int *cont ){ 
	int esc1; 
	do{
	 	system("cls"); menuCliente (&esc1); 
		switch (esc1){
		case 1: 
			system("cls"); CadastrarCliente(listaCliente, &*pos, &*cont); 
			break ; 
		case 2: 
			AlterarCliente (listaCliente, &*pos);
		case 0: 
			printf ("\n\tRETORNANDO");  //carregamento(); 
		    system("cls"); break ; 	 
		default: 
			printf ("\nOPS, VALOR DIGITADO NÃO ESTA NO MENU :(\n\n");  
			system("pause"); system("cls");
			break; 	
		}
	}while (esc1 != 0); 
}

void inf_Conta (cliente listaCliente[], conta listaConta[], int *pos, int *cont){ 
	int esc, numConta, numAgencia, retorno;
	 
	do{
	 	system("cls"); menuConta (&esc); 
		switch (esc){
		case 1: 
			system("cls"); CadastrarConta(listaCliente, listaConta, &*pos, &*cont); 
			break ; 
		case 2: 
			printf ("Digite sua angecia: "); //Variaveis axiliares, para verificação de validação
			scanf ("%d", &numAgencia);  
			printf ("Informe sua conta: ");
			scanf ("%d", &numConta); 
			retorno = validarConta (&*cont, numAgencia, numConta, listaConta);
			
			//Só vai ser chamada após a verificação, ou seja, retorno igual a zero
			printf ("\n\tVERIFICANDO EXISTENCIA DA SUA CONTA"); //carregamento(); 
			if (retorno == 0){
				system("cls"); AlterarConta (listaCliente, listaConta, &*cont, &*cont, &numAgencia, &numConta);	
			}else{
				printf ("\n\n\tConta ainda não cadastrada, para fazer alteraçãos\n"); system("pause"); 
			}
		 
			break; 
		case 0: 
			printf ("\n\tRETORNANDO");  //carregamento(); 
		    system("cls"); break ; 	 
		default: 
			printf ("\nOPS, VALOR DIGITADO NÃO ESTA NO MENU :(\n\n");  
			system("pause"); system("cls");
			break; 	
		}
	}while (esc != 0); 
}

//------------------------------------------------------------------------------------------------------------
void CadastrarCliente (cliente listaCliente[MAX_C], int *pos, int *cont){ //MENU PRINCIPAL > CADASTRAR
	int retorno; char auxCliente[50]; 
	
	subinhado(); printf ("CADASTRAMENTO DO USUÁRIO NO SISTEMA\n"); subinhado(); 
	printf ("\nDIGITE O CPF: "); 
	scanf ("%s", auxCliente); 
	buffer(); 
	
	retorno = validarCpf (&*pos, auxCliente, listaCliente );   //Antes de registrar cpf tem que fazer a verifiação
	printf ("\nVERIFICANDO"); //carregamento(); 
	
	if (retorno != 0){
		strcpy(listaCliente[*pos].cpf, auxCliente); 
		++(*pos); 
		
		printf ("|SALVANDO SEU CPF\n"); //carregamento(); systemLinha(); 
		/*
		printf ("\nDigite seu Nome: "); 
		scanf ("%s", listaCliente[*pos].nome); buffer(); 
		printf ("Endereço: "); 
		scanf ("%s", listaCliente[*pos].end); buffer(); 
		printf ("Telefone: "); 
		scanf("%d", &listaCliente[*pos].telefone); buffer();  
		printf ("Email: "); 
		scanf ("%s", listaCliente[*pos].email); buffer(); 
		*/
		systemLinha(); 
	}else{
		printf ("|CPF JA ESTÁ REGISTRADO, TENTE NOVAMENTE\n\n"); system("pause");  
	} 
}

void CadastrarConta (cliente listaCliente[MAX_C], conta listaConta[], int *pos, int *cont){ //MENU PRINCIPAL > CADASTRAR
	int retorno, numAgencia, numConta, id, retorno_val;
    char cpf[12]; 
	
	subinhado(); printf ("   CRIANDO CONTA NO SISTEMA\n"); 
	printf ("-------------------------------------\n");
	
	printf ("%s", listaCliente[0].nome); 
	printf ("\n>> CPF PARA ACESSAR SEU CADASTRO: "); 
	scanf ("%s",cpf); buffer(); 
	//Preciso verificar se o cpf existe, dentro dos cadastrados
	//Assim, ele só vai criar uma conta caso o cliente ja tiver sido cadastrado
	retorno = validarCpf (&*pos, cpf, listaCliente );   
	printf ("\nVERIFICANDO"); //carregamento(); 
	
	if (retorno == 0){
		printf ("\n<#> ENCONTRAMOS SEU CPF NOS REGISTROS <#>\n"); system ("pause");  
		
	   	printf ("\n>> Número da Agencia: "); 
		scanf ("%d", &numAgencia ); buffer(); 
		printf (">> Número da conta: "); 
		scanf ("%d", &numConta); buffer(); 
		
		//O par precisa ser novo, ou seja não aceita valores ja cadastrados
		retorno_val = validarConta (&*cont, numAgencia, numConta, listaConta);  
		if (retorno_val != 0){ 
			//Não existem valores iguais
			//ADICIONA VALORES APRENAS SE O PAR FOR VÁLIDO
			listaConta[*cont].numAgencia = numAgencia ; 
	   	   	listaConta[*cont].numConta = numConta ; 
	   		strcpy(listaConta[*cont].cpf, cpf); 
	   		
	   	   	printf (">> Saldo: "); 
			scanf("%f", &listaConta[*cont].saldo); buffer();  
			systemLinha();
			
			id = return_id (&*pos, cpf, listaCliente); //Retornar indice da posição de onte o cpf esta cadastrado
			(listaCliente[id].quant_contas)++; //Quandidade de contas vai incrementando a cada nova conta registrada 
	   	   	(*cont)++; 
	   	   	
			printf ("\nUSUÁRIO DO CPF [%s] > NUMERO DE CONTAS: %d\n", listaCliente[id].cpf, listaCliente[id].quant_contas);
		}else
			printf ("\nCONTA JÁ CADASTRADA!");
	}else
		printf ("\n<#> ESTE CPF AINDA NÃO FOI REGISTRADO <#>\n\n"); system ("pause"); 
}

void AlterarCliente(cliente listaCliente[], int *pos){ //MENU PRINCIPAL > ALTERAR CLIENTE
	int esc, retorno, id; char cpf[12], cpfAntigo[12]; 
	
	printf ("\nDigite o CPF para verificação: "); 
	scanf ("%s", cpf); 
	
	retorno = validarCpf (&*pos, cpf, listaCliente); //Não necessáriamente preciso passar pos com (&*)
	
	if (retorno == 0){ //Só vai conseguir alterar os dados do cliente se o cpf for válido na hora da verificação 
    	printf ("\n\t[ ENCONTRAMOS SEU CPF NO SISTEMA! ]\n\n"); system("pause");
		id = return_id (&*pos, cpf, listaCliente); //Retornar indice de onde esta armazenado o cpf 
		
		do{
		 	system("cls"); menuAlt (&esc); 
			switch (esc){
				case 1: 
					printf ("\nALTERE SEU NOME: "); 
					scanf ("%s", listaCliente[id].nome); 
					break ; 
				case 2: 
					//Precisa fazer a verificação antes de fazer alteração do cpf
					printf ("\nALTERE SEU CPF: "); 
					scanf ("%s", cpf);
					retorno = validarCpf (&*pos, cpf, listaCliente);
					strcpy(cpfAntigo,listaCliente[id].cpf); //Atribuindo antigo cpf, mas so vai ser printado quando valor for atualizado
					 
					if (retorno == 0){
						printf ("\t<#> ESTE CPF ESTA SENDO UTILIZADO!<#>\n"); system("pause");
					}else{
						strcpy(listaCliente[id].cpf, cpf); //Alterando cpf, quando os valores do novo não esta registrado
						printf ("\t<#>     SEU CPF FOI ATUALIZADO    <#>\n");
	   	   	   	   	   	printf ("\t<#> Antes era [%s] | agora é [%s] <#>\n\n", cpfAntigo, listaCliente[id].cpf);  
						system("pause");
					} 
					break; 
				case 3: 
					printf ("\nALTERE SEU ENDEREÇO: "); 
					scanf ("%s", listaCliente[id].end);
					break; 
				case 4: 
					printf ("\nALTERE SEU TELEFONE: "); 
					scanf ("%d", &listaCliente[id].telefone);
					break; 
				case 5: 
					printf ("\nALTERE SEU EMAIL: "); 
					scanf ("%s", listaCliente[id].email);
					break; 
				case 0: 
		   	   	   break ; 	 
				default: 
					printf ("\nOPS, VALOR DIGITADO NÃO ESTA NO MENU :(\n\n");  
					system("pause"); system("cls");
					break; 	
			}
		}while (esc != 0); 
		
	}else{
		printf ("\n\t[ CPF NÃO CADASTRADO ]\n"); system("pause"); 
	}
}

void AlterarConta (cliente listaCliente[MAX_C],conta listaConta[], int *pos, int *cont, int *numAgencia, int *numConta){
	int esc, id;
	id = return_id_conta (&*cont, &*numAgencia, &*numConta, listaConta); 
	//Se esta nesta função, é pq os pares ja não são repetidos, então podemos retornar o id_conta
	do{
	 	system("cls"); menuAltConta (&esc); 
		switch (esc){
			//Antes de fazer as atruições, é necessário verificar se os valores novos, podem ser registrados
			//Nova conta e nova agencia juntamente com o novo cpf, devem ser divergentes dos ja existentes
			case 1: 
				printf (">> INFORME NOVA AGÊNCIA:"); 
				scanf ("%d", &listaConta[id].numAgencia);
				system("pause"); 
				break ; 
			case 2: 
				printf (">> INFORME NOVO Nº CONTA:"); 
				scanf ("%d", &listaConta[id].numConta);
				system("pause"); 
				break ; 
			case 3: 
				printf (">> INFORME NOVO CPF:"); //precisa alterar dados, para novo num de cpf
				scanf ("%s", listaConta[id].cpf);
				system("pause");  
				break ; 
			case 0: 
				printf ("\n\tRETORNANDO");  //carregamento(); 
			    system("cls"); break ; 	 
			default: 
				printf ("\nOPS, VALOR DIGITADO NÃO ESTA NO MENU :(\n\n");  
				system("pause"); system("cls");
			break; 	
		}
	}while (esc != 0); 
}

#include <stdio.h> 
#include <stdlib.h>
#include <conio.h> 
#include <locale.h>
#include <windows.h>
#include <string.h> 

#define MAX_C 100#include <stdio.h> 
#include <stdlib.h>
#include <conio.h> 
#include <locale.h>
#include <windows.h>
#include <string.h> 
#define MAX_C 100

	typedef struct {
		char nome[50]; 
		char cpf[12]; 
		char end[50]; 
		int telefone; 
		char email[50]; 
		int quant_contas; 
	}cliente; 

void buffer (void); //Faz a limpeza do buffer no progama
void systemLinha (void); //Salta um linha quando é chamada
void sublinhado (void); //Faz um traço pontilhado
void carregamento (void); //Animação de carregamento na tela do usuário
int validarCpf (int *pos, char auxCliente[], cliente listaCliente[]); 
void inf_Cliente (cliente listaCliente[], int *pos);

void menuAlt (int *esc); 
void menuPrincipal (int *esc); //Faz a exibição do menu principal e retorna uma opação escolhida pelo usuário
void menuCliente (int *esc1); //Faz uma exibição do menu cliente e retorna a opção escolhida 

void CadastrarCliente (cliente listaCliente[MAX_C], int *pos); 
void AlterarCliente (cliente listaCliente[], int *pos); 

int main (){
	setlocale (LC_ALL, "portuguese"); 
	cliente listaCliente[MAX_C]; //Lista de clientes do tipo (Clientes) 
	int pos=0; //Posição de controle do numero de clientes 
	int esc; 
	
	//O progama so termina sua execução após digitar zero, no menuPrincipal 
	do{
		menuPrincipal (&esc);
		switch (esc){
		case 1: 
			system("cls"); inf_Cliente (listaCliente, &pos);	
			break ; 
		case 0: 
			break ; 
		default: 
			printf ("\nOPS, VALOR DIGITADO NÃO ESTA NO MENU :(\n\n"); 	
			system("pause"); system("cls"); 
		}
	}while (esc != 0); 
	
	return 0; 
}
//---------------------------------------------------------------------------------------------------------
/*						FUNÇÕS AUXILIARES: 
		CADA UMA DESSAS FUNÇÕES VAI AUXILIAR NO DESENVOLVIMENTO DO PROGAMA
		ALGUMAS, NÃO SÃO DE MUITA IMPORTACIA PARA O FUNCIONAMENTO DO SISTEMA       */ 
		
void subinhado(void){
	printf ("+===================================+\n");
}

void carregamento(void){
	Sleep(1000); printf ("."); Sleep(1000); printf ("."); Sleep(1000); printf (".");
}
void systemLinha (void){
	printf ("\n"); 
}

void buffer(void){
	char c; 
	while ((c = getchar()) != '\n' && c != EOF); 
}

int validarCpf (int *pos, char auxCliente[], cliente listaCliente[]){
    int i; 
   	for (i=0; i<*pos; i++){
		if (strcmp (listaCliente[i].cpf, auxCliente) == 0){
	   	   	return 0;
		}
    }
	return 1;  
}

int return_id (int *pos, char auxCliente[], cliente listaCliente[]){
    int i; 
   	for (i=0; i<*pos; i++){
		if (strcmp (listaCliente[i].cpf, auxCliente) == 0){
	   	   	return i;
		}
    } 
	return 0;  
}
//-----------------------------------------------------------------------------------------------------------
/*						FUNÇÕES DE MENU: 
		CADA UMA DESSAS FUNÇÕES PRINTA NA TELA UM MENU COM OPÇÕE:
		PARAMETRO: PONTEIRO ESCOLHA
		PONTEIRO APONTA PARA VARIAVEL ESCOLHA, CRIADA ANTES DE CHAMAR A FUNÇÃO MENU 	*/ 

void menuPrincipal (int *esc){
	subinhado(); 
	printf ("\tMENU PRINCIPAL\n"); 
	printf ("-------------------------------------\n");
	printf ("1. CLIENTE\n2. CONTA\n3. MOVIMENTO\n4. RELATORIO\n0. SAIR\n"); 	
	subinhado(); 
	printf ("\t+ Digite sua escolha: "); 
	scanf ("%d", esc); 
}

void menuCliente (int *esc1){
		subinhado(); 
	 	printf ("\tMENU CLIENTE\n"); 
	   	printf ("-------------------------------------\n");
		printf ("1. CADASTRAR CLIENTE\n2. ALTERAR CLIENTE\n0. VOLTAR\n"); 	
		subinhado(); 
		printf ("\t> Qual opção? "); 
		scanf ("%d", esc1); 
}

void menuAlt(int *esc){
		subinhado(); 
	 	printf ("/Cadastrar Cliente > ALTERAR CLIENTE\n"); 
	   	printf ("-------------------------------------\n");
		printf ("1. NOME\n2. CPF\n3. ENDEREÇO\n4. TELEFONE\n5. EMAIL\n0. VOLTAR\n"); 
		subinhado(); 
		printf ("\t> Qual opção? "); 
		scanf ("%d", esc); 
}

//--------------------------------------------------------------------------------------------------------
/*						FUNÇÕES PRINCIPAIS
		FUNÇÕES PRINCIPAIS SÃO AS QUE SERÃO ESCOLHIDAS DENTRO DO MENU PRINCIPAL	
		TEM A ACESSO PARA CHAMAR OUTRAS FUNÇÕES, CASO ELAS PRECISEM DE OUTRO MENU	
		PARAMETRO: struct listaCliente, int *pos									     	*/ 
				
void inf_Cliente (cliente listaCliente[], int *pos){ 
	int esc1; 
	do{
	 	system("cls"); menuCliente (&esc1); 
		switch (esc1){
		case 1: 
			system("cls"); CadastrarCliente(listaCliente, &*pos); 
			break ; 
		case 2: 
			AlterarCliente (listaCliente, &*pos);
		case 0: 
			printf ("\n\tRETORNANDO");  //carregamento(); 
		    system("cls"); break ; 	 
		default: 
			printf ("\nOPS, VALOR DIGITADO NÃO ESTA NO MENU :(\n\n");  
			system("pause"); system("cls");
			break; 	
		}
	}while (esc1 != 0); 
}
//------------------------------------------------------------------------------------------------------------
void CadastrarCliente (cliente listaCliente[MAX_C], int *pos){ //MENU PRINCIPAL > CADASTRAR
	int retorno; char auxCliente[50]; 
	
	subinhado(); printf ("CADASTRAMENTO DO USUÁRIO NO SISTEMA\n"); subinhado(); 
	printf ("DIGITE O CPF: "); 
	scanf ("%s", auxCliente); 
	buffer(); 
	
	retorno = validarCpf (&*pos, auxCliente, listaCliente );   //Antes de registrar cpf tem que fazer a verifiação
	printf ("\nVERIFICANDO"); //carregamento(); 
	
	if (retorno != 0){
		strcpy(listaCliente[*pos].cpf, auxCliente); 
		++(*pos); 
		
		printf ("|SALVANDO SEU CPF"); //carregamento(); systemLinha(); 
		
		printf ("\nDigite seu Nome: "); 
		scanf ("%s", listaCliente[*pos].nome); buffer(); 
		printf ("Endereço: "); 
		scanf ("%s", listaCliente[*pos].end); buffer(); 
		printf ("Telefone: "); 
		scanf("%d", &listaCliente[*pos].telefone); buffer();  
		printf ("Email: "); 
		scanf ("%s", listaCliente[*pos].email); buffer(); 
		printf ("Quantidade de contas: "); 
		scanf("%d", &listaCliente[*pos].quant_contas); buffer(); 
		systemLinha(); 
	}else
		 printf ("|CPF JA ESTÁ REGISTRADO, TENTE NOVAMENTE\n\n"); system("pause");  
}

void AlterarCliente(cliente listaCliente[], int *pos){ //MENU PRINCIPAL > ALTERAR CLIENTE
	int esc, retorno, id; char cpf[12], cpfAntigo[12]; 
	
	printf ("\nDigite o CPF para verificação: "); 
	scanf ("%s", cpf); 
	
	retorno = validarCpf (&*pos, cpf, listaCliente); //Não necessáriamente preciso passar pos com (&*)
	
	if (retorno == 0){ //Só vai conseguir alterar os dados do cliente se o cpf for válido na hora da verificação 
    	printf ("\n\t[ ENCONTRAMOS SEU CPF NO SISTEMA! ]\n\n"); system("pause");
		id = return_id (&*pos, cpf, listaCliente); //Retornar indice de onde esta armazenado o cpf 
		
		do{
		 	system("cls"); menuAlt (&esc); 
			switch (esc){
				case 1: 
					printf ("\nALTERE SEU NOME: "); 
					scanf ("%s", listaCliente[id].nome); 
					break ; 
				case 2: 
					//Precisa fazer a verificação antes de fazer alteração do cpf
					printf ("\nALTERE SEU CPF: "); 
					scanf ("%s", cpf);
					retorno = validarCpf (&*pos, cpf, listaCliente);
					strcpy(cpfAntigo,listaCliente[id].cpf); //Atribuindo antigo cpf, mas so vai ser printado quando valor for atualizado
					 
					if (retorno == 0){
						printf ("\t<#> ESTE CPF ESTA SENDO UTILIZADO!<#>\n"); system("pause");
					}else{
						strcpy(listaCliente[id].cpf, cpf); //Alterando cpf, quando os valores do novo não esta registrado
						printf ("\t<#>     SEU CPF FOI ATUALIZADO    <#>\n");
	   	   	   	   	   	printf ("\t<#> Antes era [%s] | agora é [%s] <#>\n\n", cpfAntigo, listaCliente[id].cpf);  
						system("pause");
					} 
					break; 
				case 3: 
					printf ("\nALTERE SEU ENDEREÇO: "); 
					scanf ("%s", listaCliente[id].end);
					break; 
				case 4: 
					printf ("\nALTERE SEU TELEFONE: "); 
					scanf ("%d", &listaCliente[id].telefone);
					break; 
				case 5: 
					printf ("\nALTERE SEU EMAIL: "); 
					scanf ("%s", listaCliente[id].email);
					break; 
				case 0: 
		   	   	   break ; 	 
				default: 
					printf ("\nOPS, VALOR DIGITADO NÃO ESTA NO MENU :(\n\n");  
					system("pause"); system("cls");
					break; 	
			}
		}while (esc != 0); 
		
	}else{
		printf ("\n\t[ CPF NÃO CADASTRADO ]\n"); system("pause"); 
	}
	
}



 
//Estrutura para os clientes 
	typedef struct {
		char nome[50]; 
		char cpf[12]; 
		char end[50]; 
		int telefone; 
		char email[50]; 
		int quant_contas; 
	}cliente; 

void buffer (void); //Faz a limpeza do buffer no progama
void systemLinha (void); //Salta um linha quando é chamada
void sublinhado (void); //Faz um traço pontilhado
void carregamento (void); //Animação de carregamento na tela do usuário

void menuAlt (int *esc); 
void menuPrincipal (int *esc); //Faz a exibição do menu principal e retorna uma opação escolhida pelo usuário
void menuCliente (int *esc1); //Faz uma exibição do menu cliente e retorna a opção escolhida 

int validarCpf (int *pos, char auxCliente[], cliente listaCliente[]); 

void inf_Cliente (cliente listaCliente[], int *pos);
void CadastrarCliente (cliente listaCliente[MAX_C], int *pos); 
void AlterarCliente (cliente listaCliente[], int *pos); 

int main (){
	setlocale (LC_ALL, "portuguese"); 
	cliente listaCliente[MAX_C]; //Lista de clientes do tipo (Clientes) 
	int pos=0; //Posição de controle do numero de clientes 
	int esc; 
	
	//O progama so termina sua execução após digitar zero, no menuPrincipal 
	do{
		menuPrincipal (&esc);
		switch (esc){
		case 1: 
			system("cls"); inf_Cliente (listaCliente, &pos);	
			break ; 
		case 0: 
			break ; 
		default: 
			printf ("\nOPS, VALOR DIGITADO NÃO ESTA NO MENU :(\n\n"); 	
			system("pause"); system("cls"); 
		}
	}while (esc != 0); 
	
	return 0; 
}

//Funções auxiliares: 
void subinhado(void){
	printf ("+===================================+\n");
}

void carregamento(void){
	Sleep(1000); printf ("."); Sleep(1000); printf ("."); Sleep(1000); printf (".");
}

void menuPrincipal (int *esc){
	subinhado(); 
	printf ("\tMENU PRINCIPAL\n"); 
	printf ("-------------------------------------\n");
	printf ("1. CLIENTE\n2. CONTA\n3. MOVIMENTO\n4. RELATORIO\n0. SAIR\n"); 	
	subinhado(); 
	printf ("\t+ Digite sua escolha: "); 
	scanf ("%d", esc); 
}

void menuCliente (int *esc1){
		subinhado(); 
	 	printf ("\tMENU CLIENTE\n"); 
	   	printf ("-------------------------------------\n");
		printf ("1. CADASTRAR CLIENTE\n2. ALTERAR CLIENTE\n0. VOLTAR\n"); 	
		subinhado(); 
		printf ("\t> Qual opção? "); 
		scanf ("%d", esc1); 
}

void menuAlt(int *esc){
		subinhado(); 
	 	printf ("/Cadastrar Cliente > ALTERAR CLIENTE\n"); 
	   	printf ("-------------------------------------\n");
		printf ("1. NOME\n2. CPF\n3. ENDEREÇO\n4. TELEFONE\n5. EMAIL\n0. VOLTAR\n"); 
		subinhado(); 
		printf ("\t> Qual opção? "); 
		scanf ("%d", esc); 
}

int validarCpf (int *pos, char auxCliente[], cliente listaCliente[]){
    int i; 
   	for (i=0; i<*pos; i++){
		if (strcmp (listaCliente[i].cpf, auxCliente) == 0){
	   	   	return 0;
		}
    }
	return 1;  
}

int return_id (int *pos, char auxCliente[], cliente listaCliente[]){
    int i; 
   	for (i=0; i<*pos; i++){
		if (strcmp (listaCliente[i].cpf, auxCliente) == 0){
	   	   	return i;
		}
    } 
	return 0;  
}
void systemLinha (void){
	printf ("\n"); 
}

void buffer(void){
	char c; 
	while ((c = getchar()) != '\n' && c != EOF); 
}

//Funções principais: 
void inf_Cliente (cliente listaCliente[], int *pos){
	int esc1; 
	do{
	 	system("cls"); menuCliente (&esc1); 
		switch (esc1){
		case 1: 
			system("cls"); CadastrarCliente(listaCliente, &*pos); 
			break ; 
		case 2: 
			AlterarCliente (listaCliente, &*pos);
		case 0: 
			printf ("\n\tRETORNANDO");  //carregamento(); 
		    system("cls"); break ; 	 
		default: 
			printf ("\nOPS, VALOR DIGITADO NÃO ESTA NO MENU :(\n\n");  
			system("pause"); system("cls");
			break; 	
		}
	}while (esc1 != 0); 
}

void CadastrarCliente (cliente listaCliente[MAX_C], int *pos){ //Castrar clientes no banco
	int retorno; char auxCliente[50]; 
	
	subinhado(); printf ("CADASTRAMENTO DO USUÁRIO NO SISTEMA\n"); subinhado(); 
	printf ("DIGITE O CPF: "); 
	scanf ("%s", auxCliente); 
	buffer(); 
	
	retorno = validarCpf (&*pos, auxCliente, listaCliente );   //Antes de registrar cpf tem que fazer a verifiação
	printf ("\nVERIFICANDO"); //carregamento(); 
	
	if (retorno != 0){
		strcpy(listaCliente[*pos].cpf, auxCliente); 
		++(*pos); 
		
		printf ("|SALVANDO SEU CPF"); //carregamento(); systemLinha(); 
		
		printf ("\nDigite seu Nome: "); 
		scanf ("%s", listaCliente[*pos].nome); buffer(); 
		printf ("Endereço: "); 
		scanf ("%s", listaCliente[*pos].end); buffer(); 
		printf ("Telefone: "); 
		scanf("%d", &listaCliente[*pos].telefone); buffer();  
		printf ("Email: "); 
		scanf ("%s", listaCliente[*pos].email); buffer(); 
		printf ("Quantidade de contas: "); 
		scanf("%d", &listaCliente[*pos].quant_contas); buffer(); 
		systemLinha(); 
	}else
		 printf ("|CPF JA ESTÁ REGISTRADO, TENTE NOVAMENTE\n\n"); system("pause");  
}

void AlterarCliente(cliente listaCliente[], int *pos){
	int esc, retorno, id; char cpf[12], cpfAntigo[12]; 
	
	printf ("\nDigite o CPF para verificação: "); 
	scanf ("%s", cpf); 
	
	retorno = validarCpf (&*pos, cpf, listaCliente); //Não necessáriamente preciso passar pos com (&*)
	
	if (retorno == 0){ //Só vai conseguir alterar os dados do cliente se o cpf for válido na hora da verificação 
    	printf ("\n\t[ ENCONTRAMOS SEU CPF NO SISTEMA! ]\n\n"); system("pause");
		id = return_id (&*pos, cpf, listaCliente); //Retornar indice de onde esta armazenado o cpf 
		
		do{
		 	system("cls"); menuAlt (&esc); 
			switch (esc){
				case 1: 
					printf ("\nALTERE SEU NOME: "); 
					scanf ("%s", listaCliente[id].nome); 
					break ; 
				case 2: 
					//Precisa fazer a verificação antes de fazer alteração do cpf
					printf ("\nALTERE SEU CPF: "); 
					scanf ("%s", cpf);
					retorno = validarCpf (&*pos, cpf, listaCliente);
					strcpy(cpfAntigo,listaCliente[id].cpf); //Atribuindo antigo cpf, mas so vai ser printado quando valor for atualizado
					 
					if (retorno == 0){
						printf ("\t<#> ESTE CPF ESTA SENDO UTILIZADO!<#>\n"); system("pause");
					}else{
						strcpy(listaCliente[id].cpf, cpf); //Alterando cpf, quando os valores do novo não esta registrado
						printf ("\t<#>     SEU CPF FOI ATUALIZADO    <#>\n");
	   	   	   	   	   	printf ("\t<#> Antes era [%s] | agora é [%s] <#>\n", cpfAntigo, listaCliente[id].cpf);  
						system("pause");
					} 
					break; 
				case 3: 
					printf ("\nALTERE SEU ENDEREÇO: "); 
					scanf ("%s", listaCliente[id].end);
					break; 
				case 4: 
					printf ("\nALTERE SEU TELEFONE: "); 
					scanf ("%d", &listaCliente[id].telefone);
					break; 
				case 5: 
					printf ("\nALTERE SEU EMAIL: "); 
					scanf ("%s", listaCliente[id].email);
					break; 
				case 0: 
		   	   	   break ; 	 
				default: 
					printf ("\nOPS, VALOR DIGITADO NÃO ESTA NO MENU :(\n\n");  
					system("pause"); system("cls");
					break; 	
			}
		}while (esc != 0); 
		
	}else{
		printf ("\n\t[ CPF NÃO CADASTRADO ]\n"); system("pause"); 
	}
	
}


