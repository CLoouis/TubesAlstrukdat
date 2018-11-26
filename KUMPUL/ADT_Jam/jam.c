/* NIM/Nama  : 13517072/Kevin Nathaniel Wijaya
   Nama file : jam.c
   Topik     : Tugas Pra Praktikum 02
   Tanggal   : 5 September 2018
   Deskripsi : File Body ADT Jam              */

#include "jam.h"
#include "../ADT_Lain/tipebentukan.h"
#include<stdio.h>

/* ***************************************************************** */
/* DEFINISI PRIMITIF                                                 */
/* ***************************************************************** */
/* KELOMPOK VALIDASI TERHADAP TYPE                                   */
/* ***************************************************************** */

boolean IsJAMValid (int H, int M, int S)
/* Mengirim true  jika H,M,S dapat membentuk J yang valid */
/* dipakai untuk mentest SEBELUM membentuk sebuah Jam */
{
	/* KAMUS */

	/* ALGORITMA */
	return (((H<=23)&&(H>=0))&&((M<=59)&&(M>=0))&&((S<=59)&&(S>=0)));
}

/* *** Konstruktor: Membentuk sebuah JAM dari komponen-komponennya *** */
JAM MakeJAM (int HH, int MM, int SS)
/* Membentuk sebuah JAM dari komponen-komponennya yang valid */
/* Prekondisi : HH, MM, SS valid untuk membentuk JAM */
{
	/* KAMUS */
	JAM T;
	/* ALGORITMA */
	Hour(T) = HH;
	Minute(T) = MM;
	Second(T) = SS;
	return T;
}

/* ***************************************************************** */
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */
void BacaJAM (JAM * J)
/* I.S. : J tidak terdefinisi */
/* F.S. : J terdefinisi dan merupakan jam yang valid */
/* Proses : mengulangi membaca komponen HH, MM, SS sehingga membentuk J */
/* yang valid. Tidak mungkin menghasilkan J yang tidak valid. */
/* Pembacaan dilakukan dengan mengetikkan komponen HH, MM, SS
   dalam satu baris, masing-masing dipisahkan 1 spasi, diakhiri enter. */
/* Jika JAM tidak valid maka diberikan pesan: "Jam tidak valid", dan pembacaan
   diulangi hingga didapatkan jam yang valid. */
/* Contoh:
   60 3 4
   Jam tidak valid
   1 3 4
   --> akan terbentuk JAM <1,3,4> */
{
	/* KAMUS */
	int a,b,c;
	/* ALGORITMA */
	scanf("%d %d %d", &a, &b, &c);
	while (!(IsJAMValid(a,b,c)))
	{
		printf("Jam tidak valid\n");
		scanf("%d %d %d", &a, &b, &c);
	}
	*J = MakeJAM(a,b,c);
}

void TulisJAM (JAM J)
/* I.S. : J sembarang */
/* F.S. : Nilai J ditulis dg format HH:MM:SS */
/* Proses : menulis nilai setiap komponen J ke layar dalam format HH:MM:SS
   tanpa karakter apa pun di depan atau belakangnya, termasuk spasi, enter, dll.*/
{
	/* KAMUS */
	/* ALGORITMA */
	printf("%d:%d:%d", Hour(J), Minute(J), Second(J));
}


/* ***************************************************************** */
/* KELOMPOK KONVERSI TERHADAP TYPE                                   */
/* ***************************************************************** */
long JAMToDetik (JAM J)
/* Diberikan sebuah JAM, mengkonversi menjadi jumlah detik dari pukul 0:0:0 */
/* Rumus : detik = 3600*HH + 60*MM + SS */
/* Nilai maksimum = 3600*23+59*60+59 */
{
	/* KAMUS */
	/* ALGORITMA */
	return ((Hour(J) * 3600) + (Minute(J) * 60) + Second(J));
}

JAM DetikToJAM (long N)
/* Mengirim  konversi detik ke JAM */
/* Catatan: Jika N >= 86400, maka harus dikonversi dulu menjadi jumlah detik yang
   mewakili jumlah detik yang mungkin dalam 1 hari, yaitu dengan rumus:
   N1 = N mod 86400, baru N1 dikonversi menjadi JAM */
{
	/* KAMUS */
	long N1;
	JAM J;
	/* ALGORITMA */
	N1 = N % 86400;
	Hour(J) = N1 / 3600 ;
	Minute(J) = (N1 % 3600) / 60;
	Second(J) = (N1 % 3600) % 60;
	return J;
}

/* ***************************************************************** */
/* KELOMPOK OPERASI TERHADAP TYPE                                    */
/* ***************************************************************** */
/* *** Kelompok Operator Relational *** */
boolean JEQ (JAM J1, JAM J2)
/* Mengirimkan true jika J1=J2, false jika tidak */
{
	/* KAMUS */
	/* ALGORITMA */
	return(JAMToDetik(J1) == JAMToDetik(J2));
}

boolean JNEQ (JAM J1, JAM J2)
/* Mengirimkan true jika J1 tidak sama dengan J2 */
{
	/* KAMUS */
	/* ALGORITMA */
	return(JAMToDetik(J1) != JAMToDetik(J2));
}

boolean JLT (JAM J1, JAM J2)
/* Mengirimkan true jika J1<J2, false jika tidak */
{
	/* KAMUS */
	/* ALGORITMA */
	return(JAMToDetik(J1) < JAMToDetik(J2));
}

boolean JGT (JAM J1, JAM J2)
/* Mengirimkan true jika J1>J2, false jika tidak */
{
	/* KAMUS */
	/* ALGORITMA */
	return(JAMToDetik(J1) > JAMToDetik(J2));
}

/* *** Operator aritmatika JAM *** */
JAM NextDetik (JAM J)
/* Mengirim 1 detik setelah J dalam bentuk JAM */
{
	/* KAMUS */
	int x;
	/* ALGORITMA */
	x = JAMToDetik(J);
	x++;
	return (DetikToJAM(x));
}

JAM NextNDetik (JAM J, int N)
/* Mengirim N detik setelah J dalam bentuk JAM */
{
	/* KAMUS */
	int x;
	/* ALGORITMA */
	x = JAMToDetik(J);
	x += N;
	while (x > ((24*3600) - 1))
	{
		x -= (24*3600);
	}
	return (DetikToJAM(x));
}

JAM PrevDetik (JAM J)
/* Mengirim 1 detik sebelum J dalam bentuk JAM */
{
	/* KAMUS */
	int x;
	/* ALGORITMA */
	x = JAMToDetik(J);
	x--;
	return (DetikToJAM(x));
}

JAM PrevNDetik (JAM J, int N)
/* Mengirim N detik sebelum J dalam bentuk JAM */
/* *** Kelompok Operator Aritmetika *** */
{
	/* KAMUS */
	int x;
	/* ALGORITMA */
	x = JAMToDetik(J);
	x -= N;
	while (x<0)
	{
		x += (24*3600);
	}
	return (DetikToJAM(x));
}

long Durasi (JAM JAw, JAM JAkh)
/* Mengirim JAkh-JAw dlm Detik, dengan kalkulasi */
/* Jika JAw > JAkh, maka JAkh adalah 1 hari setelah JAw */
{
	/* KAMUS */
	/* ALGORITMA */
	if (JGT(JAw, JAkh))
	{
		return (JAMToDetik(JAkh) - JAMToDetik(JAw) + (24*3600));
	}
	else
	{
		return (JAMToDetik(JAkh) - JAMToDetik(JAw));
	}
}
