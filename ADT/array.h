#ifndef ARRAY_H
#define ARRAY_H

#include "boolean.h"
#include "tipebentukan.h"

void MakeEmpty (TabInt *T);

int NbElmt (TabInt T);

int GetFirstIdx (TabInt T);

int GetLastIdx (TabInt T);

boolean IsEmpty (TabInt T);

boolean IsFull (TabInt T);

void TulisIsiTab (TabInt T);

IdxType Search (TabInt T, ArrayElType X);

void AddElUnik(TabInt *T, ArrayElType X);

void AmbilDataArray(TabInt *T);

void UploadDataArray(TabInt *T);

#endif
