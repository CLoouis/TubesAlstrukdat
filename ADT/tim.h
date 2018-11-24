#include "stackt.h"


#define FoodStack(P) (P).FoodStack
#define Hand(P) (P).Hand

typedef struct { 
	Stack FoodStack; /* tabel penyimpan elemen */
	Stack Hand;  /* alamat TOP: elemen puncak */
    int x; //posisi baris
    int y; // posisi kolomg
    int room; // ruang mana
} Player;



