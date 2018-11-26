#include <stdio.h>
#include <string.h>
#include "tipebentukan.h"
#include "../ADT_MesinKarakter_MesinKata/mesinkata.h"
#include "../ADT_MesinKarakter_MesinKata/mesinkar.h"
#include "boolean.h"
#include "../ADT_Stack/stackt.h"
#include "../ADT_Queue/queue.h"
#include "SaveLoad.h"


void newsave(KataString Nama){
    FILE *fptr1, *fptr2; 
    char Namafile[1000];
    char c; 
    snprintf(Namafile, sizeof(Namafile), "File/Save/%s.txt", Nama);
    fptr1 = fopen(Namafile, "w");
    if (fptr1 == NULL) {
        perror("fopen()");
    }
    else {
        fptr2 = fopen("File/Save/newsave.txt","r");
        c = fgetc(fptr2); 
        if (fptr2 == NULL) {
            perror("fopen()");
        }
        while (c != EOF) 
        { 
            fputc(c, fptr1); 
            c = fgetc(fptr2); 
        }
        fclose(fptr2);
    }
    fclose(fptr1);
}

void ceksave(KataString Nama, boolean *mark){
    FILE *fptr1, *fptr2; 
    char Namafile[1000];
    char c; 
    snprintf(Namafile, sizeof(Namafile), "File/Save/%s.txt", Nama);
    fptr1 = fopen(Namafile, "r");
    if (fptr1 == NULL) {
        *mark = false;
    }
    else {
        fptr2 = fopen("File/pitakar.txt","w");
        if (fptr2 == NULL) {
            perror("fopen()");
        }
        c = fgetc(fptr1); 
        while (c != EOF) 
        { 
            fputc(c, fptr2); 
            c = fgetc(fptr1); 
        }
        fclose(fptr2);
        *mark = true;
    }
    fclose(fptr1);
}

void Load (Player *P, Queue *AntrianLuar, ruang *ruangan, arrayC *arrayCust, DaftarO *DaftarOrder){
    // typedef char peta[9][9];
    // peta ruang[5];
    int i,j,N;
    KataString test;
    boolean koma;
    CreateEmpty(AntrianLuar,10);
    // char Nama[NMax+1];
    // int Money;
    // int Life;
    // int Time;
    STARTKATA();
    while(CC != MARK){
        if (strcmp(CKata.TabKata, "Name") == 0){
            while (CC == ' ' || CC == '\n'){    
                ADV();
            }
            ADVKATA();
            // strcpy(Name(*P),CKata.TabKata);
        }
        else if (strcmp(CKata.TabKata, "Position") == 0){
            while (CC == ' ' || CC == '\n'){    
                ADV();
            }
            ADVKATA();
            Posisi(*P).X = 0;
            Posisi(*P).Y = 0;
            i = 0;
            koma = false;
            while (i <= CKata.Length-1){
                if (CKata.TabKata[i] == ','){
                    koma = true;
                }
                else {
                    if (!koma){
                        Posisi(*P).X *= 10;
                        Posisi(*P).X += (int)CKata.TabKata[i] - 48;
                    }
                    else {
                        Posisi(*P).Y *= 10;
                        Posisi(*P).Y += (int)CKata.TabKata[i] - 48;
                    }
                }
                i++;
            }
        }
        else if (strcmp(CKata.TabKata, "Room") == 0){
            while (CC == ' ' || CC == '\n'){    
                ADV();
            }
            ADVKATA();
            Room(*P) = 0;
            for (i = 0; i <= CKata.Length-1; i++){
                Room(*P) *= 10;
                Room(*P) += (int)CKata.TabKata[i] - 48;
            }
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
                Ruang(*ruangan,4,i,j) = CC;
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
                Ruang(*ruangan,1,i,j) = CC;
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
                Ruang(*ruangan,2,i,j) = CC;
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
                Ruang(*ruangan,3,i,j) = CC;
                ADV();
                j++;
                if(j == 9){
                    j = 1;
                    i++;
                }
            }
        }
        else if (strcmp(CKata.TabKata, "AntrianLuar") == 0){
            while (CC == ' ' || CC == '\n'){    
                ADV();
            }
            ADVKATA();
            N = 0;
            for (i = 0; i <= CKata.Length-1; i++){
                N *= 10;
                N += (int)CKata.TabKata[i] - 48;
            }
            if (N != 0){
                Head(*AntrianLuar) = 1;
                for (i = 1; i <= N; i++){
                    Tail(*AntrianLuar) = i;
                    while (CC == ' ' || CC == '\n'){    
                        ADV();
                    }
                    ADVKATA();
                    InfoTail(*AntrianLuar).jumlah = 0;
                    for (j = 0; j <= CKata.Length-1; j++){
                        InfoTail(*AntrianLuar).jumlah *= 10;
                        InfoTail(*AntrianLuar).jumlah += (int)CKata.TabKata[j] - 48;
                    }
                    while (CC == ' ' || CC == '\n'){    
                        ADV();
                    }
                    ADVKATA();
                    InfoTail(*AntrianLuar).patience = 0;
                    for (j = 0; j <= CKata.Length-1; j++){
                        InfoTail(*AntrianLuar).patience *= 10;
                        InfoTail(*AntrianLuar).patience += (int)CKata.TabKata[j] - 48;
                    }
                    while (CC == ' ' || CC == '\n'){    
                        ADV();
                    }
                    ADVKATA();
                    InfoTail(*AntrianLuar).qpatience = 0;
                    for (j = 0; j <= CKata.Length-1; j++){
                        InfoTail(*AntrianLuar).qpatience *= 10;
                        InfoTail(*AntrianLuar).qpatience += (int)CKata.TabKata[j] - 48;
                    }
                    while (CC == ' ' || CC == '\n'){    
                        ADV();
                    }
                    ADVKATA();
                    for (j = 0; j <= CKata.Length-1; j++){
                        if (CKata.TabKata[j] == '_'){
                            CKata.TabKata[j] = ' ';
                        }
                    }
                    strcpy(InfoTail(*AntrianLuar).order,CKata.TabKata);
                    InfoTail(*AntrianLuar).isi = false;
                }
            }
            else {
                Head(*AntrianLuar) = 0;
            }
        }
        else if (strcmp(CKata.TabKata, "Customer") == 0){
            for (i = 1; i <= 12; i++){
                while (CC == ' '){    
                    ADV();
                }
                ADVKATA();
                arrayCust(*arrayCust,i).jumlah = 0;
                for (j = 0; j <= CKata.Length-1; j++){
                    arrayCust(*arrayCust,i).jumlah *= 10;
                    arrayCust(*arrayCust,i).jumlah += (int)CKata.TabKata[j] - 48;
                }
                while (CC == ' '){    
                    ADV();
                }
                ADVKATA();
                arrayCust(*arrayCust,i).patience = 0;
                for (j = 0; j <= CKata.Length-1; j++){
                    arrayCust(*arrayCust,i).patience *= 10;
                    arrayCust(*arrayCust,i).patience += (int)CKata.TabKata[j] - 48;
                }
                while (CC == ' '){    
                    ADV();
                }
                ADVKATA();
                arrayCust(*arrayCust,i).qpatience = 0;
                for (j = 0; j <= CKata.Length-1; j++){
                    arrayCust(*arrayCust,i).qpatience *= 10;
                    arrayCust(*arrayCust,i).qpatience += (int)CKata.TabKata[j] - 48;
                }
                while (CC == ' '){    
                    ADV();
                }
                ADVKATA();
                for (j = 0; j <= CKata.Length-1; j++){
                    if (CKata.TabKata[j] == '_'){
                        CKata.TabKata[j] = ' ';
                    }
                }
                strcpy(arrayCust(*arrayCust,i).order,CKata.TabKata);
                while (CC == ' '){    
                    ADV();
                }
                ADVKATA();
                if (strcmp(CKata.TabKata, "f") == 0){
                    arrayCust(*arrayCust,i).isi = false;
                }
                else {
                    arrayCust(*arrayCust,i).isi = true;
                }
            }
        }
        else if (strcmp(CKata.TabKata, "Order") == 0){
            for (i = 1; i <= 12; i++){
                while (CC == ' ' || CC == '\n'){    
                    ADV();
                }
                ADVKATA();
                for (j = 0; j <= CKata.Length-1; j++){
                    if (CKata.TabKata[j] == '_'){
                        CKata.TabKata[j] = ' ';
                    }
                }
                strcpy(DaftarOrder(*DaftarOrder,i),CKata.TabKata);
            }
        }
        else if (strcmp(CKata.TabKata, "Hand") == 0){
            while (CC == ' ' || CC == '\n'){    
                ADV();
            }
            ADVKATA();
            N = 0;
            for (i = 0; i <= CKata.Length-1; i++){
                N *= 10;
                N += (int)CKata.TabKata[i] - 48;
            }
            Top((*P).Hand) = N;
            if (N != 0){
                for (i = 1; i <= N; i++){
                    while (CC == ' ' || CC == '\n'){    
                        ADV();
                    }
                    ADVKATA();
                    for (j = 0; j <= CKata.Length-1; j++){
                        if (CKata.TabKata[j] == '_'){
                            CKata.TabKata[j] = ' ';
                        }
                    }
                    strcpy(((*P).Hand).TI[i],CKata.TabKata);
                }
            }
        }
        else if (strcmp(CKata.TabKata, "FoodStack") == 0){
            while (CC == ' ' || CC == '\n'){    
                ADV();
            }
            ADVKATA();
            N = 0;
            for (i = 0; i <= CKata.Length-1; i++){
                N *= 10;
                N += (int)CKata.TabKata[i] - 48;
            }
            Top((*P).FoodStack) = N;
            if (N != 0){
                for (i = 1; i <= N; i++){
                    while (CC == ' ' || CC == '\n'){    
                        ADV();
                    }
                    ADVKATA();
                    for (j = 0; j <= CKata.Length-1; j++){
                        if (CKata.TabKata[j] == '_'){
                            CKata.TabKata[j] = ' ';
                        }
                    }
                    strcpy(((*P).FoodStack).TI[i],CKata.TabKata);
                }
            }
        }
        while (CC == ' ' || CC == '\n'){    
            ADV();
        }
        ADVKATA();
    }
}

void Save (Player P, Queue AntrianLuar, ruang ruangan, arrayC arrayCust, DaftarO DaftarOrder){
    int i, j, N;
    FILE *fptr;
    // char str[] = P.Nama;
    char Namafile[1000];
    snprintf(Namafile, sizeof(Namafile), "File/Save/%s.txt", Name(P));
    // printf("%s", Namafile);
    fptr = fopen(Namafile, "w");
    if (fptr == NULL) {
        perror("fopen()");
    }
    fprintf(fptr, "Name\n%s\n\n", Name(P));
    fprintf(fptr, "Position\n%d,%d\n\n", Posisi(P).X, Posisi(P).Y);
    fprintf(fptr, "Room\n%d\n\n", Room(P));
    fprintf(fptr, "Money\n%d\n\n", Money(P));
    fprintf(fptr, "Life\n%d\n\n", Life(P));
    fprintf(fptr, "Time\n%d\n\n", Time(P));
    fprintf(fptr, "Room1\n");
    for(i=1;i<=8;i++){
        for(j=1;j<=8;j++){
            fprintf(fptr, "%c ",Ruang(ruangan,1,i,j));
        }
        fprintf(fptr,"\n");
    }
    fprintf(fptr, "\nRoom2\n");
    for(i=1;i<=8;i++){
        for(j=1;j<=8;j++){
            fprintf(fptr, "%c ",Ruang(ruangan,2,i,j));
        }
        fprintf(fptr,"\n");
    }
    fprintf(fptr, "\nRoom3\n");
    for(i=1;i<=8;i++){
        for(j=1;j<=8;j++){
            fprintf(fptr, "%c ",Ruang(ruangan,3,i,j));
        }
        fprintf(fptr,"\n");
    }
    fprintf(fptr, "\nKitchen\n");
    for(i=1;i<=8;i++){
        for(j=1;j<=8;j++){
            fprintf(fptr, "%c ",Ruang(ruangan,4,i,j));
        }
        fprintf(fptr,"\n");
    }
    fprintf(fptr, "\nAntrianLuar\n%d\n", Tail(AntrianLuar));
    for (i = 1; i <= Tail(AntrianLuar); i++){
        for (N = 0 ; N <= strlen((AntrianLuar).T[i].order); N++){
            if ((AntrianLuar).T[i].order[N] == ' '){
                (AntrianLuar).T[i].order[N] = '_';
            }
        }
        fprintf(fptr, "%d %d %d %s\n", (AntrianLuar).T[i].jumlah, (AntrianLuar).T[i].patience, (AntrianLuar).T[i].qpatience, (AntrianLuar).T[i].order);
    }
    fprintf(fptr, "\nCustomer\n");
    for (i = 1; i <= 12; i++){
        for (N = 0 ; N <= strlen(arrayCust(arrayCust,i).order); N++){
            if (arrayCust(arrayCust,i).order[N] == ' '){
                arrayCust(arrayCust,i).order[N] = '_';
            }
        }
        if (arrayCust(arrayCust,i).isi){
            fprintf(fptr, "%d %d %d %s t\n", arrayCust(arrayCust,i).jumlah, arrayCust(arrayCust,i).patience, arrayCust(arrayCust,i).qpatience, arrayCust(arrayCust,i).order);
        }
        else {
            fprintf(fptr, "%d %d %d %s f\n", arrayCust(arrayCust,i).jumlah, arrayCust(arrayCust,i).patience, arrayCust(arrayCust,i).qpatience, arrayCust(arrayCust,i).order);
        }
    }
    fprintf(fptr, "\nOrder\n");
    for (i = 1; i <= 12; i++){
        for (N = 0 ; N <= strlen(DaftarOrder(DaftarOrder,i)); N++){
            if (DaftarOrder(DaftarOrder,i)[N] == ' '){
                DaftarOrder(DaftarOrder,i)[N] = '_';
            }
        }
        fprintf(fptr, "%s\n", DaftarOrder(DaftarOrder,i));
    }
    fprintf(fptr, "\nFoodStack\n%d\n", Top((P).FoodStack));
    for (i = 1; i <= Top((P).FoodStack); i++){
        for (j = 0; j <= strlen(((P).FoodStack).TI[i]); j++){
            if (((P).FoodStack).TI[i][j] == ' '){
                ((P).FoodStack).TI[i][j] = '_';
            }
        }
        fprintf(fptr, "%s\n", ((P).FoodStack).TI[i]);
    }
    fprintf(fptr, "\nHand\n%d\n", Top((P).Hand));
    for (i = 1; i <= Top((P).Hand); i++){
        for (j = 0; j <= strlen(((P).Hand).TI[i]); j++){
            if (((P).Hand).TI[i][j] == ' '){
                ((P).Hand).TI[i][j] = '_';
            }
        }
        fprintf(fptr, "%s\n", ((P).Hand).TI[i]);
    }
    fprintf(fptr,".");
    fclose(fptr);
}

