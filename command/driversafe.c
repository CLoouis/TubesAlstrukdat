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
	for (i = 1; i<9; i++){
        for (j = 1; j<9; j++){
            ruangan[1][i][j] = '-';
            ruangan[2][i][j] = '-';
            ruangan[3][i][j] = '-';
            ruangan[4][i][j] = '-';
        }
    }
	
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

	return 0;
}