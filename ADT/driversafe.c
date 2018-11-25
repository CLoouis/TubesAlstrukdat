#include "SaveLoad.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tipebentukan.h"
#include "mesinkata.h"
#include "mesinkar.h"
#include "boolean.h"
#include "stackt.h"
#include "queue.h"


// void Load (Player *P, Queue *AntrianLuar, ruang *ruangan);


int main(){
	int i,j;
	Player P;
	Queue AntrianLuar;
	ruang ruangan;
	for (i = 1; i<9; i++){
        for (j = 1; j<9; j++){
            Ruang(ruangan,1,i,j) = '-';
            Ruang(ruangan,2,i,j) = '-';
            Ruang(ruangan,3,i,j) = '-';
            Ruang(ruangan,4,i,j) = '-';
        }
    }
	// for (i = 1; i<9; i++){
 //        for (j = 1; j<9; j++){
 //            printf("%c",ruangan[1][i][j]);
 //            printf("%c",ruangan[2][i][j]);
 //            printf("%c",ruangan[3][i][j]);
 //            printf("%c",ruangan[4][i][j]);
 //        }
 //    }

	CreateStackEmpty(&(FoodStack(P)));
	CreateStackEmpty(&(Hand(P)));
	Posisi(P).X = 0;
	Posisi(P).Y = 0;
	Room(P) = 0;
	strcpy(Name(P)," ");
	Money(P) = 0;
	Life(P) = 0;
	Time(P) = 0;
	CreateEmpty(&AntrianLuar,10);

	Load(&P, &AntrianLuar, &ruangan);
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