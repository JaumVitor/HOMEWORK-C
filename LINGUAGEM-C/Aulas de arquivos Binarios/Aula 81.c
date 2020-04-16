#include <stdio.h> 

int main(){
	FILE *arquivo; // Criando o arquivo 
	//arquivo = fopen("texto.txt", "w");  //Criando um arquivo txt, dessa forma ele esta padrão (Cria onde o codigo está); 
	arquivo = fopen("C:\\Users\\João Victor\\Desktop\\texto.txt", "w"); //Cria arquivo de texto passando o diretorio
	fprintf (arquivo, "Hello new word"); //Printf que ira escrever no arquivo de texto
	fclose(arquivo); //Salvando o arquivo de texto
	
	return 0; 
}