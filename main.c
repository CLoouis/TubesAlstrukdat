#include <stdio.h>
#include "boolean.h"
#include "commandlouis.h"
#include "array.h"
#include "matriks.h"
#include "point.h"


int main(){
    int input1;

    int indexUser;
    POINT Pemain;
    char nama[10];
    TabInt User;
    MakeEmpty(&User);

    MATRIKS Kitchen;
    MakeMATRIKS(8,8,&Kitchen);

    tampilanAwal();
    menu(&input1);
    AmbilDataArray(&User);
    while (input1 != 4){
        if (input1 == 1){
            newGame(&User,&nama);
        } else if (input1 == 2){
            AmbilDataMatriks(&Kitchen);
            TulisMATRIKS(Kitchen);
            printf("\n");
            Pemain = SearchPosisiP(Kitchen);
            printf("Nih nyoba GoUp\n");
            GoUp(Pemain,&Kitchen);
            TulisMATRIKS(Kitchen);
            printf("Nih nyoba GoDown\n");
            GoDown(Pemain,&Kitchen);
            TulisMATRIKS(Kitchen);
            printf("Nih nyoba GoLeft\n");
            GoLeft(Pemain,&Kitchen);
            TulisMATRIKS(Kitchen);
            printf("Nih nyoba GoDown\n");
            GoRight(Pemain,&Kitchen);
            TulisMATRIKS(Kitchen);
        } else if (input1 == 3){
            loadGame(User,&nama,&indexUser);
        }
        menu(&input1);
    }
}
