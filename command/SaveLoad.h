#ifndef SAFELOAD_H
#define SAFELOAD_H

#include "../ADT/tipebentukan.h"
#include "../ADT/boolean.h"

void newsave(KataString Nama);

boolean ceksave(KataString Nama);

void Load(Player *P, Queue *AntrianLuar, ruang *ruangan, arrayC *arrayCust, DaftarO *DaftarOrder);

void Save(Player P, Queue AntrianLuar, ruang ruangan, arrayC arrayCust, DaftarO DaftarOrder);


#endif