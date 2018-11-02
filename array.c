#include "boolean.h"
#include "array.h"
#include <stdio.h>
#include <string.h>

void MakeEmpty (TabInt *T){
    Neff(*T) = 0;
}

int NbElmt (TabInt T){
    return (Neff(T));
}

int GetFirstIdx (TabInt T){
    return (IdxMin);
}

int GetLastIdx (TabInt T){
    return (Neff(T) -1);
}

boolean IsEmpty (TabInt T){
    return (Neff(T) == 0);
}

boolean IsFull (TabInt T){
    return(GetLastIdx(T) == IdxMax);
}

void TulisIsiTab (TabInt T){
    IdxType i;

    if (IsEmpty(T)){
        printf("[]");
    } else {
        printf("[");
        for (i = GetFirstIdx(T); i <= (GetLastIdx(T) - 1); i++){
            printf("%s,",Elmt(T,i));
        }
        printf("%s]\n",Elmt(T,GetLastIdx(T)));
    }
}

IdxType Search (TabInt T, ElType X){
    IdxType i;

    if (!IsEmpty(T)){
        i = GetFirstIdx(T);
        while ((i < GetLastIdx(T)) && (strcmp(Elmt(T,i),X) != 0)){
            i = i + 1;
        } //i = GetLastIdx(T) atau T[i] = X
        if (strcmp(Elmt(T,i),X) == 0){
            return i;
        } else {
            return IdxUndef;
        }
    } else {
        return IdxUndef;
    }
}

void AddElUnik(TabInt *T, ElType X){
    IdxType i;

    if (!IsFull(*T)){
        if (Search(*T,X) == IdxUndef){
            strcpy(Elmt(*T,GetLastIdx(*T)+1),X);
            Neff(*T) += 1;
        } else {
            printf("Nama sudah ada\n");
        }
    }
}

void AmbilData(TabInt *T){
    FILE *pFile;
    ElType X;

    pFile = fopen("DaftarPemain.txt","r");
    while(!feof(pFile)){
        fscanf(pFile,"%s",X);
        AddElUnik(T,X);
    }
    fclose(pFile);
}

void UploadData(TabInt *T){
    FILE *pFile;
    ElType X;
    IdxType i;

    pFile = fopen("DaftarPemain.txt","w");
    for (i = GetFirstIdx(*T); i <= GetLastIdx(*T); i++){
        fprintf(pFile,"%s\n",Elmt(*T,i));
    }

    fclose(pFile);
}
