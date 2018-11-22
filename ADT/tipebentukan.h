#ifndef TIPEBENTUKAN_H
#define TIPEBENTUKAN_H

#include "boolean.h"
#include "point.h"
//#include <stdlib.h>
//#include <stdio.h>
#include "queue.h"
#include "stackt.h"

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

Queue AntrianLuar; //antrian di luar

POINT DaftarMeja[5]; //Letak koordinat dari meja


Kata DaftarOrder[13]; //Daftar makanan yang dipesan, meja sesuai indeks

Customer arrayCust[13]; //Salinan customer ke meja




#define MARK '.'
#endif