#ifndef TIPEBENTUKAN_H
#define TIPEBENTUKAN_H

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


#define IdxMax 9
#define IdxMin 0
#define IdxUndef -999

/* Definisi elemen dan koleksi objek */
typedef char KataArray[10];
typedef int IdxType;  /* type indeks */
typedef KataArray ArrayElType;   /* type elemen tabel */
typedef struct {
	ArrayElType TI[IdxMax+1]; /* memori tempat penyimpan elemen (container) */
	int Neff; /* >=0, banyaknya elemen efektif */
} TabInt;

//Selektor
#define Neff(T) (T).Neff
#define TI(T) (T).TI
#define ArrayElmt(T,i) (T).TI[(i)]


typedef struct {
	int HH; /* integer [0..23] */
	int MM; /* integer [0..59] */
	int SS; /* integer [0..59] */
} JAM;

/* *** Notasi Akses: selektor JAM *** */
#define Hour(J) (J).HH
#define Minute(J) (J).MM
#define Second(J) (J).SS





#define BrsMin 1
#define BrsMax 10
#define KolMin 1
#define KolMax 10

typedef int indeks; /* indeks baris, kolom */
typedef char MatriksElType;
typedef struct {
	MatriksElType Mem[BrsMax+1][KolMax+1];
    int NBrsEff; /* banyaknya/ukuran baris yg terdefinisi */
	int NKolEff; /* banyaknya/ukuran kolom yg terdefinisi */
} MATRIKS;
#define NBrsEff(M) (M).NBrsEff
#define NKolEff(M) (M).NKolEff
#define MatriksElmt(M,i,j) (M).Mem[(i)][(j)]



#define MARK '.'
#endif
