#include <stdio.h> 

int main (){
	int dia, mes, ano, diaAtr;
	char valorAno; 
	
	printf ("Data: DD/MM/AA: "); 
	scanf ("%d%d%d", &dia, &mes, &ano );
	
	//Cauculo do ano bissexto
	if ( ano%100 == 0 ){
		if ( ano%400 == 0){
			valorAno = 'b'; 
		}else 
			valorAno = 'n';
	}else if ( ano%4 == 0){
		valorAno = 'b';
	}else 
		valorAno = 'n';
	
	//Atribuindo valores dos meses	
	if ( mes <= 12){
		switch (mes){
			case 1:
				diaAtr = 30; 
				break; 
			case 2:
				if ( valorAno == 'b'){
					diaAtr = 29;
					break; 
				}else 
					diaAtr = 28;
					break;  
			case 3:
				diaAtr = 30; 
				break; 
			case 4: 
				diaAtr = 30; 
				break; 
			case 5: 
				diaAtr = 30; 
				break; 
			case 6:	
				diaAtr = 30; 
				break; 
			case 7:	
				diaAtr = 30; 
				break; 
			case 8:	
				diaAtr = 30; 
				break; 
			case 9:	
				diaAtr = 30; 
				break; 
			case 10:	
				diaAtr = 30; 
				break; 
			case 11:	
				diaAtr = 30; 
				break; 
			case 12:	
				diaAtr = 30; 
				break; 
			
		}if ( dia > diaAtr )
			printf ("Data inválida!");
	}else 
		printf ("Valor do mes não coerente!"); 
		printf ("%d/%d/%d", dia, mes, ano); 
return 0; 
}