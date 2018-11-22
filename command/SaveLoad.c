#include <stdio.h>
#include <string.h>
#include "../ADT/mesinkata.h"
#include "../ADT/boolean.h"
#include "SaveLoad.h"


void Load(){
    typedef char peta[9][9];
    peta ruang[5];
    int i,j;
    char Nama[NMax+1];
    int Money;
    int Life;
    int Time;

    STARTKATA();
    while(CC != MARK){
        if (strcmp(CKata.TabKata, "Name") == 0){
            // printf("%s\n", CKata.TabKata);
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
                ruang[1][i][j] = CC;
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
                ruang[2][i][j] = CC;
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
                ruang[3][i][j] = CC;
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
                ruang[4][i][j] = CC;
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
            printf("%c ",ruang[1][i][j]);
        }
        printf("\n");
    }
    printf("Ruang 1: \n");
    for(i=1;i<=8;i++){
        for(j=1;j<=8;j++){
            printf("%c ",ruang[2][i][j]);
        }
        printf("\n");
    }
    printf("Ruang 2: \n");
    for(i=1;i<=8;i++){
        for(j=1;j<=8;j++){
            printf("%c ",ruang[3][i][j]);
        }
        printf("\n");
    }
    printf("Ruang 3: \n");
    for(i=1;i<=8;i++){
        for(j=1;j<=8;j++){
            printf("%c ",ruang[4][i][j]);
        }
        printf("\n");
    }
}
