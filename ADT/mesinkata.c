/* NIM/Nama  : 13517072/Kevin Nathaniel Wijaya
   Nama file : mesinkata.c
   Topik     : Praktikum 05
   Tanggal   : 21 September 2018
   Deskripsi : File Body ADT Matriks              */

/* File: mesinkata.h */
/* Definisi Mesin Kata: Model Akuisisi Versi I */

#include "mesinkata.h"
// #include "tipebentukan.h"

Kata CKata;
boolean EndKata;


void IgnoreBlank()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK atau CC = MARK */
{
	/* Kamus Lokal */
	/* Algoritma */
	while (((CC == ' ') || (CC == '\n')) && (CC != MARK))
	{
		ADV();
	} /* CC != BLANK or CC = MARK */
}

void STARTKATA()
/* I.S. : CC sembarang
   F.S. : EndKata = true, dan CC = MARK;
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */
{
	/* Kamus Lokal */
	/* Algoritma*/
	START();
	IgnoreBlank();
	if (CC == MARK)
  	{
		EndKata = true;
   	}
	else /* CC != MARK */
	{
		EndKata = false;
		SalinKata();
	}
}

void ADVKATA()
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi,
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndKata = true.
   Proses : Akuisisi kata menggunakan procedure SalinKata */
{
	/* Kamus Lokal */
	/* Algoritma*/
	IgnoreBlank();
	if (CC == MARK)
	{
		EndKata = true;
	}
	else /* CC != MARK */
	{
		SalinKata();
		IgnoreBlank();
	}
}

void SalinKata()
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi;
          CC = BLANK atau CC = MARK;
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
{
	/* Kamus Lokal */
	int i = 0; /* inisialisasi */
	/* Algoritma*/
	for (;;)
	{
		CKata.TabKata[i] = CC;
		ADV();
		if (i >= NMax)
		{
			break;
		}
		if ((CC == MARK) || (CC == ' ') || (CC == '\n')) 
		{
			CKata.TabKata[i+1] = '\0';
			break;
		}
		else
		{
			i++;
		}
	} /* CC = MARK or CC = BLANK */
	CKata.Length = i+1;
}
