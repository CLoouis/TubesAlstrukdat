#include "commandlouis.h"
#include <stdio.h>

void Recipe(){
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
    printf("----------------------------------------------\n");
    printf("-----------ENGI'S KITCHEN EXPANSION-----------\n");
    printf("----------------------------------------------\n");
}

void menu(int *X){
    printf("1. New Game\n");
    printf("2. Start Game\n");
    printf("3. Load Game\n");
    printf("4. Exit\n\n");

    printf("Input : > ");
    scanf("%d",&*X);
}
