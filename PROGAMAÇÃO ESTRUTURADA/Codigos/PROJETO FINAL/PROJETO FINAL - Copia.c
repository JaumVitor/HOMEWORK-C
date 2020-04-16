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
void systemLinha (void); //Salta um linha quando � chamada
void sublinhado (void); //Faz um tra�o pontilhado

void carregamento (void); //Anima��o de carregamento na tela do usu�rio
int validarCpf (int *pos, char auxCliente[], cliente listaCliente[]); 
int validarCpfConta (int *cont, char cpf[], conta listaConta[]);
int validarConta (int *cont, int numAgencia, int numConta, conta listaConta[]);
int validarContaAgencia (int *cont, int numAgencia, conta listaConta[]);

int return_id (int *pos, char auxCliente[], cliente listaCliente[]);
int return_id_conta (int *cont, int *numAgencia, int *numConta, conta listaConta[]);
int return_id_conta_cpf (int *cont, char cpf[], conta listaConta[]);
int return_id_conta_Ag (int *cont, int numAgencia, conta listaConta[]);
		
void inf_Cliente (cliente listaCliente[], int *pos, int *cont);
void inf_Conta (cliente listaCliente[], conta listaConta[], int *pos, int *cont);
void inf_Relatorio (cliente listaCliente[], conta listaConta[], int *pos, int *cont, FILE *salvar, FILE *salvar1, FILE *salvar2, FILE *salvar3); 
void inf_Movimento(conta listaConta[], int *cont);

void menuAlt (int *esc); 
void menuPrincipal (int *esc); //Faz a exibi��o do menu principal e retorna uma opa��o escolhida pelo usu�rio
void menuCliente (int *esc); //Faz uma exibi��o do menu cliente e retorna a op��o escolhida 
void menuConta (int *esc);
void menuAltConta (int *esc); 
void menuRelatorio (int *esc);
void menuMovimento (int *esc); 
void menuValorEsp(int *esc, float valorAnalise);
void menuSalvar(int *esc1);

void CadastrarCliente (cliente listaCliente[MAX_C], int *pos, int *cont); 
void CadastrarConta(cliente listaCliente[MAX_C],conta listaConta[], int *pos, int *cont);
void AlterarCliente (cliente listaCliente[], int *pos); 
void AlterarConta (cliente listaCliente[MAX_C],conta listaConta[], int *pos, int *cont, int *numAgencia, int *numConta); 
void RemoverConta (int *cont, int *pos, conta listaConta[], cliente listaCliente[], int id); 
void SaldoConta (int *cont, conta listaConta[]);
void Depositar(conta listaConta[],int *cont); 
void Saque (conta listaConta[],int *cont);
void Tranferencia (conta listaConta[],int *cont);
void Listar1 (conta listaConta[], cliente listaCliente[], int *cont, int *pos);
void Listar2 (conta listaConta[], cliente listaCliente[], int *cont, int *pos, FILE *salvar);
void Listar3 (cliente listaCliente[], int *pos, FILE *salvar1); //listar todos Cliente
void Listar4 (conta listaConta[], cliente listaCliente[], int *cont, int *pos, FILE *salvar2); //listar todas as contas 
void Listar5 (conta listaConta[], cliente listaCliente[], int *cont, int *pos, FILE *salvar3);
void Listar6 (conta listaConta[], cliente listaCliente[], int *cont, int *pos);

int main (){
	setlocale (LC_ALL, "portuguese"); 
	cliente listaCliente[MAX_C]; //Lista de clientes do tipo (Clientes) 
	conta listaConta[MAX_C]; //Lista de contas 
	
	FILE *salvar; //Salvar alquivos da Listar2
	salvar = fopen("arquivoFunc11.txt", "w");
	
	FILE *salvar1; //Listar3
	salvar1 = fopen("arquivoFunc12.txt", "w");
	
	FILE *salvar2; //Listar4
	salvar2 = fopen("arquivoFunc13.txt", "w");
	
	FILE *salvar3; //Listar5
	salvar3 = fopen("arquivoFunc14.txt", "w");
	
	int pos=0; //Posi��o de controle do numero de clientes 
	int cont=0; //Quandidade de contas que est�o sendo registradas 
	int esc; 
	
	//O progama so termina sua execu��o ap�s digitar zero, no menuPrincipal 
	do{
		menuPrincipal (&esc);
		switch (esc){
		case 1: 
			system("cls"); inf_Cliente (listaCliente, &pos, &cont);	
			break ; 
		case 2:
			system("cls"); inf_Conta (listaCliente, listaConta, &pos, &cont);
			break ; 
		case 3: 
			system("cls"); inf_Movimento (listaConta, &cont);
			break ; 
		case 4: 
			system("cls"); inf_Relatorio (listaCliente, listaConta, &pos, &cont, &*salvar, &*salvar1, &*salvar2, &*salvar3);
			break ; 
		case 0: 
			break ; 
		default: 
			printf ("\nOPS, VALOR DIGITADO N�O ESTA NO MENU :(\n\n"); 	
			system("pause"); system("cls"); 
		}
	}while (esc != 0); 
	
	return 0; 
}
//---------------------------------------------------------------------------------------------------------
/*						FUN��S AUXILIARES: 
		CADA UMA DESSAS FUN��ES VAI AUXILIAR NO DESENVOLVIMENTO DO PROGAMA
		ALGUMAS, N�O S�O DE MUITA IMPORTACIA PARA O FUNCIONAMENTO DO SISTEMA       */ 
		
void subinhado(void){
	printf ("+===================================+\n");
}

void carregamento(void){
	Sleep(500); printf ("."); Sleep(500); printf ("."); Sleep(500); printf (".");
}
void systemLinha (void){
	printf ("\n"); 
}

void buffer(void){
	char c; 
	while ((c = getchar()) != '\n' && c != EOF); 
}

int validarCpf (int *pos, char auxCliente[], cliente listaCliente[]){ //Valida o cpf do cliente
	//Retorna 0; Se os valores de cpf forem iguais
	//Retorna 1; Se n�o existir cpf repetido
    int i; 
   	for (i=0; i<*pos; i++){
		if (strcmp (listaCliente[i].cpf, auxCliente) == 0){
	   	   	return 0;
		}
    }
	return 1;  
}

int validarCpfConta (int *cont, char cpf[], conta listaConta[]){ //Valida o cpf da conta do cliente 
	//N�o poderia ser a msm da fun��o cpf pq as structs s�o diferentes
	//Retorna 0; Se os valores de cpf forem iguais
	//Retorna 1; Se n�o existir cpf repetido
    int i; 
   	for (i=0; i<*cont; i++){
		if (strcmp (listaConta[i].cpf, cpf) == 0){
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

int validarContaAgencia (int *cont, int numAgencia, conta listaConta[]){
	//Retorna 0; se tiver valores de contas iguais.....retorna 1; caso contrario
    int i; 
   	for (i=0; i< *cont; i++){
		if (listaConta[i].numAgencia == numAgencia ){
	   	   	return 0; 
		}
    }
	return 1; 
}

int return_id (int *pos, char auxCliente[], cliente listaCliente[]){ 
	//RETORNA INDICE DO CLIENTE RECEBENDO CPF
	//Retorna o indice, se existir cpf igual, nesse caso s� funciona caso os valores da lista n�o se repetirem
    int i; 
   	for (i=0; i<*pos; i++){
		if (strcmp (listaCliente[i].cpf, auxCliente) == 0){
	   	   	return i;
		}
    } 
	return 0;  
}

int return_id_conta (int *cont, int *numAgencia, int *numConta, conta listaConta[]){ 
	//RETORNA O INDICE DA CONTA RECEBENDO AGENCIA E CONTA
	//Retorna o indice, onde existe conta igual
    int i; 
   	for (i=0; i<*cont; i++){
		if (listaConta[i].numAgencia == *numAgencia && listaConta[i].numConta == *numConta){
	   	   	return i;
		}
    } 
	return 0;  
}

int return_id_conta_cpf (int *cont, char cpf[], conta listaConta[]){ 
	//RETORNA O INDICE DA CONTA RECEBENDO CPF
	//Retorna o indice, onde existe conta igual
    int i; 
   	for (i=0; i<*cont; i++){
		if ( strcmp (listaConta[i].cpf, cpf) == 0){
	   	   	return i;
		}
    } 
	return 0;  
}

int return_id_conta_Ag (int *cont, int numAgencia, conta listaConta[]){
	//RETORNA O INDICE DA CONTA RECEBENDO AGENCIA
	//Retorna o indice, onde existe valor igual
    int i; 
   	for (i=0; i<*cont; i++){
		if ( listaConta[i].numAgencia == numAgencia ){
	   	   	return i;
		}
    } 
	return 0;  
}
//-----------------------------------------------------------------------------------------------------------
/*						FUN��ES DE MENU: 
		CADA UMA DESSAS FUN��ES PRINTA NA TELA UM MENU COM OP��E:
		PARAMETRO: PONTEIRO ESCOLHA
		PONTEIRO APONTA PARA VARIAVEL ESCOLHA, CRIADA ANTES DE CHAMAR A FUN��O MENU 	*/ 

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
		printf ("\t> Qual op��o? "); 
		scanf ("%d", esc1); 
}

void menuAlt(int *esc){
		subinhado(); 
	 	printf ("/Cadastrar Cliente > ALTERAR CLIENTE\n"); 
	   	printf ("-------------------------------------\n");
		printf ("1. NOME\n2. CPF\n3. ENDERE�O\n4. TELEFONE\n5. EMAIL\n0. VOLTAR\n"); 
		subinhado(); 
		printf ("\t> Qual op��o? "); 
		scanf ("%d", esc); 
}

void menuAgencia_Conta(int *numAgencia, int *numConta){
	printf ("\nINFORME OS OS DADOS PARA VERIFICA��O: \n"); 
	printf ("\n>> Digite o n�mero da Ag�ncia: ");
	scanf("%d",numAgencia);
	printf (">> Digite o n�mero da conta: ");
	scanf ("%d",numConta);
}

void menuConta (int *esc){
		subinhado(); 
	 	printf ("\tMENU CONTA\n"); 
	   	printf ("-------------------------------------\n");
		printf ("1. CADASTRAR\n2. ALTERAR CONTA\n3. REMOVER CONTA\n0. VOLTAR\n"); 
		subinhado(); 
		printf ("\t> Qual op��o? "); 
		scanf ("%d", esc); 
}

void menuAltConta (int *esc){
		subinhado(); 
	 	printf ("/Conta > ALTERAR CONTA\n"); 
	   	printf ("-------------------------------------\n");
		printf ("1. NUMERO AGENCIA\n2. NUMERO DA CONTA\n3. CPF\n0. VOLTAR\n"); 
		subinhado(); 
		printf ("\t> Qual op��o? "); 
		scanf ("%d", esc); 
}

void menuMovimento(int *esc){
		subinhado(); 
	 	printf ("\tMENU MOVIMENTO\n"); 
	   	printf ("-------------------------------------\n");
		printf ("1. VERIFICAR SALDO\n2. DEPOSITAR VALOR\n3. SAQUE\n4. TRANSFER�NCIA\n0. VOLTAR\n"); 
		subinhado(); 
		printf ("\t> Qual op��o? "); 
		scanf ("%d", esc); 
}

void menuRelatorio (int *esc){
		subinhado(); 
	 	printf ("\tMENU RELAT�RIO (LISTAGEM)\n"); 
	   	printf ("-------------------------------------\n");
		printf (
		"1.      VER CONTAS CORRENTES\n\n"
		"2.      DADOS DE TODAS AS CONTAS\n" 
		"	      (VALOR ESP)\n\n"
		"3. DADOS CADRASTRAIS DE TODOS CLIENTES\n\n"
		"4.   INFORMA��ES DE TODAS AS CONTAS\n" 
		"	 (COM NOME E CPF)\n\n"
		"5.   INFORMA��ES DE TODOS OS CLIENTES\n" 
		"	  (CONTAS E CADASTRO)\n\n"
		"6. DADOS CADASTRAIS DE CLIENTES p/AGEN\n"
		"	 (ORDENADOS PELO CPF)\n\n"
		"0. 		VOLTAR\n"); 
		subinhado(); 
		printf ("\t    > Qual op��o? "); 
		scanf ("%d", esc); 
}

void menuValorEsp(int *esc, float valorAnalise){
		subinhado(); 
	 	printf ("\tESCOLHA VALOR MAIOR, MENOR OU IGUAL\n"); 
	 	printf ("\tVALOR SOLICITADO: %.2f\n", valorAnalise); 
	   	printf ("-------------------------------------\n");
		printf ("1 ) MAIOR\n0 ) VALOR IGUAL\n-1) MENOR\n"); 
		subinhado(); 
		printf ("\tQual a op��o ? "); 
		scanf ("%d", esc); 
}

void menuSalvar(int *esc){
   	printf ("\n>>Deseja salvar esses Dados ?\n\t[1]-Sim [0]-N�o: "); 	
	scanf ("%d", &*esc ); 
}
//--------------------------------------------------------------------------------------------------------
/*						FUN��ES PRINCIPAIS
		FUN��ES PRINCIPAIS S�O AS QUE SER�O ESCOLHIDAS DENTRO DO MENU PRINCIPAL	
		TEM A ACESSO PARA CHAMAR OUTRAS FUN��ES, CASO ELAS PRECISEM DE OUTRO MENU	
		PARAMETRO: struct listaCliente, int *pos									     	*/ 
				
void inf_Cliente (cliente listaCliente[], int *pos, int *cont ){ 
	int esc;
	
	do{
	 	system("cls"); menuCliente (&esc); 
		switch (esc){
		case 1: 
			system("cls"); CadastrarCliente(listaCliente, &*pos, &*cont); 
			break ; 
		case 2: 
			AlterarCliente (listaCliente, &*pos);
		case 0: 
			printf ("\n\tRETORNANDO");  //carregamento(); 
		    system("cls"); break ; 	 
		default: 
			printf ("\nOPS, VALOR DIGITADO N�O ESTA NO MENU :(\n\n");  
			system("pause"); system("cls");
			break; 	
		}
	}while (esc != 0); 
}

void inf_Conta (cliente listaCliente[], conta listaConta[], int *pos, int *cont){ 
	int esc, retorno, id;
	int numConta, numAgencia; //Variaveis axiliares, para verifica��o de valida��o
	
	do{
	 	system("cls"); menuConta (&esc); 
		switch (esc){
		case 1: //Cadastrar conta do cliente
			system("cls"); CadastrarConta(listaCliente, listaConta, &*pos, &*cont); 
			break ; 
		case 2: //Alterar conta dos clientes
			printf ("\n>Digite sua angecia: "); 
			scanf ("%d", &numAgencia);  
			printf (">Informe sua conta: ");
			scanf ("%d", &numConta); 
			retorno = validarConta (&*cont, numAgencia, numConta, listaConta);
			
			//S� vai ser chamada ap�s a verifica��o, ou seja, retorno igual a zero
			printf ("\n\tVERIFICANDO EXISTENCIA DA SUA CONTA"); //carregamento(); 
			if (retorno == 0){
				system("cls"); AlterarConta (listaCliente, listaConta, &*cont, &*cont, &numAgencia, &numConta);	
			}else{
				printf ("\n\tCONTA AINDA N�O REGISTRADA\n\tPARA FAZER ALTERA��ES\n\n"); system("pause"); 
			}
			break; 
		
		case 3: //Remover conta, deixando n�o alterando os valores da lista cliente
			printf ("\n>Digite sua angecia: ");
			scanf ("%d", &numAgencia);  
			printf (">Informe sua conta: ");
			scanf ("%d", &numConta); 
			retorno = validarConta(&*cont, numAgencia, numConta, listaConta);
			
			printf ("\n\tVERIFICANDO EXISTENCIA DA SUA CONTA"); //carregamento(); 
			printf ("FAZENDO CANCELAMENTO DA CONTA"); //carregamento(); 	
			if (retorno == 0){
				id = return_id_conta (&*cont, &numAgencia, &numConta, listaConta); 
				RemoverConta (&*cont, &*pos, listaConta, listaCliente, id);
			}else 
				printf ("\n\n\tCONTA AINDA N�O REGISTRADA\n\t  N�O � POSSIVEL REMOVER\n\n"); system("pause"); 
		case 0: 
			printf ("\n\tRETORNANDO");  //carregamento(); 
		    system("cls"); break ; 	 
		default: 
			printf ("\nOPS, VALOR DIGITADO N�O ESTA NO MENU :(\n\n");  
			system("pause"); system("cls");
			break; 	
		}
	}while (esc != 0); 
}

void inf_Movimento(conta listaConta[], int *cont){
	int esc; 
	do{
	 	system("cls"); menuMovimento (&esc); 
		switch (esc){
		case 1: 
			SaldoConta (&*cont, listaConta); 
			break ; 
		case 2: 
			Depositar(listaConta, &*cont); 
			break ; 
		case 3: 
			Saque (listaConta, &*cont); 
		 	break;
		case 4: 
			Tranferencia (listaConta, &*cont); 
			break;
		case 0:
			printf ("\n\tRETORNANDO");  //carregamento(); 
		    system("cls"); break;
		default: 
			printf ("\nOPS, VALOR DIGITADO N�O ESTA NO MENU :(\n\n");  
			system("pause"); system("cls");
			break; 	
		}
	}while (esc != 0); 
}

void inf_Relatorio (cliente listaCliente[], conta listaConta[], int *pos, int *cont, FILE *salvar, FILE *salvar1, FILE *salvar2, FILE *salvar3){
	int esc; 
	do{
	 	system("cls"); menuRelatorio (&esc); 
		switch (esc){
		case 1: 
			system("cls"); Listar1 (listaConta, listaCliente, &*cont, &*pos); system("pause"); 
			break ; 
		case 2:
			Listar2 (listaConta, listaCliente, &*cont, &*pos, &*salvar); system("pause"); 
			break; 
		case 3: 
			Listar3 (listaCliente, &*pos, salvar1); system("pause"); 
			break; 
		case 4: 
			Listar4 (listaConta, listaCliente, &*cont, &*pos, &*salvar2); system("pause"); 
			break; 
		case 5: 
			Listar5 (listaConta, listaCliente, &*cont, &*pos, &*salvar3); system("pause"); 
			break; 
		case 6: 
			Listar6 (listaConta, listaCliente, &*cont, &*pos); system("pause"); 
			break; 
		case 0: 
			printf ("\n\tRETORNANDO");  carregamento(); 
		    system("cls"); break ; 	 
		default: 
			printf ("\nOPS, VALOR DIGITADO N�O ESTA NO MENU :(\n\n");  
			system("pause"); system("cls");
			break; 	
		}
	}while (esc != 0); 
}


//------------------------------------------------------------------------------------------------------------
void CadastrarCliente (cliente listaCliente[MAX_C], int *pos, int *cont){ //MENU PRINCIPAL > CADASTRAR
	int retorno; char auxCliente[50]; 
	
	subinhado(); printf ("CADASTRAMENTO DO USU�RIO NO SISTEMA\n"); 
	printf ("-------------------------------------\n"); 
	printf ("\nDIGITE O CPF: "); 
	scanf ("%s", auxCliente); 
	buffer(); 
	
	retorno = validarCpf (&*pos, auxCliente, listaCliente );   //Antes de registrar cpf tem que fazer a verifia��o
	printf ("\nVERIFICANDO"); carregamento(); 
	
	if (retorno != 0){
		strcpy(listaCliente[*pos].cpf, auxCliente); 

		printf ("\n\nDigite seu Nome: "); 
		scanf ("%s", listaCliente[*pos].nome); buffer(); 
		printf ("Endere�o: "); 
		scanf ("%s", listaCliente[*pos].end); buffer(); 
		printf ("Telefone: "); 
		scanf("%d", &listaCliente[*pos].telefone); buffer();  
		printf ("Email: "); 
		scanf ("%s", listaCliente[*pos].email); buffer(); 
		listaCliente[*pos].quant_contas = 0; 
		++(*pos); 
		systemLinha(); 
	}else{
		printf ("| CPF JA EST� REGISTRADO, TENTE NOVAMENTE\n\n"); system("pause");  
	}  
}

void CadastrarConta (cliente listaCliente[MAX_C], conta listaConta[], int *pos, int *cont){ //MENU PRINCIPAL > CADASTRAR
	int retorno, numAgencia, numConta, id, retorno_val;
    char cpf[12]; 
	
	subinhado(); printf ("   CRIANDO CONTA NO SISTEMA\n"); 
	printf ("-------------------------------------\n");
	
	printf ("\n>> CPF PARA ACESSAR SEU CADASTRO: "); 
	scanf ("%s",cpf); buffer(); 
	//Preciso verificar se o cpf existe, dentro dos cadastrados
	//Assim, ele s� vai criar uma conta caso o cliente ja tiver sido cadastrado
	retorno = validarCpf (&*pos, cpf, listaCliente );   
	printf ("\nVERIFICANDO"); carregamento(); 
	
	if (retorno == 0){
		printf ("\n\n<#> ENCONTRAMOS SEU CPF NOS REGISTROS <#>\n\n"); system ("pause");  
		
	   	printf ("\n>> N�mero da Agencia: "); 
		scanf ("%d", &numAgencia ); buffer(); 
		printf (">> N�mero da conta: "); 
		scanf ("%d", &numConta); buffer(); 
		
		//O par precisa ser novo, ou seja n�o aceita valores ja cadastrados
		retorno_val = validarConta (&*cont, numAgencia, numConta, listaConta);  
		if (retorno_val != 0){ 
			//N�o existem valores iguais
			//ADICIONA VALORES APRENAS SE O PAR FOR V�LIDO
			listaConta[*cont].numAgencia = numAgencia ; 
	   	   	listaConta[*cont].numConta = numConta ; 
	   		strcpy(listaConta[*cont].cpf, cpf); 
	   		
	   	   	printf (">> SALDO INICIAL DA CONTA R$ "); 
			scanf("%f", &listaConta[*cont].saldo); buffer();  
			systemLinha();
			
			id = return_id (&*pos, cpf, listaCliente); //Retornar indice da posi��o de onte o cpf esta cadastrado
			(listaCliente[id].quant_contas)++; //Quandidade de contas vai incrementando a cada nova conta registrada 
	   	   	(*cont)++; 
	   	   	
			printf (">>USU�RIO: %s\n>>CONTAS: %d\n", listaCliente[id].nome, listaCliente[id].quant_contas);
		}else
			printf ("\nCONTA J� CADASTRADA!");
	}else
		printf ("\n<#> ESTE CPF AINDA N�O FOI REGISTRADO <#>\n\n"); system ("pause"); 
}

void AlterarCliente(cliente listaCliente[], int *pos){ //MENU PRINCIPAL > ALTERAR CLIENTE
	int esc, retorno, id; char cpf[12], cpfAntigo[12]; 
	
	printf ("\nDigite o CPF para verifica��o: "); 
	scanf ("%s", cpf); 
	
	retorno = validarCpf (&*pos, cpf, listaCliente); //N�o necess�riamente preciso passar pos com (&*)
	
	if (retorno == 0){ //S� vai conseguir alterar os dados do cliente se o cpf for v�lido na hora da verifica��o 
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
					//Precisa fazer a verifica��o antes de fazer altera��o do cpf
					printf ("\nALTERE SEU CPF: "); 
					scanf ("%s", cpf);
					retorno = validarCpf (&*pos, cpf, listaCliente);
					strcpy(cpfAntigo,listaCliente[id].cpf); //Atribuindo antigo cpf, mas so vai ser printado quando valor for atualizado
					 
					if (retorno == 0){
						printf ("\t<#> ESTE CPF ESTA SENDO UTILIZADO!<#>\n"); system("pause");
					}else{
						strcpy(listaCliente[id].cpf, cpf); //Alterando cpf, quando os valores do novo n�o esta registrado
						printf ("\t<#>     SEU CPF FOI ATUALIZADO    <#>\n");
	   	   	   	   	   	printf ("\t<#> Antes era [%s] | agora � [%s] <#>\n\n", cpfAntigo, listaCliente[id].cpf);  
						system("pause");
					} 
					break; 
				case 3: 
					printf ("\nALTERE SEU ENDERE�O: "); 
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
					printf ("\nOPS, VALOR DIGITADO N�O ESTA NO MENU :(\n\n");  
					system("pause"); system("cls");
					break; 	
			}
		}while (esc != 0); 
		
	}else{
		printf ("\n\t[ CPF N�O CADASTRADO ]\n"); system("pause"); 
	}
}

void AlterarConta (cliente listaCliente[MAX_C],conta listaConta[], int *pos, int *cont, int *numAgencia, int *numConta){
	int esc, id, idCpf, auxAgencia, auxConta;
	int retornoAlt, retornoValCpf;
	char cpf[12]; 
	
	id = return_id_conta (&*cont, &*numAgencia, &*numConta, listaConta); 
	//Se esta nesta fun��o, � pq os pares ja n�o s�o repetidos, ent�o podemos retornar o id_conta
	do{
	 	system("cls"); menuAltConta (&esc); 
		switch (esc){
			//Antes de fazer as atrui��es, � necess�rio verificar se os valores novos, podem ser registrados
			//Nova conta e nova agencia juntamente com o novo cpf, devem ser divergentes dos ja existentes
			case 1: 
				printf ("\n>> INFORME NOVA AG�NCIA:"); 
				scanf ("%d", &auxAgencia);
				retornoAlt = validarConta(&*cont, auxAgencia, listaConta[id].numConta, listaConta);
				//Se retorno da fun��o for igual a 1 o novo par esta adequado para fazer altera��o
				if (retornoAlt == 1){
					printf ("\n\t<#> ALTERA��O FEITA COM SUCESSO! <#>\n"); 
					listaConta[id].numAgencia = auxAgencia; 
				//Caso o par for inadequado, ent�o valor n�o � alterado, e retorna para o menu de altera��o 	
				}else 
					printf ("\n\t<#>  Error, ALTERA��O INV�LIDA   <#>\n"); 
					
				system("pause"); 
				break ; 
			case 2: 
				printf (">> INFORME NOVO N� CONTA:"); 
				scanf ("%d", &auxConta);
	   	   	   	retornoAlt = validarConta(&*cont, listaConta[id].numAgencia, auxConta, listaConta);
	   	   	   	//Se retorno da fun��o for igual a 1 o novo par esta adequado para fazer altera��o
				if (retornoAlt == 1){
					printf ("\n\t<#> ALTERA��O FEITA COM SUCESSO! <#>\n"); 
					listaConta[id].numConta = auxConta; 
				//Caso o par for inadequado, ent�o valor n�o � alterado, e retorna para o menu de altera��o 	
				}else 
					printf ("\n\t<#>  ERROR, ALTERA��O INV�LIDA   <#>\n"); 
					
				system("pause"); 
				break ; 
			case 3: 
				printf (">> INFORME NOVO CPF:"); //precisa alterar dados, para novo num de cpf
				scanf ("%s", cpf);
				retornoValCpf = validarCpfConta (&*cont, cpf, listaConta);
				
				if (retornoValCpf == 1){
					strcpy(listaConta[id].cpf, cpf);
					idCpf = return_id (&*pos, cpf, listaCliente);  
					strcpy(listaCliente[idCpf].cpf, cpf);  
				}else 
					printf ("\n\t<#>  ERROR, ALTERA��O INV�LIDA   <#>\n");
				system("pause");  
				break ; 
			case 0: 
				printf ("\n\tRETORNANDO");  
				carregamento(); 
			    system("cls"); break ; 	 
			default: 
				printf ("\nOPS, VALOR DIGITADO N�O ESTA NO MENU :(\n\n");  
				system("pause"); system("cls");
			break; 	
		}
	}while (esc != 0); 
}

void RemoverConta (int *cont, int *pos, conta listaConta[], cliente listaCliente[], int id){
	//Zera toda a conta do clinte e ao final decrementa um valor do numero de contas
	int retorno,i ;
	
	listaConta[id].numAgencia = 0; 
	listaConta[id].numConta = 0; 
	listaConta[id].saldo = 0; 	
	//Retorno do cpf para encontrar a conta do cliente, deve ser feito antes de zerar os dados
	retorno = return_id (&*pos, listaConta[id].cpf, listaCliente);
	strcpy (listaConta[id].cpf, "\0");
	
	for (i=id; i< *cont; i++){ // Passando os valore da lista para esquerda
		listaConta[i] = listaConta[i+1]; 
	}
	
	(*cont)--;  //Decrementando o numero de contas
	(listaCliente[retorno].quant_contas)--; //Retirando uma conta do usu�rio
}

void SaldoConta (int *cont, conta listaConta[]){
	//Fun��o saldo da conta precisa pedir os valoes da Agencia e conta, para poder printar o saldo
	int retorno, id, numAgencia, numConta;  
	
	menuAgencia_Conta(&numAgencia, &numConta); //Menu agencia, recebe os valores de numAgencia e numConta
	retorno = validarConta(&*cont,numAgencia,numConta, listaConta); 

	if (retorno == 0){
		id = return_id_conta (&*cont, &numAgencia, &numConta, listaConta); 
		printf("\n\tSALDO ATUAL R$%.2f\n\n", listaConta[id].saldo); system("pause"); 
	}else{
	   	printf("\n\t[CONTA N�O REGISTRADA PARA VIZUALIZAR]\n\n"); system("pause"); 
	} 
}

void Depositar(conta listaConta[],int *cont){
	float valorDep ;
	int numAgencia, numConta,id, retorno;
	
	menuAgencia_Conta(&numAgencia, &numConta); 
	retorno = validarConta(&*cont,numAgencia,numConta, listaConta); 
	
    if (retorno == 0){
    	system("cls"); subinhado(); printf ("DEPOSITANDO DINHEIRO NA CONTA\n"); 
    	printf ("-------------------------------------\n");
    	
    	id = return_id_conta (&*cont, &numAgencia, &numConta, listaConta); 
    	printf("\n\tSALDO ATUAL R$%.2f\n\n", listaConta[id].saldo);
		printf(">> Informe o valor de deposito R$ ");
		scanf("%f", &valorDep); 
		
		(listaConta[id].saldo) += valorDep ; //Adicionando valor da conta do cliente 
		printf ("\n\t<#> VALOR RETIRADO COM SUCESSO <#>\n\n");
		system ("pause"); 
	}else{
	   	printf("\n\t[CONTA N�O REGISTRADA PARA MODIFICA��S]\n\n"); system("pause"); 
	}
}

void Saque (conta listaConta[],int *cont){
	int numAgencia, numConta,id, retorno;
	float valorRet; 
	
	menuAgencia_Conta(&numAgencia, &numConta); 
	retorno = validarConta(&*cont,numAgencia,numConta, listaConta); 
	
    if (retorno == 0){
    	system("cls"); subinhado(); printf ("SACANDO DINHERO DA CONTA\n"); 
    	printf ("-------------------------------------\n");
    	
    	id = return_id_conta (&*cont, &numAgencia, &numConta, listaConta); 
    	printf("\n\tSALDO ATUAL R$%.2f\n\n", listaConta[id].saldo);
		printf(">> Informe valor a ser retirado R$ ");
		scanf("%f", &valorRet); 
		
		if (valorRet <= listaConta[id].saldo){
			(listaConta[id].saldo) -= valorRet ; //Retirando valor da conta do cliente
			printf ("\n\t<#> VALOR RETIRADO COM SUCESSO <#>\n\n");
		}else 
			printf("\n\t[SALDO INSUFICIENTE]\n\n");  
	
		system ("pause"); 
	}else{
	   	printf("\n\t[CONTA N�O REGISTRADA PARA MODIFICA��S]\n\n"); system("pause"); 
	}
}

void Tranferencia (conta listaConta[],int *cont){
	float valorTranf; 
	int numAgencia1, numConta1, numAgencia2, numConta2; 
	int retorno1, retorno2, id_1, id_2;
	
	menuAgencia_Conta(&numAgencia1, &numConta1); //Recebendo os pares1
	id_1 = return_id_conta ( &*cont, &numAgencia1, &numConta1, listaConta); //Retornando id da conta origem
	retorno1 = validarConta(&*cont,numAgencia1,numConta1, listaConta); 
	
	menuAgencia_Conta(&numAgencia2, &numConta2); //Recebendo os pares2
	id_2 = return_id_conta ( &*cont, &numAgencia2, &numConta2, listaConta); //Retornando id da conta saida
	retorno2 = validarConta(&*cont,numAgencia2,numConta2, listaConta);
	
	if (numConta1 != numConta2 && numAgencia1 != numAgencia2){ //Fazendo valida��o de contas, atribuindo o aviso adequado para cada situa��o
		if (retorno1 == 1){
    		printf ("\n\tCONTA DE ORIGEM N�O EXISTE\n");
		}else if (retorno2 == 1){
			printf ("\n\tCONTA DE SAIDA N�O EXISTE\n");
		}else if (retorno1 == 1 && retorno2 == 1){
			printf ("\n\tCONTA DE ORIGEM & CONTA DE ENTRADA\nN�O EXISTEM PRA CONTINUAR A TRANFERENCIA\n");	
			
		}else{ //Caso n�o entre em nunhuma exec��o, a conta esta adequada e os valores podem ser transferidos
			printf ("\n\tPREPARANDO TRANFERENCIA"); carregamento(); 
			system("cls"); subinhado(); printf ("\tTRANSFER�NCIA BANCARIA\n");
			printf ("CONTA ORIGEM: %.2f\nCONTA SAIDA: %.2f\n", listaConta[id_1].saldo, listaConta[id_2].saldo ); 
			printf ("-------------------------------------\n\n");	
			
			printf ("\tInforme o saldo para transferir R$ "); 
			scanf ("%f", &valorTranf); 
			
			if (valorTranf <= listaConta[id_1].saldo){ //Somente execulta a a��o se a conta tiver saldo suficiente
				printf ("\n\t TRANFERINDO"); carregamento(); 
				(listaConta[id_1].saldo) -= valorTranf; 
				(listaConta[id_2].saldo) += valorTranf;
				printf ("\n\t<#> VALOR TRANFERIDO COM SUCESSO <#>\n\n");
			}else 
				printf ("\n\t[SALDO INSUFICINTE PARA TRANSI��O]\n\n");
		}
	}else{
		printf ("\n\tN�O � POSSIVEL FAZER TRANFER�NCIAS, COM CONTAS IGUAIS\n");
	}system ("pause"); 	 
}

void Listar1 (conta listaConta[], cliente listaCliente[], int *cont, int *pos){ 
	//LISTAR CONTAS CUJO O CPF FOR DIGITADO
	char cpf[12]; 
	int retorno , id; 
	system("cls"); subinhado(); printf ("\tLISTAGEM DE CONTA\n");
	
	printf ("\nInforme o CPF para ver conta: "); 
	scanf ("%s", cpf); 
	retorno = validarCpfConta ( &*cont, cpf, listaConta);
	id = return_id(&*pos, cpf, listaCliente);
	
	if (retorno == 0){
		printf ("\nN� DA CONTA:  %d   \n", listaConta[id].numConta); 
		printf ("N� DA AG�NCIA:  %d   \n", listaConta[id].numAgencia);
		printf ("SALDO DA CONTA R$%.2f\n\n", listaConta[id].saldo);
	}else{
		printf ("\n\t[CONTA N�O REGISTRADA NESTE CPF]\n\n");
	}
}

void Listar2 (conta listaConta[], cliente listaCliente[], int *cont, int *pos, FILE *salvar){ //FUN��O QUE PODE SALVAR DADOS COMO ARQUIVO TXT
	double valorAnalise; 
	int esc, id, i;
	int quantM=0; //quat vai contar o tanto de contas ser�o encontradas com valores MAIORES
	int esc1;
	
	printf ("\nInforme o valor para analise R$ ");
	scanf ("%lf", &valorAnalise);
		
 	system("cls"); menuValorEsp (&esc, valorAnalise);
 	
 	if (*cont != 0){
		switch (esc){
			case 1: //Quer mostrar contas com valores MAIORES que valorEspecifico
				system("cls"); printf ("\tIMPRIMINDO DADOS DOS CLIENTES\n");
	   	   	   	printf ("-------------------------------------\n");	
				for (i=0; i< *cont; i++){ //Pecorrer todas as contas cadastradas 
					if (listaConta[i].saldo > valorAnalise ){ 
						id = return_id ( &*pos, listaConta[i].cpf, listaCliente); //Pegar o id do cpf para buscar conta certa
						printf ("\n\tCONTA DO CLIENTE [%d]\n", id+1); 
						printf ("NOME      : %s\n", listaCliente[id].nome); 
				  		printf ("CPF       : %s\n", listaCliente[id].cpf); 
						printf ("N� AG�NCIA: %d\n", listaConta[i].numAgencia);
						printf ("N� CONTA  : %d\n", listaConta[i].numConta);
						printf ("SALDO     : %.2lf\n", listaConta[i].saldo); 
						printf ("-------------------------------------\n");		 
						quantM++ ; //incrementando quantidade de contas encontradas 
					} 
				}if (quantM == 0){
					printf ("NENHUMA CONTA TEM VALOR MAIOR QUE %.2f\n\n", valorAnalise); 
				}else{
					menuSalvar(&esc1); 
					if (esc1 == 1){
						for (i=0; i< *cont; i++){ //Pecorrer todas as contas cadastradas 
							fprintf (salvar, "NOME      : %s\n", listaCliente[id].nome); 
					  		fprintf (salvar, "CPF       : %s\n", listaCliente[id].cpf); 
							fprintf (salvar, "N� AG�NCIA: %d\n", listaConta[i].numAgencia);
							fprintf (salvar, "N� CONTA  : %d\n", listaConta[i].numConta);
							fprintf (salvar, "SALDO     : %.2lf\n\n", listaConta[i].saldo); 
	  	  	            }	
					}	
	 	 	 	 } 	  	 	  	
				break ;	 
			case 0: //Quer mostrar contas com valores IGUAIS que valorEspecifico
	   	   	   	system("cls"); printf ("\tIMPRIMINDO DADOS DOS CLIENTES\n");
	   	   	   	printf ("-------------------------------------\n");	
				for (i=0; i< *cont; i++){ //Pecorrer todas as contas cadastradas 
					if (listaConta[i].saldo == valorAnalise ){ 
						id = return_id ( &*pos, listaConta[i].cpf, listaCliente); //Pegar o id do cpf para buscar conta certa
						printf ("\n\tCONTA DO CLIENTE [%d]\n", id+1); 
						printf ("NOME------- %s\n", listaCliente[id].nome); 
				  		printf ("CPF-------- %s\n", listaCliente[id].cpf); 
						printf ("N� AG�NCIA- %d\n", listaConta[i].numAgencia);
						printf ("N� CONTA--- %d\n", listaConta[i].numConta);
						printf ("SALDO------ %.2lf\n", listaConta[i].saldo); 
						printf ("-------------------------------------\n");		 
						quantM++ ; //incrementando quantidade de contas encontradas 
					} 
				}if (quantM == 0){
					printf ("NENHUMA CONTA TEM VALOR IGUAL A %.2f\n\n", valorAnalise); 
				}else{
	   	   	   	   	menuSalvar(&esc1); 
					if (esc1 == 1){
						for (i=0; i< *cont; i++){ //Pecorrer todas as contas cadastradas 
							fprintf (salvar, "NOME      : %s\n", listaCliente[id].nome); 
					  		fprintf (salvar, "CPF       : %s\n", listaCliente[id].cpf); 
							fprintf (salvar, "N� AG�NCIA: %d\n", listaConta[i].numAgencia);
							fprintf (salvar, "N� CONTA  : %d\n", listaConta[i].numConta);
							fprintf (salvar, "SALDO     : %.2lf\n\n", listaConta[i].saldo); 
	  	  	            }	
					}	
	 	 	 	 } 	  
				break ; 
			case -1: //Quer mostrar contas com valores MENORES que valorEspecifico
				system("cls"); printf ("\tIMPRIMINDO DADOS DOS CLIENTES\n");
				printf ("-------------------------------------\n");	
				for (i=0; i< *cont; i++){ //Pecorrer todas as contas cadastradas 
					if (listaConta[i].saldo < valorAnalise ){ 
						id = return_id ( &*pos, listaConta[i].cpf, listaCliente); //Pegar o id do cpf para buscar conta certa
						printf ("\n\tCONTA DO CLIENTE [%d]\n", id+1); 
						printf ("NOME------- %s\n", listaCliente[id].nome); 
				  		printf ("CPF-------- %s\n", listaCliente[id].cpf); 
						printf ("N� AG�NCIA- %d\n", listaConta[i].numAgencia);
						printf ("N� CONTA--- %d\n", listaConta[i].numConta);
						printf ("SALDO------ %lf\n", listaConta[i].saldo); 
						printf ("-------------------------------------\n");		 
						quantM++ ; //incrementando quantidade de contas encontradas 
					} 
				}if (quantM == 0){
					printf ("NENHUMA CONTA TEM VALOR MENOR QUE %.2f\n\n", valorAnalise);
				}else{
					menuSalvar(&esc1); 
					if (esc1 == 1){
						for (i=0; i< *cont; i++){ //Pecorrer todas as contas cadastradas 
							fprintf (salvar, "NOME      : %s\n", listaCliente[id].nome); 
					  		fprintf (salvar, "CPF       : %s\n", listaCliente[id].cpf); 
							fprintf (salvar, "N� AG�NCIA: %d\n", listaConta[i].numAgencia);
							fprintf (salvar, "N� CONTA  : %d\n", listaConta[i].numConta);
							fprintf (salvar, "SALDO     : %.2lf\n\n", listaConta[i].saldo); 
	  	  	            }	
					}	
	 	 	 	 } 
			 	break;
			default: 
				printf ("\nOPS, VALOR DIGITADO N�O ESTA NO MENU :(\n\n");  
				break; 		
		}
	}else{
		printf ("\nN�O EXISTE CONTAS FAZER LISTAMENTO\n"); 
	}
}

void Listar3 (cliente listaCliente[], int *pos, FILE *salvar1){ //DEVE SALVAR ARQUIVO TXT
	//INFORMA��ES DE TODOS CLIENTES
	system("cls"); printf ("\tIMPRIMINDO DADOS DOS CLIENTES\n");
	printf ("-------------------------------------\n");	
	int i, quant=0, esc;
	for (i=0; i< *pos; i++){	
		printf ("\nCADASTRO DO CLIENTE [%d]\n", i+1); 
		printf ("NOME----- %s\n", listaCliente[i].nome); 
  		printf ("CPF------ %s\n", listaCliente[i].cpf); 
		printf ("ENDERE�O- %s\n", listaCliente[i].end);
		printf ("TELEFONE- %d\n", listaCliente[i].telefone);
		printf ("EMAIL---- %s\n", listaCliente[i].email);
		printf ("-------------------------------------\n");		
		quant++;
	}
	if (quant == 0)
		printf ("\n\t<#> NENHUMA CONTA PARA IMPRIMIR DADOS <#>\n\n");
	
	menuSalvar(&esc); //SAlvando arquivos
	if (esc == 1){
		for (i=0; i< *pos; i++){	
			fprintf (salvar1, "\nCADASTRO DO CLIENTE [%d]\n", i+1); 
			fprintf (salvar1, "NOME----- %s\n", listaCliente[i].nome); 
	  		fprintf (salvar1, "CPF------ %s\n", listaCliente[i].cpf); 
			fprintf (salvar1, "ENDERE�O- %s\n", listaCliente[i].end);
			fprintf (salvar1, "TELEFONE- %d\n", listaCliente[i].telefone);
			fprintf (salvar1, "EMAIL---- %s\n\n", listaCliente[i].email);
		}
	}
}

void Listar4 (conta listaConta[], cliente listaCliente[], int *cont, int *pos, FILE *salvar2){ //DEVE SALVAR ARQUIVO TXT
	//INFOMRA��ES SOBRE TODOS AS CONTAS
	system("cls"); printf ("\tIMPRIMINDO DADOS DOS CLIENTES\n");
	printf ("-------------------------------------\n");	
	int i, id, quant=0, esc;
	for (i=0; i< *cont; i++){	
		id = return_id(&*pos, listaConta[i].cpf, listaCliente);
		printf ("\nCONTA DO CLIENTE [%d]\n", id+1); 	
		printf ("NOME------- %s\n", listaCliente[id].nome);
		printf ("CPF-------- %s\n", listaConta[i].cpf);
		printf ("N� AG�NCIA- %d\n", listaConta[i].numAgencia); 
  		printf ("N� CONTA--- %d\n", listaConta[i].numConta); 
		printf ("SALDO------ %.2f\n", listaConta[i].saldo);
		printf ("-------------------------------------\n");	
		quant++;	
	}
	if (quant == 0)
		printf ("\n\t<#> NENHUMA CONTA PARA IMPRIMIR DADOS <#>\n\n");

	menuSalvar(&esc); //SAlvando arquivos
	if (esc == 1){
		for (i=0; i< *pos; i++){	
			fprintf (salvar2, "\nCONTA DO CLIENTE [%d]\n", id+1); 	
			fprintf (salvar2, "NOME------- %s\n", listaCliente[id].nome);
			fprintf (salvar2, "CPF-------- %s\n", listaConta[i].cpf);
			fprintf (salvar2, "N� AG�NCIA- %d\n", listaConta[i].numAgencia); 
	  		fprintf (salvar2, "N� CONTA--- %d\n", listaConta[i].numConta); 
			fprintf (salvar2, "SALDO------ %.2f\n", listaConta[i].saldo);
		}
	}
}

void Listar5 (conta listaConta[], cliente listaCliente[], int *cont, int *pos, FILE *salvar3){ //DEVE SALVAR ARQUIVO TXT
	//INFOMRA��ES SOBRE todos clientes e caso existir conta, deve imprimir tmb
	system("cls"); printf ("\tIMPRIMINDO DADOS DOS CLIENTES\n");
	printf ("-------------------------------------\n");	
	int i, x , id , quant=0, esc;
	for (i=0; i< *pos; i++){	
		printf ("\n\tCADASTRO DO CLIENTE [%d]\n", i+1); 
		printf ("NOME----- %s\n", listaCliente[i].nome); 
  		printf ("CPF------ %s\n", listaCliente[i].cpf); 
		printf ("ENDERE�O- %s\n", listaCliente[i].end);
		printf ("TELEFONE- %d\n", listaCliente[i].telefone);
		printf ("EMAIL---- %s\n", listaCliente[i].email);
		printf ("***********************************\n");	
			
		if (listaCliente[i].quant_contas == 0){ //N�o exista conta deste cliente para imprimir
			printf ("PARA ESTE CLIENTE N�O EXISTE CONTA!\n\n"); 
			
		}else{	
			id = return_id_conta_cpf (&*cont, listaCliente[i].cpf, listaConta); //Pegar o indice do cliente
			for (x=0; x< listaCliente[i].quant_contas; x++){
				printf ("\tCONTA DO CLIENTE [%d]\n", i+1); 	
				printf ("\tN� AG�NCIA- %d\n", listaConta[id].numAgencia); 
		  		printf ("\tN� CONTA--- %d\n", listaConta[id].numConta); 
				printf ("\tSALDO------ %.2f\n", listaConta[id].saldo);
				printf ("-------------------------------------\n");	
			}
		}
		quant++;
	}
	if (quant == 0)
		printf ("\n\t<#> NENHUM DADO CLIENTE IMPRIMIR <#>\n\n");
	
	menuSalvar(&esc); //SAlvando arquivos
	if (esc == 1){
		for (i=0; i< *pos; i++){	
		fprintf (salvar3, "\n\tCADASTRO DO CLIENTE [%d]\n", i+1); 
		fprintf (salvar3, "NOME----- %s\n", listaCliente[i].nome); 
  		fprintf (salvar3, "CPF------ %s\n", listaCliente[i].cpf); 
		fprintf (salvar3, "ENDERE�O- %s\n", listaCliente[i].end);
		fprintf (salvar3, "TELEFONE- %d\n", listaCliente[i].telefone);
		fprintf (salvar3, "EMAIL---- %s\n", listaCliente[i].email);	
				
		if (listaCliente[i].quant_contas == 0){ //N�o exista conta deste cliente para imprimir
			printf ("PARA ESTE CLIENTE N�O EXISTE CONTA!\n\n"); 
			
		}else{	
			id = return_id_conta_cpf (&*cont, listaCliente[i].cpf, listaConta); //Pegar o indice do cliente
			for (x=0; x< listaCliente[i].quant_contas; x++){
				fprintf (salvar3, "\tCONTA DO CLIENTE [%d]\n", i+1); 	
				fprintf (salvar3, "\tN� AG�NCIA- %d\n", listaConta[id].numAgencia); 
				fprintf (salvar3, "\tN� CONTA--- %d\n", listaConta[id].numConta); 
				fprintf (salvar3, "\tSALDO------ %.2f\n\n", listaConta[id].saldo);	
			}
		}
	}
}
}
void Listar6 (conta listaConta[], cliente listaCliente[], int *cont, int *pos){
	int numAgencia, id, i, retorno; 
	printf ("Digite o numero da agencia: ");
	scanf ("%d", &numAgencia); 
	retorno = validarContaAgencia(&*cont, numAgencia, listaConta); //Verificando existencia da conta cadastrada nesta agencia
	
	system("cls"); 
	printf ("\n\tCLIENTES CADASTRADOS NA AGENICA [%d]\n", numAgencia); 
	if (retorno == 0){
		for (i=0; i< *cont; i++){ //Pecorrendo cada elemento do vetConta, procurando Agencia
			if (listaConta[i].numAgencia == numAgencia){ 
				id = return_id (&*pos, listaConta[i].cpf, listaCliente); //Retornar indice cliente, passado seu cpf
				
	   	   	   	printf ("\n\tCADASTRO DO CLIENTE [%d]\n", i+1); 
				printf ("NOME----- %s\n", listaCliente[id].nome); 
		  		printf ("CPF------ %s\n", listaCliente[id].cpf); 
				printf ("ENDERE�O- %s\n", listaCliente[id].end);
				printf ("TELEFONE- %d\n", listaCliente[id].telefone);
				printf ("EMAIL---- %s\n", listaCliente[id].email);
			}
		}
	}else{
		printf ("N�O EXISTE CONTA CADASTRADA NESTA AGENICA\n"); 
	}	   	
} 