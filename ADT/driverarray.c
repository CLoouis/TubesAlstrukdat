#include <stdio.h>
#include <stdlib.h>
#include "../ADT/array.h"
#include "../ADT/tipebentukan.h"

int main(){
	int X,N;
	TabInt T1,T2;
	MakeEmpty(&T1);
	MakeEmpty(&T2);
	printf("Masukkan isi Tab 1\n");
	BacaIsiTab(&T1);
	printf("Masukkan isi Tab 2\n");
	BacaIsiTab(&T2);
	// TulisIsiTab(PlusTab(T1,T2));
	/*
	if(IsLess(T1,T2)){
		printf("T1 lebih kecil dari T2\n");
	}
	else{
		printf("T1 tidak lebih kecil dari T2\n");
	}*/
//	CopyTab(T1,&T2);
	/*
	printf("%d\n",T1.Neff);
	
	if (IsEQ(T1,T2)){
		printf("Sama\n");
	}
	else {
		printf("Tidak Sama\n");
	}
		*/
	/*
	printf("%d\n",ValMax(T1));
	printf("%d\n",IdxMaxTab(T1));
	printf("\n%d\n",ValMin(T1));
	printf("%d\n",IdxMinTab(T1));	*/
//	AddElUnik(&T1,6);
//	Del1Urut(&T1,4);
//	Add1Urut(&T1,5);
//	MaxSortDesc(&T1);
//	TulisIsiTab(T1);
//	printf("%d\n",T1.Neff);
//	TulisIsiTab(T2);
//	TulisIsiTab(InverseTab(T1));
/*
	if(IsSimetris(T1)){
		printf("Simetris\n");
	}
	else{
		printf("Tidak Simetris\n");
	}*/

/*
	if(SearchSentinel(T1,5)){
		printf("ketemu\n");
	}
	else {
		printf("tidak ketemu\n");
	}*/

//	MaxMinUrut(T1,&X,&N);
//	printf("%d\n",SearchUrut(T1,5));
//	printf("Nilai max Tab1 adalah %d, dan nilai min Tab1 adalah %d\n",X,N);
	return 0;
}