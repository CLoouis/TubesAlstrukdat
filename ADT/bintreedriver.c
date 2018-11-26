#include "bintree.h"
#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    BinTree R2,L2,T,L,R;
    infotype temp;
    List daftar;

    L2 = Nil;
    L = AlokNode(3);
    R2 = AlokNode(9);
    R = Tree(7,L2,R2);
    T = Tree(5,L,R);
    //PrintPreorder(T);
    AddDaun(&T,3,4,5>2);
    //printf("%d\n",Info(T));
    //printf("\n");
    //PrintPreorder(T);
    //DelDaunTerkiri(&T,&temp);
    //printf("\n");
    //PrintPreorder(T);
    //printf("\n");
    //PrintInorder(T);
    //printf("\n");
    //PrintPostorder(T);
    PrintTree(T,3);
    //daftar = MakeListLevel(T,2);
    //PrintList(daftar);
    printf("\n%d\n",Level(T,4));
    if(SearchTree(T,9)) printf("\nketemu\n");
    printf("Jumlah elemen ada %d\n",NbElmt(T));
    printf("Jumlah daun ada %d\n",NbDaun(T));
    printf("Tinggi pohon adalah %d\n",Tinggi(T));
    if(IsSkewLeft(T)){
        printf("Rata kiri\n");
    }
    if(IsSkewRight(T)){
        printf("Rata kanan\n");
    }
    return 0;
}
