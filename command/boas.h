#ifndef BOAS_H
#define BOAS_H

#include "../ADT/boolean.h"
#include "../ADT/point.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "../ADT/queue.h"
#include "../ADT/graph.h"
#include "../ADT/stackt.h"
#include "../ADT/listrek.h"
#include "../ADT/bintree.h"




boolean IsReachable(Player P, int x, int y, int jarak);
// Player P, x,y menyatakan koordinat tujuan, jarak menyatakan jarak yang kita mau, utk room 2, utk kitchen 1
void Order(Player P);  
void Put(Player *P);
void Take(Player *P);
void CH(Player *P);
void CT(Player *P);
void Place(Player P);
void Give(Player *P);   
void Recipe();
void NextTick(Player *P);
void Credit();
void AddQueue(Player P);
void UpdatePeta();
void GoUp(Player *P);
void GoDown(Player *P);
void GoLeft(Player *P);
void GoRight(Player *P);
void TampilPeta(int room);

//Titipan Louis
void tampilanAwal();
//Menampilkan tampilan awal game
void menu(int *X);
//Menampilkan menu awal
void newGame(TabInt *User, KataArray *nama);

void loadGame(TabInt User, KataArray *nama, int *indexUser);

#endif