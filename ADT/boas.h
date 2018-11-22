#ifndef BOAS_H
#define BOAS_H

#include "boolean.h"
#include "point.h"
#include <stdlib.h>
#include <stdio.h>
#include "queue.h"
#include "stackt.h"




boolean IsReachable(Player P, int x, int y, int jarak);
// Player P, x,y menyatakan koordinat tujuan, jarak menyatakan jarak yang kita mau, utk room 2, utk kitchen 1
void Order(Player P);  
void Put();
void Take(Player *P, POINT *pts );
void CH(Player *P);
void Place(Player P, Customer C, Queue Q);   

#endif
