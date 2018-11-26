#include <stdio.h>
#include "../ADT/boolean.h"
#include "../ADT/matriks.h"


void CariDet(MATRIKS M){
    int baref,kolef,i,k,j;
    float tabel[M.NBrsEff+1][M.NKolEff+1];
    float pembagi,totalpembagi;
    baref = M.NBrsEff;
    kolef = M.NKolEff;
    totalpembagi = 1;
    //Salin Matriks M ke matriks float
    for(i=GetFirstIdxBrs(M);i<=GetLastIdxBrs(M);i++){
        for(j=GetFirstIdxKol(M);j<=GetLastIdxKol(M);j++){
            tabel[i][j] = M.Mem[i][j];
        }
    }

    for(k=GetFirstIdxBrs(M);k<GetLastIdxBrs(M);k++){
        //Membagi dengan angka kolom pertama
        for(i=k;i<=GetLastIdxBrs(M);i++){
            pembagi = tabel[i][k];
            totalpembagi *= pembagi;
            for(j=k;j<=GetLastIdxKol(M);j++){
                tabel[i][j] = (tabel[i][j])/pembagi;
            }
        }
        //Mengurangi dengan kolom atasnya
        for(i=k+1;i<=GetLastIdxBrs(M);i++){
            for(j=k;j<=GetLastIdxKol(M);j++){
                tabel[i][j]=tabel[i][j]-tabel[k][j];
            }
        }
    }

    //TulisMatriks
    for(i=GetFirstIdxBrs(M);i<=GetLastIdxBrs(M);i++){
        for(j=GetFirstIdxKol(M);j<GetLastIdxKol(M);j++){
            printf("%f ",tabel[i][j]);
        }
        printf("%f\n",tabel[i][GetLastIdxKol(M)]);
    }
    printf("Determinannya adalah %f",totalpembagi*tabel[GetLastIdxBrs(M)][GetLastIdxKol(M)]);
}

int main(){
    int i,j,a,b;
    MATRIKS M,CopyM;
    printf("Masukkan nilai efektif baris dan kolom matriks\n");
    scanf("%d %d",&i,&j);  
    printf("Baca Matriks\n");
    BacaMATRIKS(&M,i,j);
    printf("%d\n",NBElmtMatriks(M));

}