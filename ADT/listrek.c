#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listrek.h"

/* *** Manajemen Memori *** */
address Alokasi (Kata X){
    address P;

    P = (address) malloc(sizeof(Kata));
    if(P==Nil){
        return(Nil);
    }
    else{
        strcpy(Info(P),X);
        Next(P) = Nil;
        return(P);
    }
}
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak Nil, dan misalnya menghasilkan P, 
  maka Info(P) = X, Next(P) = Nil */
/* Jika alokasi gagal, mengirimkan Nil */

void Dealokasi (address P){
    free(P);
}
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

/* *** Primitif-primitif yang harus direalisasikan *** */

/* Pemeriksaan Kondisi List */
int IsEmpty(List L){
    if(L==Nil){
        return 1;
    }
    else{
        return 0;
    }
}
/* Mengirimkan 1 jika L kosong dan 0 jika L tidak kosong */

int IsOneElmt(List L){
    if(NbElmtList(L) == 1){
        return 1;
    }
    else{
        return 0;
    }
}
/* Mengirimkan 1 jika L berisi 1 elemen dan 0 jika > 1 elemen atau kosong */

/* *** Selektor *** */
// Kata FirstElmt (List L){
//     return(Info(L));
// }
/* Mengirimkan elemen pertama sebuah list L yang tidak kosong */
List TailList(List L){
    return(Next(L));
}
/* Mengirimkan list L tanpa elemen pertamanya, mungkin menjadi list kosong */

/* *** Konstruktor *** */
List Konso(Kata e, List L){
    address P;
    
    P = Alokasi(e);
    if(P == Nil){
        return L;
    }
    else{
        Next(P) = L;
        return P;
    }
}
/* Mengirimkan list L dengan tambahan e sebagai elemen pertamanya. 
e dialokasi terlebih dahulu. Jika alokasi gagal, mengirimkan L. */

List KonsB(List L, Kata e){
    if(IsEmpty(L)){
        return (Alokasi(e));
    }
    else{
        Next(L) = KonsB(TailList(L),e);
    }
    return L;
}
/* Mengirimkan list L dengan tambahan e sebagai elemen pertamanya */
/* e harus dialokasi terlebih dahulu */
/* Jika alokasi e gagal, mengirimkan L */ 

/* *** Operasi Lain *** */
List Copy (List L){
    if(IsEmpty(L)){
        return(Nil);
    }
    else{
        return(Konso(Info(L),Copy(TailList(L))));
    }
}
/* Mengirimkan salinan list L (menjadi list baru) */
/* Jika ada alokasi gagal, mengirimkan L */ 

void MCopy (List Lin, List *Lout){
    List Ltemp;

    if(IsEmpty(Lin)){
        *Lout = Nil;
    }
    else{
        MCopy(TailList(Lin),&Ltemp);
        *Lout = Konso(Info(Lin),Ltemp);
    }
}
/* I.S. Lin terdefinisi */
/* F.S. Lout berisi salinan dari Lin */
/* Proses : menyalin Lin ke Lout */

List Concat (List L1, List L2){
    if(IsEmpty(L1)){
        return(Copy(L2));
    }
    else{
        return(Konso(Info(L1),Concat(TailList(L1),L2)));
    }
}
/* Mengirimkan salinan hasil konkatenasi list L1 dan L2 (menjadi list baru) */
/* Jika ada alokasi gagal, menghasilkan Nil */

void MConcat (List L1, List L2, List *LHsl){
    *LHsl = Nil;

    *LHsl = Concat(L1,L2);
}
/* I.S. L1, L2 terdefinisi */
/* F.S. LHsl adalah hasil melakukan konkatenasi L1 dan L2 dengan cara "disalin" */
/* Proses : Menghasilkan salinan hasil konkatenasi list L1 dan L2 */
void PrintList (List L){
    if(IsEmpty(L) == 1){
        //printf("\n");
    }
    else{
        printf("%s\n",Info(L));
        PrintList(TailList(L));
    }
}
/* I.S. L terdefinisi. */
/* F.S. Setiap elemen list dicetak. */

int NbElmtList (List L){
    if(IsEmpty(L)){
        return 0;
    }
    else{
        return (1+NbElmtList(TailList(L)));
    }
}
/* Mengirimkan banyaknya elemen list L, Nol jika L kosong */

boolean Search (List L, Kata X){
    if(IsEmpty(L)){
        return(false);
    }
    else{
        if(strcmp(Info(L),X) == 0){
            return(true);
        }
        else{
            return(Search(TailList(L),X));
        }
    }
}
/* Mengirim true jika X adalah anggota list, false jika tidak */