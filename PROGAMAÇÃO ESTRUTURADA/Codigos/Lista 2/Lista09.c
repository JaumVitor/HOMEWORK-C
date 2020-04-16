#include <stdio.h> 
#include <locale.h> 

#define HR_TOTAL 86400; // 24 horas convertidas em segundos

int main(){
	setlocale(LC_ALL, "Portuguese"); 
	int seg, hh, mm, ss;
	
	
	printf ("Informe a os segundos: "); 
	scanf ("%d", &seg);
 	
	hh = seg / 3600;
	mm = ((seg % 3600) * 60) / 3600;
	ss = seg - ((60 * mm) + (60 * hh));
 
 	printf ("Hora: %d\nMin: %d\nSeg: %d", hh,mm, ss);
 	
	return 0; 
}