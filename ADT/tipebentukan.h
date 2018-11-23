#ifndef TIPEBENTUKAN_H
#define TIPEBENTUKAN_H

#include "boolean.h"


//---------------------------------------------------------STACK--------------------------------------------------------------------
#define IdxMax 10
#define NilS 0
#define MaxElStackt 10
/* Nil adalah stack dengan elemen kosong . */
/* Karena indeks dalam bhs C dimulai 0 maka tabel dg indeks 0 tidak dipakai */
typedef char Kata[50];
// typedef Kata infotype;
typedef int addressS;   /* indeks tabel */
typedef struct {
	Kata TI[IdxMax+1]; /* memori tempat penyimpan elemen (container) */
    addressS Top;
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

//-------------------------------------------------------ARRAY-----------------------------------------------------------------------
// #define IdxMax 100
/* Indeks maksimum array, sekaligus ukuran maksimum array dalam C */
#define IdxMin 1
/* Indeks minimum array */
#define IdxUndef -999 
/* Indeks tak terdefinisi*/

typedef char KataArray[10];
/* Definisi elemen dan koleksi objek */
typedef int IdxType;  /* type indeks */
typedef KataArray ArrayElType;   /* type elemen tabel */
typedef struct { 
	ArrayElType TI[100+1]; /* memori tempat penyimpan elemen (container) */
	int Neff; /* >=0, banyaknya elemen efektif */
} TabInt;
  
/* ********** SELEKTOR ********** */
#define Neff(T)   (T).Neff
#define TI(T)     (T).TI
#define Elmt(T,i) (T).TI[(i)]
//-----------------------------------------------------------------------------------------------------------------------------------

//-------------------------------------------------------QUEUE-----------------------------------------------------------------------
#define NilQ 0 /* Konstanta untuk mendefinisikan address tak terdefinisi */
typedef Customer infotypeCust;
typedef int addressQ;   /* indeks tabel */
typedef struct { infotypeCust * T;   /* tabel penyimpan elemen */
                 addressQ HEAD;  /* alamat penghapusan */
                 addressQ TAIL;  /* alamat penambahan */
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
	Stack FoodStack; /* Tray */
	Stack Hand;  /* Bahan Mentah */
    POINT Posisi; // posisi kolomg
    int room; // ruang mana
    Kata name;
    int money;
    int life;
    int time;
} Player;

#define FoodStack(P) (P).FoodStack
#define Hand(P) (P).Hand
#define Posisi(P) (P).Posisi
#define Room(P) (P).room
#define Name(P) (P).name
#define Money(P) (P).money
#define Life(P) (P).life
#define Time(P) (P).time
//-----------------------------------------------------------------------------------------------------------------------------------


//----------------------------------------------------------LISTREK------------------------------------------------------------------
#define Nil NULL

/* Definisi Type */
// typedef int infotype;
typedef struct tElmtlist *address;
typedef struct tElmtlist { 
	Kata info;
	address next;
} ElmtList;

/* Definisi list : */
/* List kosong : L = Nil */
typedef address List;

/* Deklarasi  nama untuk variabel kerja */ 
/*  	L : List */
/*  	P : address 	*/
/* Maka penulisan First(L) menjadi L */
/*                P.info menjadi Info(P); P.next menjadi Next(P) */

/* Selektor */
#define Info(P) (P)->info
#define Next(P) (P)->next
//-----------------------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------JAM------------------------------------------------------------------
typedef struct { 
	int HH; /* integer [0..23] */
	int MM; /* integer [0..59] */
	int SS; /* integer [0..59] */
} JAM;

/* *** Notasi Akses: selektor JAM *** */
#define Hour(J) (J).HH
#define Minute(J) (J).MM
#define Second(J) (J).SS
//-----------------------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------MATRIKS------------------------------------------------------------------
#define BrsMin 1
#define BrsMax 100
#define KolMin 1
#define KolMax 100

typedef int indeks; /* indeks baris, kolom */
// typedef int ElType; 
typedef struct { 
	char Mem[BrsMax+1][KolMax+1];
    int NBrsEff; /* banyaknya/ukuran baris yg terdefinisi */
	int NKolEff; /* banyaknya/ukuran kolom yg terdefinisi */
} MATRIKS;

#define NBrsEff(M) (M).NBrsEff
#define NKolEff(M) (M).NKolEff
#define MatriksElmt(M,i,j) (M).Mem[(i)][(j)]
//-----------------------------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------BINTREE-----------------------------------------------------------------------
typedef struct tNode *addrNode;
typedef struct tNode
{
  Kata info;
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


//-----------------------------------------------------MESINKATA-----------------------------------------------------------------------
#define NMax 50
#define BLANK ' '

typedef struct {
	char TabKata[NMax+1];  //container penyimpan kata, indeks yang dipakai [1..NMax] 
    int Length;
} MesinKata;

/* State Mesin Kata */
extern boolean EndKata;
extern MesinKata CKatan;
//-----------------------------------------------------------------------------------------------------------------------------------


//---------------------------------------------------------OTHERS--------------------------------------------------------------------
Queue AntrianLuar; //antrian di luar
BinTree Resep;
POINT DaftarMeja[5]; //Letak koordinat dari meja
Kata DaftarOrder[13]; //Daftar makanan yang dipesan, meja sesuai indeks
Customer arrayCust[13]; //Salinan customer ke meja
typedef char peta[9][9];
typedef peta ruang[5];
ruang ruangan;

#define MARK '.'
#define BLANK ' '
//-----------------------------------------------------------------------------------------------------------------------------------

#endif