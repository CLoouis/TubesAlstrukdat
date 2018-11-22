#ifndef TIPEBENTUKAN_H
#define TIPEBENTUKAN_H

#include "boolean.h"


//---------------------------------------------------------STACK--------------------------------------------------------------------
#define IdxMax 10
#define Nil 0
#define MaxElStackt 10
/* Nil adalah stack dengan elemen kosong . */
/* Karena indeks dalam bhs C dimulai 0 maka tabel dg indeks 0 tidak dipakai */
typedef char Kata[50];
typedef Kata infotype;
typedef int address;   /* indeks tabel */
typedef struct {
	infotype TI[IdxMax+1]; /* memori tempat penyimpan elemen (container) */
    address Top;
} Stack;
#define Top(S) (S).Top
#define InfoTop(S) (S).TI[(S).Top]
//-----------------------------------------------------------------------------------------------------------------------------------


//--------------------------------------------------------POINT----------------------------------------------------------------------
typedef struct {
	int X; /* absis   */
	int Y; /* ordinat */
} POINT;
#define Absis(P) (P).X
#define Ordinat(P) (P).Y
//-----------------------------------------------------------------------------------------------------------------------------------


//-------------------------------------------------------CUSTOMER-----------------------------------------------------------------------
typedef struct{
    int jumlah;
    int patience;
    int qpatience;// patience di queue
    Kata order;
    boolean isi; // apakah si customer sudah pergi atau belum 
}Customer;
//-----------------------------------------------------------------------------------------------------------------------------------


//-------------------------------------------------------QUEUE-----------------------------------------------------------------------
typedef Customer infotypeCust;
typedef int address;   /* indeks tabel */
typedef struct { infotypeCust * T;   /* tabel penyimpan elemen */
                 address HEAD;  /* alamat penghapusan */
                 address TAIL;  /* alamat penambahan */
                 int MaxElQueue;     /* Max elemen queue */
               } Queue;

#define Head(Q) (Q).HEAD
#define Tail(Q) (Q).TAIL
#define InfoHead(Q) (Q).T[(Q).HEAD]
#define InfoTail(Q) (Q).T[(Q).TAIL]
#define MaxElQueue(Q) (Q).MaxElQueue
//-----------------------------------------------------------------------------------------------------------------------------------


//-------------------------------------------------------PLAYER-----------------------------------------------------------------------
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
//-----------------------------------------------------------------------------------------------------------------------------------


//-----------------------------------------------------BINTREE-----------------------------------------------------------------------
typedef struct tNode *addrNode;
typedef struct tNode
{
  infotype info;
  addrNode left;
  addrNode right;
} Node;

/* Definisi PohonBiner : */
/* Pohon Biner kosong : P = Nil */
typedef addrNode BinTree;

/* *** PROTOTYPE *** */

/* *** Selektor *** */
#define Akar(P) (P)->info
#define Left(P) (P)->left
#define Right(P) (P)->right
//-----------------------------------------------------------------------------------------------------------------------------------

//---------------------------------------------------------OTHERS--------------------------------------------------------------------
Queue AntrianLuar; //antrian di luar
POINT DaftarMeja[5]; //Letak koordinat dari meja
Kata DaftarOrder[13]; //Daftar makanan yang dipesan, meja sesuai indeks
Customer arrayCust[13]; //Salinan customer ke meja
#define MARK '.'
//-----------------------------------------------------------------------------------------------------------------------------------

#endif
