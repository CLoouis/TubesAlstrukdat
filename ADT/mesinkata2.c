/* NIM/Nama  : 13517072/Kevin Nathaniel Wijaya
   Nama file : mesinkata.c
   Topik     : Praktikum 05
   Tanggal   : 21 September 2018
   Deskripsi : File Body ADT Matriks              */

/* File: mesinkata.h */
/* Definisi Mesin Kata: Model Akuisisi Versi I */

#include "mesinkata2.h"
// #include "tipebentukan.h"

Kata2 CKata2;
boolean EndKata2;


void IgnoreBlank2()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC2 sembarang
   F.S. : CC2 ≠ BLANK atau CC2 = MARK2 */
{
	/* Kamus Lokal */
	/* Algoritma */
	while (((CC2 == ' ') || (CC2 == '\n')) && (CC2 != MARK2))
	{
		ADV2();
	} /* CC2 != BLANK or CC2 = MARK2 */
}

void STARTKATA2()
/* I.S. : CC2 sembarang
   F.S. : EndKata = true, dan CC2 = MARK2;
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC2 karakter pertama sesudah karakter terakhir kata */
{
	/* Kamus Lokal */
	/* Algoritma*/
	START2();
	IgnoreBlank2();
	if (CC2 == MARK2)
  	{
		EndKata2 = true;
   	}
	else /* CC2 != MARK2 */
	{
		EndKata2 = false;
		SalinKata2();
	}
}

void ADVKATA2()
/* I.S. : CC2 adalah karakter pertama kata yang akan diakuisisi
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi,
          CC2 adalah karakter pertama dari kata berikutnya, mungkin MARK2
          Jika CC2 = MARK2, EndKata = true.
   Proses : Akuisisi kata menggunakan procedure SalinKata */
{
	/* Kamus Lokal */
	/* Algoritma*/
	IgnoreBlank2();
	if (CC2 == MARK2)
	{
		EndKata2 = true;
	}
	else /* CC2 != MARK2 */
	{
		SalinKata2();
		IgnoreBlank2();
	}
}

void SalinKata2()
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC2 adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi;
          CC2 = BLANK atau CC2 = MARK2;
          CC2 adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
{
	/* Kamus Lokal */
	int i = 0; /* inisialisasi */
	/* Algoritma*/
	for (;;)
	{
		CKata2.TabKata2[i] = CC2;
		ADV2();
		if (i >= NMax2)
		{
			break;
		}
		if ((CC2 == MARK2) || (CC2 == BLANK2) || (CC2 == '\n')) 
		{
			CKata2.TabKata2[i+1] = '\0';
			break;
		}
		else
		{
			i++;
		}
	} /* CC2 = MARK2 or CC2 = BLANK */
	CKata2.Length2 = i+1;
}
