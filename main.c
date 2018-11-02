#include <stdio.h>
#include "boolean.h"
#include "commandlouis.h"

int main(){
    int input1;
    char nama[10];

    tampilanAwal();
    menu(&input1);
    if (input1 == 1){
        printf("Masukan nama Anda :\n");
        printf(">> ");
        scanf("%s",&nama);
        //Terus cek di array daftar user apa udah ada namanya
        //Kalau belum ada langsung panggil Start
        //Kalau udah ada bilang udah ada woy langsung start game aja
    } else if (input1 == 2){
        printf("Masukan nama Anda : \n");
        printf(">> ");
        scanf("%s",&nama);
        //Panggil start game dengan inputan variable - variable yang
        //diperlukan
    } else if (input1 == 3){

    } else if (input1 == 4){
        printf("4\n");
    }

    Recipe();
}
