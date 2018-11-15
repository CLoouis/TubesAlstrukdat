#ifndef TIPEBENTUKAN_H
#define TIPEBENTUKAN_H

typedef struct {
	Stack FoodStack; /* tabel penyimpan elemen */
	Stack Hand;  /* alamat TOP: elemen puncak */
    POINT Posisi; // posisi kolomg
    int room; // ruang mana
} Player;

#define FoodStack(P) (P).FoodStack
#define Hand(P) (P).Hand
#define Posisi(P) (P).Posisi
#define Room(P) (P).room

#endif
