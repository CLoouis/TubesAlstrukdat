/* Nama : Louis Cahyadi
NIM : 13517126
Nama File : matriks.c
Tanggal : 16 Sept 2018
*/

#include "../ADT_Lain/boolean.h"
#include "matriks.h"
#include "../ADT_Point/point.h"
#include "../ADT_Lain/tipebentukan.h"
#include <stdio.h>

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk MATRIKS *** */
void MakeMATRIKS (int NB, int NK, MATRIKS * M){
	NBrsEff(*M) = NB;
	NKolEff(*M) = NK;
}
/* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */

/* *** Selektor: Untuk sebuah matriks M yang terdefinisi: *** */
indeks GetFirstIdxBrs (MATRIKS M){
	return BrsMin;
}
/* Mengirimkan indeks baris terkecil M */
indeks GetFirstIdxKol (MATRIKS M){
	return KolMin;
}
/* Mengirimkan indeks kolom terkecil M */
indeks GetLastIdxBrs (MATRIKS M){
	return (GetFirstIdxBrs(M) + NBrsEff(M) - 1);
}
/* Mengirimkan indeks baris terbesar M */
indeks GetLastIdxKol (MATRIKS M){
	return (GetFirstIdxKol(M) + NKolEff(M) - 1);
}
/* Mengirimkan indeks kolom terbesar M */

/* ********** Assignment  MATRIKS ********** */
void CopyMATRIKS (MATRIKS MIn, MATRIKS * MHsl){
	indeks i,j;

	MakeMATRIKS(NBrsEff(MIn),NKolEff(MIn),MHsl);

	for (i = GetFirstIdxBrs(MIn); i <= GetLastIdxBrs(MIn);i++){
		for (j = GetFirstIdxKol(MIn); j <= GetLastIdxKol(MIn);j++){
			MatriksElmt(*MHsl,i,j) = MatriksElmt(MIn,i,j);
		}
	}
}
/* Melakukan assignment MHsl  MIn */

/* ********** KELOMPOK BACA/TULIS ********** */
void BacaMATRIKS (MATRIKS * M, int NB, int NK){
	indeks i,j;

	MakeMATRIKS(NB,NK,M);
	for (i = GetFirstIdxBrs(*M); i <= GetLastIdxBrs(*M);i++){
		for (j = GetFirstIdxKol(*M); j < GetLastIdxKol(*M);j++){
			scanf("%c ",&MatriksElmt(*M,i,j));
		}
		scanf("%c",&MatriksElmt(*M,i,GetLastIdxKol(*M)));
	}
}

/* I.S. IsIdxValid(NB,NK) */
/* F.S. M terdefinisi nilai elemen efektifnya, berukuran NB x NK */
/* Proses: Melakukan MakeMATRIKS(M,NB,NK) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika NB = 3 dan NK = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10
*/
void TulisMATRIKS (MATRIKS M){
	indeks i,j;

	for (i = GetFirstIdxBrs(M); i < GetLastIdxBrs(M);i++){
		for (j = GetFirstIdxKol(M); j < GetLastIdxKol(M);j++){
			printf("%c ",MatriksElmt(M,i,j));
		}
		printf("%c\n",MatriksElmt(M,i,GetLastIdxKol(M)));
	}
	i = GetLastIdxBrs(M);
	for (j = GetFirstIdxKol(M); j < GetLastIdxKol(M);j++){
		printf("%c ",MatriksElmt(M,i,j));
	}
	printf("%c\n",MatriksElmt(M,GetLastIdxBrs(M),GetLastIdxKol(M)));
}
/* I.S. M terdefinisi */
/* F.S. Nilai M(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen M ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/

/* ********** Operasi lain ********** */
int NBElmtMatriks (MATRIKS M){
	return (NBrsEff(M)*NKolEff(M));
}
/* Mengirimkan banyaknya elemen M */

void AmbilDataMatriks (MATRIKS *M){
	FILE *pFile;
	char Kata[100];
	int i,j;

	pFile = fopen("kitchen.txt","r");
	fscanf(pFile,"%s",Kata);
	for (i = 1; i <= 8; i++){
		for (j = 1; j <= 8; j++){
			MatriksElmt(*M,i,j) = Kata[8*(i-1) + (j-1)];
		}
	}
	fclose(pFile);
}

POINT SearchPosisiP(MATRIKS M){
	POINT Pemain;
	int i = GetFirstIdxBrs(M);
	int j = GetFirstIdxKol(M);
	boolean found = false;

	while (i <= GetLastIdxBrs(M) && !found){
		j = GetFirstIdxKol(M);
		while(j <= GetLastIdxKol(M) && !found){
			if (MatriksElmt(M,i,j) == 'P'){
				found = true;
			} else {
				j += 1;
			}
		}
		i += 1;
	} // Posisi P di M[i][j]
	Absis(Pemain) = i-1;
	Ordinat(Pemain) = j;
	return Pemain;

}
