#ifndef SAFELOAD_H
#define SAFELOAD_H

#include "tipebentukan.h"
#include "boolean.h"

void newsave(KataString Nama);

void ceksave(KataString Nama, boolean *mark);

void Load(Player *P, Queue *AntrianLuar, ruang *ruangan, arrayC *arrayCust, DaftarO *DaftarOrder);

void Save(Player P, Queue AntrianLuar, ruang ruangan, arrayC arrayCust, DaftarO DaftarOrder);


#endif