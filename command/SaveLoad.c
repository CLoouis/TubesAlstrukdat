#include <stdio.h>
#include <string.h>
#include "../ADT/tipebentukan.h"
#include "../ADT/mesinkata.h"
#include "../ADT/mesinkar.h"
#include "../ADT/boolean.h"
#include "../ADT/stackt.h"
#include "SaveLoad.h"

// (int)strtol(<string>, (char **)NULL, 10);

void Load (Player *P, Queue *AntrianLuar, ruang *ruangan){
    // typedef char peta[9][9];
    // peta ruang[5];
    int i,j;
    Kata test;
    // char Nama[NMax+1];
    // int Money;
    // int Life;
    // int Time;

    STARTKATA();
    while(CC != MARK){
        if (strcmp(CKata.TabKata, "Name") == 0){
            // printf("%s\n", CKata.TabKata);
            while (CC == ' ' || CC == '\n'){    
                ADV();
            }
            ADVKATA();
            // printf("%s\n", CKata.TabKata);
            strcpy(Name(*P),CKata.TabKata);
        }
        else if (strcmp(CKata.TabKata, "Money") == 0){
            while (CC == ' ' || CC == '\n'){    
                ADV();
            }
            ADVKATA();
            Money(*P) = 0;
            for (i = 0; i <= CKata.Length-1; i++){
                Money(*P) *= 10;
                Money(*P) += (int)CKata.TabKata[i] - 48;
            }
        }
        else if (strcmp(CKata.TabKata, "Life") == 0){
            while (CC == ' ' || CC == '\n'){    
                ADV();
            }
            ADVKATA();
            Life(*P) = 0;
            for (i = 0; i <= CKata.Length-1; i++){
                Life(*P) *= 10;
                Life(*P) += (int)CKata.TabKata[i] - 48;
            }
        }
        else if (strcmp(CKata.TabKata, "Time") == 0){
            while (CC == ' ' || CC == '\n'){    
                ADV();
            }
            ADVKATA();
            Time(*P) = 0;
            for (i = 0; i <= CKata.Length-1; i++){
                Time(*P) *= 10;
                Time(*P) += (int)CKata.TabKata[i] - 48;
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
                *ruangan[4][i][j] = CC;
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
                *ruangan[1][i][j] = CC;
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
                *ruangan[2][i][j] = CC;
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
                *ruangan[3][i][j] = CC;
                ADV();
                j++;
                if(j == 9){
                    j = 1;
                    i++;
                }
            }
        }
        else if (strcmp(CKata.TabKata, "FoodStack") == 0){
            while (CC == ' ' || CC == '\n'){    
                ADV();
            }
            ADVKATA();
            Push(&(FoodStack(*P)),CKata.TabKata);
            while (CC == ','){
                while (CC == ' ' || CC == '\n'){    
                    ADV();
                }
                ADVKATA();
                Push(&(FoodStack(*P)),CKata.TabKata);
            }
        }
        while (CC == ' ' || CC == '\n'){    
            ADV();
        }
        ADVKATA();
    }
    printf("Nama: %s\n", Name(*P));
    printf("Money: %d\n", Money(*P));
    printf("Life: %d\n", Life(*P));
    printf("Time: %d\n", Time(*P));
    printf("Ruang 1: \n");
    for(i=1;i<=8;i++){
        for(j=1;j<=8;j++){
            printf("%c ",*ruangan[1][i][j]);
        }
        printf("\n");
    }
    printf("Ruang 2: \n");
    for(i=1;i<=8;i++){
        for(j=1;j<=8;j++){
            printf("%c ",*ruangan[2][i][j]);
        }
        printf("\n");
    }
    printf("Ruang 3: \n");
    for(i=1;i<=8;i++){
        for(j=1;j<=8;j++){
            printf("%c ",*ruangan[3][i][j]);
        }
        printf("\n");
    }
    printf("Kitchen: \n");
    for(i=1;i<=8;i++){
        for(j=1;j<=8;j++){
            printf("%c ",*ruangan[4][i][j]);
        }
        printf("\n");
    }
    printf("Food stack:");
    while (!IsStackEmpty(FoodStack(*P))){
        Pop(&(FoodStack(*P)), test);
        printf("%s ",test);
    }
}

void Save(){

}

