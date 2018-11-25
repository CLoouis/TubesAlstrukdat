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
#include "ADT/graph.h"
#include "ADT/listrek.h"
#include "ADT/bintree.h"
#include <string.h>

int main(){

    srand(time(0));
    char inputtest;
    infotypeCust orang;
    //Variable untuk menu awal
    Graph G;
    int input1;
    int indexUser;
    char name[10];
    int IdxQueue, IdxOrder, IdxFoodStack, IdxHand; // Elemen queue antrian diluar, elemen order, elemen food stack, elemen hand
    TabInt User;

    //MakeEmpty(&User);

    //Create pemain
    Player pemain;
    CreateStackEmpty(&FoodStack(pemain));
    CreateStackEmpty(&Hand(pemain));
    CreateGraph(&G);
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

    //Daftar meja
    arrayCust(arrayCust,1).jumlah = 4;
    arrayCust(arrayCust,2).jumlah = 2;
    arrayCust(arrayCust,3).jumlah = 4;
    arrayCust(arrayCust,4).jumlah = 2;
    arrayCust(arrayCust,5).jumlah = 2;
    arrayCust(arrayCust,6).jumlah = 2;
    arrayCust(arrayCust,7).jumlah = 4;
    arrayCust(arrayCust,8).jumlah = 2;
    arrayCust(arrayCust,9).jumlah = 2;
    arrayCust(arrayCust,10).jumlah = 2;
    arrayCust(arrayCust,11).jumlah = 4;
    arrayCust(arrayCust,12).jumlah = 2;
    arrayCust(arrayCust,1).isi = false;
    arrayCust(arrayCust,2).isi = false;
    arrayCust(arrayCust,3).isi = false;
    arrayCust(arrayCust,4).isi = false;
    arrayCust(arrayCust,5).isi = false;
    arrayCust(arrayCust,6).isi = false;
    arrayCust(arrayCust,7).isi = false;
    arrayCust(arrayCust,8).isi = false;
    arrayCust(arrayCust,9).isi = false;
    arrayCust(arrayCust,10).isi = false;
    arrayCust(arrayCust,11).isi = false;
    arrayCust(arrayCust,12).isi = false;

    //Kursi meja
    KursiMeja[1] = 4;
    KursiMeja[2] = 2;
    KursiMeja[3] = 4;
    KursiMeja[4] = 2;
    KursiMeja[5] = 2;
    KursiMeja[6] = 2;
    KursiMeja[7] = 4;
    KursiMeja[8] = 2;
    KursiMeja[9] = 2;
    KursiMeja[10] = 2;
    KursiMeja[11] = 4;
    KursiMeja[12] = 2;

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
    Ruang(ruangan,4,1,8) = 'T';
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

    NamaMeja[1] = '1';
    NamaMeja[2] = '2';
    NamaMeja[3] = '3';
    NamaMeja[4] = '4';
    NamaMeja[5] = '5';
    NamaMeja[6] = '6';
    NamaMeja[7] = '7';
    NamaMeja[8] = '8';
    NamaMeja[9] = '9';
    NamaMeja[10] = 'A';
    NamaMeja[11] = 'B';
    NamaMeja[12] = 'D';


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

    // Daftar Order
    for(IdxOrder = 1; IdxOrder <= 12; IdxOrder++){
            strcpy(DaftarOrder(DaftarOrder, IdxOrder), "*");
    }


    // Pohon resep
    MakeTree("Piring",Tree("Sendok",Tree("Es Krim",Tree("Pisang",Tree("Banana Split",Nil,Nil),Nil),Tree("Stroberi",Tree("Sundae",Nil,Nil),Nil)),Tree("Nasi",Tree("Telur",Tree("Nasi Telur Dadar",Nil,Nil),Nil),Tree("Ayam Goreng",Tree("Nasi Ayam Goreng",Nil,Nil),Nil)))
                     ,Tree("Garpu",Tree("Roti",Tree("Patty",Tree("Burger",Nil,Nil),Nil),Tree("Sosis",Tree("Hot Dog",Nil,Nil),Nil)),Tree("Spaghetti",Tree("Bolognese",Tree("Keju",Tree("Spaghetti Bolognese",Nil,Nil),Nil),Nil),Tree("Carbonara",Tree("Spaghetti Carbonara",Nil,Nil),Nil))),&Resep);

    
    Pintu Pintu1,Pintu2,Pintu3,Pintu4,Pintu5,Pintu6,Pintu7,Pintu8;
    adrNode P1,P2,P3,P4,P5,P6,P7,P8;

    Pintu1.X = 1;
    Pintu1.Y = 5;
    Pintu1.Z = 8;

    Pintu2.X = 2;
    Pintu2.Y = 2;
    Pintu2.Z = 1;

    Pintu3.X = 2;
    Pintu3.Y = 8;
    Pintu3.Z = 5;

    Pintu4.X = 3;
    Pintu4.Y = 1;
    Pintu4.Z = 5;

    Pintu5.X = 3;
    Pintu5.Y = 2;
    Pintu5.Z = 1;

    Pintu6.X = 4;
    Pintu6.Y = 5;
    Pintu6.Z = 8;

    Pintu7.X = 4;
    Pintu7.Y = 1;
    Pintu7.Z = 5;

    Pintu8.X = 1;
    Pintu8.Y = 8;
    Pintu8.Z = 5;

    InsertNodeGraph(&G,Pintu1,&P1);
    InsertNodeGraph(&G,Pintu2,&P2);
    InsertNodeGraph(&G,Pintu3,&P3);
    InsertNodeGraph(&G,Pintu4,&P4);
    InsertNodeGraph(&G,Pintu5,&P5);
    InsertNodeGraph(&G,Pintu6,&P6);
    InsertNodeGraph(&G,Pintu7,&P7);
    InsertNodeGraph(&G,Pintu8,&P8);

    InsertEdge(&G,Pintu1,Pintu2);
    InsertEdge(&G,Pintu2,Pintu1);
    InsertEdge(&G,Pintu3,Pintu4);
    InsertEdge(&G,Pintu4,Pintu3);
    InsertEdge(&G,Pintu5,Pintu6);
    InsertEdge(&G,Pintu6,Pintu5);
    InsertEdge(&G,Pintu7,Pintu8);
    InsertEdge(&G,Pintu8,Pintu7);
    
    //-----------------------------------------------------MAIN PROGRAM-----------------------------------------------------------------------

    inputtest = ' ';
    while(inputtest != 'q'){
        printf("\n");
        printf("Name : %s\n", pemain.name);
        printf("Money : %d\n\n", pemain.money);
        printf("Life : %d\n\n", pemain.life);
        printf("Time : %d\n\n", pemain.time);
        printf("Waiting Cust : \n");
        for(IdxQueue = Head(AntrianLuar); IdxQueue <= Tail(AntrianLuar); IdxQueue++){
            printf("%d\n", AntrianLuar.T[IdxQueue].jumlah);
        }
        printf("\n");
        printf("Order : \n");
        for(IdxOrder = 1; IdxOrder <= 12; IdxOrder++){
            if((strcmp(DaftarOrder(DaftarOrder, IdxOrder), "*") != 0) && (arrayCust(arrayCust, IdxOrder).isi == true)){
                printf("%s, %c\n", DaftarOrder(DaftarOrder, IdxOrder), NamaMeja[IdxOrder]);
            }
        }
        printf("\n");
        printf("Food Stack : \n");
        for(IdxFoodStack = 1; IdxFoodStack <= Top(FoodStack(pemain)); IdxFoodStack++){
            printf("%s\n", FoodStack(pemain).TI[IdxFoodStack]);
        }
        printf("\n");
        printf("Hand :\n");
        for(IdxHand = 1; IdxHand <= Top(Hand(pemain)); IdxHand++){
            printf("%s\n", Hand(pemain).TI[IdxHand]);
        }

        TampilPeta(pemain.room);
        scanf("%c",&inputtest);
        scanf("%c",&inputtest);
        if(inputtest == 'd'){
            GoRight(&pemain);
        }
        else if(inputtest == 'w'){
            GoUp(&pemain);
        }
        else if(inputtest == 'a'){
            GoLeft(&pemain);
        }
        else if(inputtest == 's'){
            GoDown(&pemain);
        }
        else if(inputtest == 'o'){
            Order(pemain);
        }
        else if(inputtest == 'p'){
            Place(pemain);
        }
        else if(inputtest == 't'){
            Take(&pemain);
        }
        else if(inputtest == 'z'){
            Put(&pemain);
        }
        else if(inputtest == 'g'){
            Give(&pemain);
        }
        else if(inputtest =='x'){
            CH(&pemain);
        }
        else if(inputtest =='c'){
            CT(&pemain);
        }
    }

}


