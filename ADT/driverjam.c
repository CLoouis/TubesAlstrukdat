#include <stdio.h>
#include "../ADT/boolean.h"
#include "../ADT/jam.h"

int main(){
	
	JAM j1,j2;
	int a,b,c;
	printf("Masukkan data jam 1\n");
	scanf("%d %d %d",&a,&b,&c);
	//MakeJAM
	j1 = MakeJAM(a,b,c);
	//TulisJAM
	TulisJAM(j1);
	printf(" atau sama dengan %li detik\n",JAMToDetik(j1));
	printf("Masukkan data jam 2\n");
	//BacaJAM & IsJAMValid
	BacaJAM(&j2);
	
	//JEQ,JNEQ,JGT,JLT
	if(JEQ(j1,j2)){
		printf("j1 sama dengan j2\n");
	}
	else if (JNEQ(j1,j2)){
		if(JGT(j1,j2)){
			printf("jam 1 lebih besar dari jam 2\n");
		}
		else if(JLT(j1,j2)){
			printf("jam 1 lebih kecil dari jam 2\n");
		}
	}
	//PrevDetik & NextDetik
	printf("jam 1 terletak diantara ");
	TulisJAM(PrevDetik(j1));
	printf(" dan ");
	TulisJAM(NextDetik(j1));
	printf("\n");
	
	//NextNDetik & PrevNDetik
	printf("Masukkan nilai modifier detik\n");
	scanf("%d",&a);
	printf("%d detik setelah j1 adalah ",a);
	TulisJAM(NextNDetik(j1,a));
	printf(" dan %d detik sebelum j1 adalah ",a);
	TulisJAM(PrevNDetik(j1, a));
	
	//Durasi
	printf("\nDurasi antara j1 dan j2 adalah %li\n",Durasi(j1,j2));
	
	return 0;
}