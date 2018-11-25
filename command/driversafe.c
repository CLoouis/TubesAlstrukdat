#include "SaveLoad.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../ADT/tipebentukan.h"
#include "../ADT/mesinkata.h"
#include "../ADT/mesinkar.h"
#include "../ADT/boolean.h"
#include "../ADT/stackt.h"
#include "../ADT/queue.h"


// void Load (Player *P, Queue *AntrianLuar, ruang *ruangan);


int main(){
	int i,j;
	Player P;
	Queue AntrianLuar;
	ruang ruangan;
	DaftarO DaftarOrder; 
	arrayC arrayCust;
	boolean Found;
	char input;
	KataString temp;
	for (i = 1; i<9; i++){
        for (j = 1; j<9; j++){
            Ruang(ruangan,1,i,j) = '-';
            Ruang(ruangan,2,i,j) = '-';
            Ruang(ruangan,3,i,j) = '-';
            Ruang(ruangan,4,i,j) = '-';
        }
    }
    CreateEmpty(&AntrianLuar,10);
    printf("Nama disave: ");
    scanf("%s", Name(P));
	// for (i = 1; i<9; i++){
 //        for (j = 1; j<9; j++){
 //            printf("%c",ruangan[1][i][j]);
 //            printf("%c",ruangan[2][i][j]);
 //            printf("%c",ruangan[3][i][j]);
 //            printf("%c",ruangan[4][i][j]);
 //        }
 //    }

	// CreateStackEmpty(&(FoodStack(P)));
	// CreateStackEmpty(&(Hand(P)));
	// Posisi(P).X = 0;
	// Posisi(P).Y = 0;
	// Room(P) = 0;
	// strcpy(Name(P)," ");
	// Money(P) = 0;
	// Life(P) = 0;
	// Time(P) = 0;
	// CreateEmpty(&AntrianLuar,10);
    Found = ceksave(Name(P));
    if (Found){
    	printf("Nama ditemukan\n");
    	Load(&P, &AntrianLuar, &ruangan, &arrayCust, &DaftarOrder);
		Save(P, AntrianLuar, ruangan, arrayCust, DaftarOrder);
    }
	else {
		printf("Apakah ingin membuat file baru? ");
		scanf("%c", &input);
		scanf("%c", &input);
		if (input == 'Y' || input == 'y'){
			newsave(Name(P));
			Load(&P, &AntrianLuar, &ruangan, &arrayCust, &DaftarOrder);
			// printf("Name: %s\n", Name(P));
			Save(P, AntrianLuar, ruangan, arrayCust, DaftarOrder);
		}
	}
	printf("Name: %s\n", Name(P));
    printf("Position: %d,%d\n", Posisi(P).X, Posisi(P).Y);
    printf("Money: %d\n", Money(P));
    printf("Life: %d\n", Life(P));
    printf("Time: %d\n", Time(P));
    printf("Ruang 1: \n");
    for(i=1;i<=8;i++){
        for(j=1;j<=8;j++){
            printf("%c ",Ruang(ruangan,1,i,j));
        }
        printf("\n");
    }
    printf("Ruang 2: \n");
    for(i=1;i<=8;i++){
        for(j=1;j<=8;j++){
            printf("%c ",Ruang(ruangan,2,i,j));
        }
        printf("\n");
    }
    printf("Ruang 3: \n");
    for(i=1;i<=8;i++){
        for(j=1;j<=8;j++){
            printf("%c ",Ruang(ruangan,3,i,j));
        }
        printf("\n");
    }
    printf("Kitchen: \n");
    for(i=1;i<=8;i++){
        for(j=1;j<=8;j++){
            printf("%c ",Ruang(ruangan,4,i,j));
        }
        printf("\n");
    }


	return 0;
}