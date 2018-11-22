/* NAMA-NIM : Louis Cahyadi-13517126
File: point.c
Tanggal: 06 September 2018
Implementasi ABSTRACT DATA TYPE POINT */


#include <stdio.h>
#include <math.h>
#include "point.h"
#include "boolean.h"
//#include "tipebentukan.h"


/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk POINT *** */
POINT MakePOINT (int X, int Y){
    POINT P;

    Absis(P) = X;
    Ordinat(P) = Y;
    return P;
}
/* Membentuk sebuah POINT dari komponen-komponennya */

/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */
void BacaPOINT (POINT * P){
    int X,Y;

    scanf("%d %d",&X,&Y);
    *P = MakePOINT(X,Y);
}
/* Membaca nilai absis dan ordinat dari keyboard dan membentuk
   POINT P berdasarkan dari nilai absis dan ordinat tersebut */
/* Komponen X dan Y dibaca dalam 1 baris, dipisahkan 1 buah spasi */
/* Contoh: 1 2
   akan membentuk POINT <1,2> */
/* I.S. Sembarang */
/* F.S. P terdefinisi */
void TulisPOINT (POINT P){
    printf("(%d,%d)\n",Absis(P),Ordinat(P));
}
/* Nilai P ditulis ke layar dengan format "(X,Y)"
   tanpa spasi, enter, atau karakter lain di depan, belakang,
   atau di antaranya
   Output X dan Y harus dituliskan dalam bilangan riil dengan 2 angka di belakang koma.
*/
/* I.S. P terdefinisi */
/* F.S. P tertulis di layar dengan format "(X,Y)" */

/* *** Kelompok operasi relasional terhadap POINT *** */
boolean EQ (POINT P1, POINT P2){
    if (Absis(P1) == Absis(P2) && Ordinat(P1) == Ordinat(P2)){
        return true;
    } else {
        return false;
    }
}
/* Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama */
boolean NEQ (POINT P1, POINT P2){
    if (Absis(P1) != Absis(P2) || Ordinat(P1) != Ordinat(P2)){
        return true;
    } else {
        return false;
    }
}
/* Mengirimkan true jika P1 tidak sama dengan P2 */

/* *** Kelompok menentukan di mana P berada *** */
boolean IsOrigin (POINT P){
    if (Absis(P) == 0 && Ordinat(P) == 0){
        return true;
    } else {
        return false;
    }
}
/* Menghasilkan true jika P adalah titik origin */
boolean IsOnSbX (POINT P){
    if (Ordinat(P) == 0){
        return true;
    } else {
        return false;
    }
}
/* Menghasilkan true jika P terletak Pada sumbu X */
boolean IsOnSbY (POINT P){
    if (Absis(P) == 0){
        return true;
    } else {
        return false;
    }
}
/* Menghasilkan true jika P terletak pada sumbu Y */
int Kuadran (POINT P){
    if (Absis(P) > 0 && Ordinat(P) > 0){
        return 1;
    } else if (Absis(P) < 0 && Ordinat(P) > 0){
        return 2;
    } else if (Absis(P) < 0 && Ordinat(P) < 0){
        return 3;
    } else {
        return 4;
    }
}
/* Menghasilkan kuadran dari P: 1, 2, 3, atau 4 */
/* Prekondisi : P bukan titik origin, */
/*              dan P tidak terletak di salah satu sumbu */

/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */
POINT NextX (POINT P){
    POINT Q;
    Q = MakePOINT(Absis(P)+1,Ordinat(P));
    return Q;
}
/* Mengirim salinan P dengan absis ditambah satu */
POINT NextY (POINT P){
    POINT Q;
    Q = MakePOINT(Absis(P),Ordinat(P)+1);
    return Q;
}
/* Mengirim salinan P dengan ordinat ditambah satu */
POINT PlusDelta (POINT P, int deltaX, int deltaY){
    POINT Q;
    Q = MakePOINT(Absis(P) + deltaX,Ordinat(P) + deltaY);
    return Q;
}
/* Mengirim salinan P yang absisnya adalah Absis(P) + deltaX dan ordinatnya adalah Ordinat(P) + deltaY */
POINT MirrorOf (POINT P, boolean SbX){
    POINT Q;

    if (SbX){
        Ordinat(Q) = Ordinat(P) - 2*Ordinat(P);
        Absis(Q) = Absis(P);
    } else {
        Absis(Q) = Absis(P) - 2*Absis(P);
        Ordinat(Q) = Ordinat(P);
    }

    return Q;
}
/* Menghasilkan salinan P yang dicerminkan terhadap salah satu sumbu */
/* Jika SbX bernilai true, maka dicerminkan terhadap sumbu X */
/* Jika SbX bernilai false, maka dicerminkan terhadap sumbu Y */
int Jarak0 (POINT P){
    int JKuadrat;

    JKuadrat = pow(Absis(P),2) + pow(Ordinat(P),2);
    return sqrt(JKuadrat);
}
/* Menghitung jarak P ke (0,0) */
int Panjang (POINT P1, POINT P2){
    int JKuadrat;

    JKuadrat = pow(Absis(P1) - Absis(P2),2) + pow(Ordinat(P1) - Ordinat(P2),2);
    return sqrt(JKuadrat);
}
/* Menghitung panjang garis yang dibentuk P1 dan P2 */
/* Perhatikanlah bahwa di sini spec fungsi kurang baik sebab menyangkut ADT Garis. */
/* Tuliskan spec fungsi yang lebih tepat. */
void Geser (POINT *P, int deltaX, int deltaY){
    Absis(*P) = Absis(*P) + deltaX;
    Ordinat(*P) = Ordinat(*P) + deltaY;
}
/* I.S. P terdefinisi */
/* F.S. P digeser, absisnya sebesar deltaX dan ordinatnya sebesar deltaY */
void GeserKeSbX (POINT *P){
    Ordinat(*P) = 0;
}
/* I.S. P terdefinisi */
/* F.S. P berada pada sumbu X dengan absis sama dengan absis semula. */
/* Proses : P digeser ke sumbu X. */
/* Contoh : Jika koordinat semula (9,9), maka menjadi (9,0) */
void GeserKeSbY (POINT *P){
    Absis(*P) = 0;
}
/* I.S. P terdefinisi*/
/* F.S. P berada pada sumbu Y dengan ordinat yang sama dengan semula. */
/* Proses : P digeser ke sumbu Y. */
/* Contoh : Jika koordinat semula (9,9), maka menjadi (0,9) */
void Mirror (POINT *P, boolean SbX){
    if (SbX){
        Ordinat(*P) = Ordinat(*P) - 2*Ordinat(*P);
    } else {
        Absis(*P) = Absis(*P) - 2*Absis(*P);
    }
}
/* I.S. P terdefinisi */
/* F.S. P dicerminkan tergantung nilai SbX atau SbY */
/* Jika SbX true maka dicerminkan terhadap sumbu X */
/* Jika SbX false maka dicerminkan terhadap sumbu Y */
void Putar (POINT *P, int Sudut){
    int radian;
    POINT Q;

    //radian = Sudut*(M_PI/180);
    //Absis(Q) = cos(radian)*Absis(*P) - sin(radian)*Ordinat(*P);
    //Ordinat(Q) = sin(radian)*Absis(*P) + cos(radian)*Ordinat(*P);

    *P = Q;
}
/* I.S. P terdefinisi */
/* F.S. P digeser sebesar Sudut derajat dengan sumbu titik (0,0) */