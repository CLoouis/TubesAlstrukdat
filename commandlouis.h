#include "array.h"

#ifndef COMMANDLOUIS_H
#define COMMANDLOUIS_H

void Recipe();
//Menampilkan resep makanan
void tampilanAwal();
//Menampilkan tampilan awal game
void menu(int *X);
//Menampilkan menu awal
void newGame(TabInt *User, Kata *nama);

void loadGame(TabInt User, Kata *nama, int *indexUser);
#endif
