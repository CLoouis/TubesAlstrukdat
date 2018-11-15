#include "../ADT/array.h"
#include "../ADT/point.h"
#include "../ADT/matriks.h"
#include "../ADT/stackt.h"

#ifndef COMMANDLOUIS_H
#define COMMANDLOUIS_H

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

void Recipe();
//Menampilkan resep makanan
void tampilanAwal();
//Menampilkan tampilan awal game
void menu(int *X);
//Menampilkan menu awal
void newGame(TabInt *User, KataArray *nama);

void loadGame(TabInt User, KataArray *nama, int *indexUser);

void GoUp(Player *P, MATRIKS *M);

void GoDown(Player *P, MATRIKS *M);

void GoLeft(Player *P, MATRIKS *M);

void GoRight(Player *P, MATRIKS *M);

#endif
