//gcc -o main main.c command/boas.c command/SaveLoad.c ADT/point.c ADT/stackt.c ADT/mesinkar.c ADT/mesinkata.c ADT/queue.c ADT/listrek.c ADT/bintree.c -lm

#include <stdio.h>
#include "ADT/boolean.h"
#include "command/boas.h"
#include "command/SaveLoad.h"
//#include "ADT/array.h"
//#include "ADT/matriks.h"
// #include "command/commandlouis.h"
#include "ADT/point.h"
#include "ADT/stackt.h"
#include "ADT/mesinkar.h"
#include "ADT/mesinkata.h"
#include "ADT/tipebentukan.h"
#include "ADT/queue.h"
#include "ADT/listrek.h"
#include "ADT/bintree.h"
#include <string.h>

int main(){

    srand(time(0));
    char inputtest;
    infotypeCust orang;
    //Variable untuk menu awal
    int input1;
    int indexUser;
    char name[10];
    TabInt User;

    //MakeEmpty(&User);

    //Create pemain
    Player pemain;
    CreateStackEmpty(&FoodStack(pemain));
    CreateStackEmpty(&Hand(pemain));
    Room(pemain) = 1;
    pemain.money = 0;
    pemain.life = 3;
    pemain.Posisi.X = 5;
    pemain.Posisi.Y = 5;
    pemain.time = 0;

    CreateEmpty(&AntrianLuar,10);
    //Daftar koordinat meja
    DaftarMeja[1].X = 2;
    DaftarMeja[1].Y = 2;
    DaftarMeja[2].X = 2;
    DaftarMeja[2].Y = 7;
    DaftarMeja[3].X = 7;
    DaftarMeja[3].Y = 2;
    DaftarMeja[4].X = 7;
    DaftarMeja[4].Y = 7;

    //Inisialisasi Peta
    for (int i = 1; i<9; i++){
        for (int j = 1; j<9; j++){
            Ruang(ruangan,1,i,j) = '-';
            Ruang(ruangan,2,i,j) = '-';
            Ruang(ruangan,3,i,j) = '-';
            Ruang(ruangan,4,i,j) = '-';
        }
    }

    //Daftar meja kursi dan M pada restoran
    Ruang(ruangan,1,1,2) = 'X';
    Ruang(ruangan,1,2,1) = 'X';
    Ruang(ruangan,1,2,2) = '1';
    Ruang(ruangan,1,2,3) = 'X';
    Ruang(ruangan,1,2,6) = 'X';
    Ruang(ruangan,1,2,7) = '2';
    Ruang(ruangan,1,2,8) = 'X';
    Ruang(ruangan,1,3,2) = 'X';
    Ruang(ruangan,1,6,2) = 'X';
    Ruang(ruangan,1,7,1) = 'X';
    Ruang(ruangan,1,7,2) = '3';
    Ruang(ruangan,1,7,3) = 'X';
    Ruang(ruangan,1,7,6) = 'X';
    Ruang(ruangan,1,7,7) = '4';
    Ruang(ruangan,1,7,8) = 'X';
    Ruang(ruangan,1,8,2) = 'X';

    Ruang(ruangan,2,1,2) = 'X';
    Ruang(ruangan,2,2,2) = '5';
    Ruang(ruangan,2,2,6) = 'X';
    Ruang(ruangan,2,2,7) = '6';
    Ruang(ruangan,2,2,8) = 'X';
    Ruang(ruangan,2,3,2) = 'X';
    Ruang(ruangan,2,6,2) = 'X';
    Ruang(ruangan,2,7,1) = 'X';
    Ruang(ruangan,2,7,2) = '7';
    Ruang(ruangan,2,7,3) = 'X';
    Ruang(ruangan,2,7,6) = 'X';
    Ruang(ruangan,2,7,7) = '8';
    Ruang(ruangan,2,7,8) = 'X';
    Ruang(ruangan,2,8,2) = 'X';

    Ruang(ruangan,3,1,2) = 'X';
    Ruang(ruangan,3,2,2) = '9';
    Ruang(ruangan,3,2,6) = 'X';
    Ruang(ruangan,3,2,7) = 'A';
    Ruang(ruangan,3,2,8) = 'X';
    Ruang(ruangan,3,3,2) = 'X';
    Ruang(ruangan,3,6,2) = 'X';
    Ruang(ruangan,3,7,1) = 'X';
    Ruang(ruangan,3,7,2) = 'B';
    Ruang(ruangan,3,7,3) = 'X';
    Ruang(ruangan,3,7,6) = 'X';
    Ruang(ruangan,3,7,7) = 'D';
    Ruang(ruangan,3,7,8) = 'X';
    Ruang(ruangan,3,8,2) = 'X';

    Ruang(ruangan,4,1,1) = 'M';
    Ruang(ruangan,4,2,1) = 'M';
    Ruang(ruangan,4,3,1) = 'M';
    Ruang(ruangan,4,4,1) = 'M';
    Ruang(ruangan,4,5,1) = 'M';
    Ruang(ruangan,4,6,1) = 'M';
    Ruang(ruangan,4,7,1) = 'M';
    Ruang(ruangan,4,8,1) = 'M';
    Ruang(ruangan,4,5,4) = 'M';
    Ruang(ruangan,4,5,5) = 'M';
    Ruang(ruangan,4,5,6) = 'M';
    Ruang(ruangan,4,8,4) = 'M';
    Ruang(ruangan,4,8,5) = 'M';
    Ruang(ruangan,4,8,6) = 'M';
    Ruang(ruangan,4,8,7) = 'M';
    Ruang(ruangan,4,8,8) = 'M';

    Ruang(ruangan,pemain.room,pemain.Posisi.X,pemain.Posisi.Y) = 'P';
    //Daftar resep
    strcpy(DaftarResep[1],"Banana Split");
    strcpy(DaftarResep[2],"Sundae");
    strcpy(DaftarResep[3],"Nasi Telur Dadar");
    strcpy(DaftarResep[4],"Nasi Ayam Goreng");
    strcpy(DaftarResep[5],"Burger");
    strcpy(DaftarResep[6],"Hot Dog");
    strcpy(DaftarResep[7],"Spaghetti Bolognese");
    strcpy(DaftarResep[8],"Spaghetti Carbonara");

    //Pohon resep
    MakeTree("Piring",Tree("Sendok",Tree("Es Krim",Tree("Pisang",Tree("Banana Split",Nil,Nil),Nil),Tree("Stroberi",Tree("Sundae",Nil,Nil),Nil)),Tree("Nasi",Tree("Telur",Tree("Nasi Telur Dadar",Nil,Nil),Nil),Tree("Ayam Goreng",Tree("Nasi Ayam Goreng",Nil,Nil),Nil)))
                     ,Tree("Garpu",Tree("Roti",Tree("Patty",Tree("Burger",Nil,Nil),Nil),Tree("Sosis",Tree("Hot Dog",Nil,Nil),Nil)),Tree("Spaghetti",Tree("Bolognese",Tree("Keju",Tree("Spaghetti Bolognese",Nil,Nil),Nil),Nil),Tree("Carbonara",Tree("Spaghetti Carbonara",Nil,Nil),Nil))),&Resep);

    
    //Create peta semua ruangan
    // MATRIKS ruang[5];
    // MakeMATRIKS (8,8,&ruang[1]);
    // MakeMATRIKS (8,8,&ruang[2]);
    // MakeMATRIKS (8,8,&ruang[3]);
    // MakeMATRIKS (8,8,&ruang[4]);

    //Variable untuk import dari file eksternal
    // int i,j;
    // char Nama[NMax+1]; //Nama di file eksternal
    // int Money;
    // int Life;
    // int Time;
    // printf("Cek\n");
    // STARTKATA();
    // printf("cek\n");
    // printf("%s\n", CKata.TabKata);
    // while(CC != MARK){
    //     //printf("%s\n", CKata.TabKata);
    //     if (strcmp(CKata.TabKata, "Name") == 0){
    //         printf("%s\n", CKata.TabKata);
    //         while (CC == ' ' || CC == '\n'){
    //             ADV();
    //         }
    //         ADVKATA();
    //         // printf("%s\n", CKata.TabKata);
    //         strcpy(Nama,CKata.TabKata);
    //     }
    //     else if (strcmp(CKata.TabKata, "Money") == 0){
    //         while (CC == ' ' || CC == '\n'){
    //             ADV();
    //         }
    //         ADVKATA();
    //         Money = 0;
    //         for (i = 0; i <= CKata.Length-1; i++){
    //             Money *= 10;
    //             Money += (int)CKata.TabKata[i] - 48;
    //         }
    //     }
    //     else if (strcmp(CKata.TabKata, "Life") == 0){
    //         while (CC == ' ' || CC == '\n'){
    //             ADV();
    //         }
    //         ADVKATA();
    //         Life = 0;
    //         for (i = 0; i <= CKata.Length-1; i++){
    //             Life *= 10;
    //             Life += (int)CKata.TabKata[i] - 48;
    //         }
    //     }
    //     else if (strcmp(CKata.TabKata, "Time") == 0){
    //         while (CC == ' ' || CC == '\n'){
    //             ADV();
    //         }
    //         ADVKATA();
    //         Time = 0;
    //         for (i = 0; i <= CKata.Length-1; i++){
    //             Time *= 10;
    //             Time += (int)CKata.TabKata[i] - 48;
    //         }
    //     }
    //     else if (strcmp(CKata.TabKata, "Kitchen") == 0){
    //         while (CC == ' ' || CC == '\n'){
    //             ADV();
    //         }
    //         i = 1;
    //         j = 1;
    //         while (i != 9){
    //             while (CC == ' ' || CC == '\n'){
    //                 ADV();
    //             }
    //             MatriksElmt(ruang[4],i,j) = CC;
    //             //ruang[1][i][j] = CC;
    //             ADV();
    //             j++;
    //             if(j == 9){
    //                 j = 1;
    //                 i++;
    //             }
    //         }
    //     }
    //     else if (strcmp(CKata.TabKata, "Room1") == 0){
    //         while (CC == ' ' || CC == '\n'){
    //             ADV();
    //         }
    //         i = 1;
    //         j = 1;
    //         while (i != 9){
    //             while (CC == ' ' || CC == '\n'){
    //                 ADV();
    //             }
    //             MatriksElmt(ruang[1],i,j) = CC;
    //             //ruang[2][i][j] = CC;
    //             ADV();
    //             j++;
    //             if(j == 9){
    //                 j = 1;
    //                 i++;
    //             }
    //         }
    //     }
    //     else if (strcmp(CKata.TabKata, "Room2") == 0){
    //         while (CC == ' ' || CC == '\n'){
    //             ADV();
    //         }
    //         i = 1;
    //         j = 1;
    //         while (i != 9){
    //             while (CC == ' ' || CC == '\n'){
    //                 ADV();
    //             }
    //             MatriksElmt(ruang[2],i,j) = CC;
    //             //ruang[3][i][j] = CC;
    //             ADV();
    //             j++;
    //             if(j == 9){
    //                 j = 1;
    //                 i++;
    //             }
    //         }
    //     }
    //     else if (strcmp(CKata.TabKata, "Room3") == 0){
    //         while (CC == ' ' || CC == '\n'){
    //             ADV();
    //         }
    //         i = 1;
    //         j = 1;
    //         while (i != 9){
    //             while (CC == ' ' || CC == '\n'){
    //                 ADV();
    //             }
    //             MatriksElmt(ruang[3],i,j) = CC;
    //             //ruang[4][i][j] = CC;
    //             ADV();
    //             j++;
    //             if(j == 9){
    //                 j = 1;
    //                 i++;
    //             }
    //         }
    //     }
    //     while (CC == ' ' || CC == '\n'){
    //         ADV();
    //     }
    //     ADVKATA();
    // }
    // printf("Nama: %s\n", Nama);
    // printf("Money: %d\n", Money);
    // printf("Life: %d\n", Life);
    // printf("Time: %d\n", Time);
    // printf("Kitchen: \n");
    // for(i=1;i<=8;i++){
    //     for(j=1;j<=8;j++){
    //         printf("%c ",MatriksElmt(ruang[4],i,j));
    //     }
    //     printf("\n");
    // }
    // printf("Ruang 1: \n");
    // for(i=1;i<=8;i++){
    //     for(j=1;j<=8;j++){
    //         printf("%c ",MatriksElmt(ruang[1],i,j));
    //     }
    //     printf("\n");
    // }
    // printf("Ruang 2: \n");
    // for(i=1;i<=8;i++){
    //     for(j=1;j<=8;j++){
    //         printf("%c ",MatriksElmt(ruang[2],i,j));
    //     }
    //     printf("\n");
    // }
    // printf("Ruang 3: \n");
    // for(i=1;i<=8;i++){
    //     for(j=1;j<=8;j++){
    //         printf("%c ",MatriksElmt(ruang[3],i,j));
    //     }
    //     printf("\n");
    // }


    tampilanAwal();
    //menu(&input1);
    //AmbilDataArray(&User);
//     while (input1 != 4){
//         if (input1 == 1){
//             newGame(&User,&name);
//         } else if (input1 == 2){
//             TulisMATRIKS(ruang[4]);
//             printf("\n");
//             GoUp(&pemain,&ruang[4]);
//             TulisMATRIKS(ruang[4]);
//             printf("\n");
//             GoDown(&pemain,&ruang[4]);
//             TulisMATRIKS(ruang[4]);
//             printf("\n");
//             GoLeft(&pemain,&ruang[4]);
//             TulisMATRIKS(ruang[4]);
//             printf("\n");
//             GoRight(&pemain,&ruang[4]);
//             TulisMATRIKS(ruang[4]);
//             printf("%d, %d, %d\n",Room(pemain),Absis(Posisi(pemain)),Ordinat(Posisi(pemain)));
//         } else if (input1 == 3){
//             loadGame(User,&name,&indexUser);
//         }
//         menu(&input1);
//     }

    inputtest = ' ';
    while(inputtest != 'q'){
        printf("\n");
        TampilPeta(pemain.room);
        scanf("%c",&inputtest);
        if(inputtest == 'd'){
            GoRight(&pemain);
            printf("%d\n",pemain.time);
        }
        else if(inputtest == 'w'){
            GoUp(&pemain);
            printf("%d\n",pemain.time);
        }
        else if(inputtest == 'a'){
            GoLeft(&pemain);
            printf("%d\n",pemain.time);
        }
        else if(inputtest == 's'){
            GoDown(&pemain);
            printf("%d\n",pemain.time);
        }
        else if(inputtest == 'o'){
            Order(pemain);
            printf("%s\n",DaftarOrder[1]);
        }
        else if(inputtest == 'p'){
            Place(pemain);
            printf("%s\n",arrayCust[1].order);
            printf("%d\n",arrayCust[1].jumlah);
            printf("%d\n",arrayCust[1].patience);
            printf("%d\n",arrayCust[1].qpatience);
        }
        else if(inputtest == 't'){
            Take(&pemain);
            printf("%s\n",InfoTop(Hand(pemain)));
        }
        else if(inputtest == 'l'){
            AddQueue(pemain);
        }
    }

}


