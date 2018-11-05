/* Nama : Louis Cahyadi
NIM : 13517126
Nama File : matriks.c
Tanggal : 16 Sept 2018
*/

#include "boolean.h"
#include "matriks.h"
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

/* *** Selektor "DUNIA MATRIKS" *** */
boolean IsIdxValid (int i, int j){
	if ((i >= BrsMin && i <= BrsMax) && (j >= KolMin && j <= KolMax)){
		return true;
	} else {
		return false;
	}
}
/* Mengirimkan true jika i, j adalah indeks yang valid untuk matriks apa pun */

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
boolean IsIdxEff (MATRIKS M, indeks i, indeks j){
	if ((i >= GetFirstIdxBrs(M) && i <= GetLastIdxBrs(M)) && (j >= GetFirstIdxKol(M) && j <= GetLastIdxKol(M))){
		return true;
	} else {
		return false;
	}
}
/* Mengirimkan true jika i, j adalah indeks efektif bagi M */
MatriksElType GetElmtDiagonal (MATRIKS M, indeks i){
	return (MatriksElmt(M,i,i));
}
/* Mengirimkan elemen M(i,i) */

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


/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP MATRIKS ********** */
boolean EQ (MATRIKS M1, MATRIKS M2){
	indeks i,j;
	boolean cek;

	if (EQSize(M1,M2)){
		cek = true;
		i = GetFirstIdxBrs(M1);

		while (cek && i <= GetLastIdxBrs(M1)){
			j = GetFirstIdxKol(M1);
			while (cek && j <= GetLastIdxKol(M1)){
				if (MatriksElmt(M1,i,j) != MatriksElmt(M2,i,j)){
					cek = false;
				} else {
					j += 1;
				}
			}

			if (cek){
				i += 1;
			}
		}

		return cek;
	} else {
		return false;
	}
}
/* Mengirimkan true jika M1 = M2, yaitu NBMatriksElmt(M1) = NBMatriksElmt(M2) dan */
/* untuk setiap i,j yang merupakan indeks baris dan kolom M1(i,j) = M2(i,j) */
/* Juga merupakan strong EQ karena GetFirstIdxBrs(M1) = GetFirstIdxBrs(M2)
   dan GetLastIdxKol(M1) = GetLastIdxKol(M2) */
boolean NEQ (MATRIKS M1, MATRIKS M2){
	if (!EQ(M1,M2)){
		return true;
	} else {
		return false;
	}
}
/* Mengirimkan true jika M1 tidak sama dengan M2 */
boolean EQSize (MATRIKS M1, MATRIKS M2){
	if (NBrsEff(M1) == NBrsEff(M2) && NKolEff(M1) == NKolEff(M2)){
		return true;
	} else {
		return false;
	}
}
/* Mengirimkan true jika ukuran efektif matriks M1 sama dengan ukuran efektif M2 */
/* yaitu GetBrsEff(M1) = GetNBrsEff (M2) dan GetNKolEff (M1) = GetNKolEff (M2) */

/* ********** Operasi lain ********** */
int NBElmt (MATRIKS M){
	return (NBrsEff(M)*NKolEff(M));
}
/* Mengirimkan banyaknya elemen M */

/* ********** KELOMPOK TEST TERHADAP MATRIKS ********** */
boolean IsBujurSangkar (MATRIKS M){
	if (NBrsEff(M) == NKolEff(M)){
		return true;
	} else {
		return false;
	}
}
/* Mengirimkan true jika M adalah matriks dg ukuran baris dan kolom sama */

void AmbilDataMatriks (MATRIKS *M){
	FILE *pFile;
	MatriksElType X;
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
/* I.S. M terdefinisi dan IsBujursangkar(M) */
/* F.S. M "di-transpose", yaitu setiap elemen M(i,j) ditukar nilainya dengan elemen M(j,i) */
