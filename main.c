#include <stdio.h>
#include "ADT/boolean.h"
#include "command/commandlouis.h"
#include "ADT/array.h"
#include "ADT/matriks.h"
#include "ADT/point.h"
#include "ADT/stackt.h"
#include "ADT/mesinkar.h"
#include "ADT/mesinkata.h"
#include <string.h>

int main(){
    //Variable untuk menu awal
    int input1;
    int indexUser;
    char name[10];
    TabInt User;
    MakeEmpty(&User);

    //Create Pemain
    Player Pemain;
    CreateStackEmpty(&FoodStack(Pemain));
    CreateStackEmpty(&Hand(Pemain));
    Room(Pemain) = 4;

    //Create peta semua ruangan
    MATRIKS ruang[5];
    MakeMATRIKS (8,8,&ruang[1]);
    MakeMATRIKS (8,8,&ruang[2]);
    MakeMATRIKS (8,8,&ruang[3]);
    MakeMATRIKS (8,8,&ruang[4]);

    //Variable untuk import dari file eksternal
    int i,j;
    char Nama[NMax+1]; //Nama di file eksternal
    int Money;
    int Life;
    int Time;
    printf("Cek\n");
    STARTKATA();
    printf("cek\n");
    printf("%s\n", CKata.TabKata);
    while(CC != MARK){
        //printf("%s\n", CKata.TabKata);
        if (strcmp(CKata.TabKata, "Name") == 0){
            printf("%s\n", CKata.TabKata);
            while (CC == ' ' || CC == '\n'){
                ADV();
            }
            ADVKATA();
            // printf("%s\n", CKata.TabKata);
            strcpy(Nama,CKata.TabKata);
        }
        else if (strcmp(CKata.TabKata, "Money") == 0){
            while (CC == ' ' || CC == '\n'){
                ADV();
            }
            ADVKATA();
            Money = 0;
            for (i = 0; i <= CKata.Length-1; i++){
                Money *= 10;
                Money += (int)CKata.TabKata[i] - 48;
            }
        }
        else if (strcmp(CKata.TabKata, "Life") == 0){
            while (CC == ' ' || CC == '\n'){
                ADV();
            }
            ADVKATA();
            Life = 0;
            for (i = 0; i <= CKata.Length-1; i++){
                Life *= 10;
                Life += (int)CKata.TabKata[i] - 48;
            }
        }
        else if (strcmp(CKata.TabKata, "Time") == 0){
            while (CC == ' ' || CC == '\n'){
                ADV();
            }
            ADVKATA();
            Time = 0;
            for (i = 0; i <= CKata.Length-1; i++){
                Time *= 10;
                Time += (int)CKata.TabKata[i] - 48;
            }
        }
        else if (strcmp(CKata.TabKata, "Kitchen") == 0){
            while (CC == ' ' || CC == '\n'){
                ADV();
            }
            i = 1;
            j = 1;
            while (i != 9){
                while (CC == ' ' || CC == '\n'){
                    ADV();
                }
                MatriksElmt(ruang[4],i,j) = CC;
                //ruang[1][i][j] = CC;
                ADV();
                j++;
                if(j == 9){
                    j = 1;
                    i++;
                }
            }
        }
        else if (strcmp(CKata.TabKata, "Room1") == 0){
            while (CC == ' ' || CC == '\n'){
                ADV();
            }
            i = 1;
            j = 1;
            while (i != 9){
                while (CC == ' ' || CC == '\n'){
                    ADV();
                }
                MatriksElmt(ruang[1],i,j) = CC;
                //ruang[2][i][j] = CC;
                ADV();
                j++;
                if(j == 9){
                    j = 1;
                    i++;
                }
            }
        }
        else if (strcmp(CKata.TabKata, "Room2") == 0){
            while (CC == ' ' || CC == '\n'){
                ADV();
            }
            i = 1;
            j = 1;
            while (i != 9){
                while (CC == ' ' || CC == '\n'){
                    ADV();
                }
                MatriksElmt(ruang[2],i,j) = CC;
                //ruang[3][i][j] = CC;
                ADV();
                j++;
                if(j == 9){
                    j = 1;
                    i++;
                }
            }
        }
        else if (strcmp(CKata.TabKata, "Room3") == 0){
            while (CC == ' ' || CC == '\n'){
                ADV();
            }
            i = 1;
            j = 1;
            while (i != 9){
                while (CC == ' ' || CC == '\n'){
                    ADV();
                }
                MatriksElmt(ruang[3],i,j) = CC;
                //ruang[4][i][j] = CC;
                ADV();
                j++;
                if(j == 9){
                    j = 1;
                    i++;
                }
            }
        }
        while (CC == ' ' || CC == '\n'){
            ADV();
        }
        ADVKATA();
    }
    printf("Nama: %s\n", Nama);
    printf("Money: %d\n", Money);
    printf("Life: %d\n", Life);
    printf("Time: %d\n", Time);
    printf("Kitchen: \n");
    for(i=1;i<=8;i++){
        for(j=1;j<=8;j++){
            printf("%c ",MatriksElmt(ruang[4],i,j));
        }
        printf("\n");
    }
    printf("Ruang 1: \n");
    for(i=1;i<=8;i++){
        for(j=1;j<=8;j++){
            printf("%c ",MatriksElmt(ruang[1],i,j));
        }
        printf("\n");
    }
    printf("Ruang 2: \n");
    for(i=1;i<=8;i++){
        for(j=1;j<=8;j++){
            printf("%c ",MatriksElmt(ruang[2],i,j));
        }
        printf("\n");
    }
    printf("Ruang 3: \n");
    for(i=1;i<=8;i++){
        for(j=1;j<=8;j++){
            printf("%c ",MatriksElmt(ruang[3],i,j));
        }
        printf("\n");
    }


    tampilanAwal();
    menu(&input1);
    AmbilDataArray(&User);
    while (input1 != 4){
        if (input1 == 1){
            newGame(&User,&name);
        } else if (input1 == 2){
            TulisMATRIKS(ruang[4]);
            printf("\n");
            GoUp(&Pemain,&ruang[4]);
            TulisMATRIKS(ruang[4]);
            printf("\n");
            GoDown(&Pemain,&ruang[4]);
            TulisMATRIKS(ruang[4]);
            printf("\n");
            GoLeft(&Pemain,&ruang[4]);
            TulisMATRIKS(ruang[4]);
            printf("\n");
            GoRight(&Pemain,&ruang[4]);
            TulisMATRIKS(ruang[4]);
            printf("%d, %d, %d\n",Room(Pemain),Absis(Posisi(Pemain)),Ordinat(Posisi(Pemain)));
        } else if (input1 == 3){
            loadGame(User,&name,&indexUser);
        }
        menu(&input1);
    }
}
