#include "SaveLoad.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../ADT/tipebentukan.h"
#include "../ADT/mesinkata.h"
#include "../ADT/boolean.h"
#include "../ADT/stackt.h"
#include "../ADT/queue.h"


// void Load (Player *P, Queue *AntrianLuar, ruang *ruangan);


int main(){
	
	Player P;
	Queue AntrianLuar;
	ruang ruangan;
	
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

	Load(&P, &AntrianLuar, &ruangan);

	return 0;
}