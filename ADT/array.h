#ifndef ARRAY_H
#define ARRAY_H

#include "boolean.h"

/*  Kamus Umum */
#define IdxMax 9
#define IdxMin 0
#define IdxUndef -999

/* Definisi elemen dan koleksi objek */
typedef char Kata[10];
typedef int IdxType;  /* type indeks */
typedef Kata ArrayElType;   /* type elemen tabel */
typedef struct {
	ArrayElType TI[IdxMax+1]; /* memori tempat penyimpan elemen (container) */
	int Neff; /* >=0, banyaknya elemen efektif */
} TabInt;

//Selektor
#define Neff(T) (T).Neff
#define TI(T) (T).TI
#define ArrayElmt(T,i) (T).TI[(i)]

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
