#include <stdio.h>
#include "boolean.h"
#include "commandlouis.h"
#include "array.h"
#include "matriks.h"

int main(){
    int input1;

    int indexUser;
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
        } else if (input1 == 3){
            loadGame(User,&nama,&indexUser);
        }
        menu(&input1);
    }
}
