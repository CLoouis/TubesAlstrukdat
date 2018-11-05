#include "commandlouis.h"
#include "array.h"
#include <stdio.h>

void Recipe(){
    //Menampilkan pohon resep kepada pengguna
    printf("Piring\n");
    printf("\tSendok\n");
    printf("\t\tEs Krim\n");
    printf("\t\t\tPisang\n");
    printf("\t\t\t\tBanana Split\n");
    printf("\t\t\tStroberi\n");
    printf("\t\t\t\tSundae\n");
    printf("\t\tNasi\n");
    printf("\t\t\tTelur\n");
    printf("\t\t\t\tNasi telur dadar\n");
    printf("\t\t\tAyam Goreng\n");
    printf("\t\t\t\tNasi Ayam Goreng\n");
    printf("\tGarpu\n");
    printf("\t\tRoti\n");
    printf("\t\t\tPatty\n");
    printf("\t\t\t\tBurger\n");
    printf("\t\t\tSosis\n");
    printf("\t\t\t\tHot Dog\n");
    printf("\t\tSpaghetti\n");
    printf("\t\t\tBolognese\n");
    printf("\t\t\t\tKeju\n");
    printf("\t\t\t\t\tSpaghetti Bolognese\n");
    printf("\t\t\tCarbonara\n");
    printf("\t\t\t\tSpaghetti Carbonara\n");
}

void tampilanAwal(){
    //Menampilkan Tampilan awal permainan
    printf("----------------------------------------------\n");
    printf("-----------ENGI'S KITCHEN EXPANSION-----------\n");
    printf("----------------------------------------------\n");
}

void menu(int *X){
    //Menampilkan menu dan X sebagai input yang diterima dari user
    printf("1. New Game\n");
    printf("2. Start Game\n");
    printf("3. Load Game\n");
    printf("4. Exit\n\n");

    printf("Input : > ");
    scanf("%d",&*X);
}

void newGame(TabInt *User, Kata *nama){
    printf("Masukan nama Anda :\n");
    printf(">> ");
    scanf("%s",nama);
    if (IsFull(*User)){
        printf("Maaf tempat penyimpanan sudah penuh.\n");
    } else {
        AddElUnik(User,*nama);
        printf("Silahkan lanjutkan ke Start Game\n");
    }
    UploadDataArray(User);
}

void loadGame(TabInt User, Kata *nama, int *indexUser){
    TulisIsiTab(User);
    printf("Siapa Anda : \n");
    printf(">> ");
    scanf("%s",nama);
    *indexUser = Search(User,*nama);
    while (*indexUser == IdxUndef){
        printf("Anda salah memasukan nama!!!\n");
        printf("Siapa Anda : \n");
        printf(">> ");
        scanf("%s",nama);
        *indexUser = Search(User,*nama);
    }
    printf("Anda memilih slot %d\n\n",*indexUser);
}
