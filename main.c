#include <stdio.h>
#include "boolean.h"
#include "commandlouis.h"
#include "array.h"

int main(){
    int input1;
    int indexUser;
    char nama[10];
    TabInt User;

    tampilanAwal();
    menu(&input1);
    AmbilData(&User);
    if (input1 == 1){
        printf("Masukan nama Anda :\n");
        printf(">> ");
        scanf("%s",&nama);
        if (IsFull(User)){
            printf("Maaf tempat penyimpanan sudah penuh.\n");
        } else {
            AddElUnik(&User,nama);
        }
        UploadData(&User);
        TulisIsiTab(User);
        //Terus cek di array daftar user apa udah ada namanya
        //Kalau belum ada langsung panggil Start
        //Kalau udah ada bilang udah ada woy langsung start game aja
    } else if (input1 == 2){
        TulisIsiTab(User);
        printf("Siapa Anda : \n");
        printf(">> ");
        scanf("%s",&nama);
        indexUser = Search(User,nama);
        while (indexUser == IdxUndef){
            printf("Anda salah memasukan nama!!!\n");
            printf("Siapa Anda : \n");
            printf(">> ");
            scanf("%s",&nama);
            indexUser = Search(User,nama);
        }
        printf("Hooo Anda memilih slot %d",indexUser);
        //Panggil start game dengan inputan variable - variable yang
        //diperlukan
    } else if (input1 == 3){

    } else if (input1 == 4){
        printf("4\n");
    }
}
