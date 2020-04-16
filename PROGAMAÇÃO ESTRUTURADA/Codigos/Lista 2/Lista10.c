#include <stdio.h> 
#define hora_dia 1440

int main(){
	int horaC,minC, horaS, minS, horaFinalC, horaFinalS, tempo; 
	float tarifa; char boll = 'T'; 
	
	printf ("CHEGADA: ");
	scanf ("%d%d", &horaC, &minC);
	printf ("SAIDA: ");
	scanf ("%d%d", &horaS, &minS);
	
	if ((horaC < 24 && horaS < 24) && (minC < 61 && minS < 61)){
		if (horaC <= horaS){	// Caso 1 
			horaFinalC = (horaC * 60) + minC; 
			horaFinalS = (horaS * 60) + minS; 
			tempo = horaFinalS - horaFinalC; 
		}else{	//Caso 2
			tempo = ((hora_dia - (horaC * 60 + minC)) + (horaS * 60 + minS)); 
		}
		
		if (tempo <= 60)
			tarifa = 2;
		else if (tempo > 60 && tempo <= 120)
			tarifa = 2 + 2 ;
		else if (tempo > 120 && tempo <= 180)
			tarifa = 4 + 2.50;
		else if (tempo > 180 && tempo <= 240)
			tarifa = 4 + (2* 2.50);
		else
			tarifa = 5 + ((tempo / 60) * 3);
	}else{
		boll = 'F'; 
		printf ("Erro 401 com arcondicionado: Hora invalida digite novamente\n");
	}
	if (boll == 'T'){
		printf ("Esse veiculo ficou estacionado durante %d min\n", tempo); 
		printf ("Valor da tarifa: R$%.1f\n", tarifa);
	}	
	return 0; 
}