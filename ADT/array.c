#include "boolean.h"
#include "array.h"
#include "tipebentukan.h"
#include <stdio.h>
#include <string.h>

void MakeEmpty (TabInt *T){
    Neff(*T) = 0;
}

int NbElmtArray (TabInt T){
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
            printf("%s,",ArrayElmt(T,i));
        }
        printf("%s]\n",ArrayElmt(T,GetLastIdx(T)));
    }
}

IdxType Search (TabInt T, ArrayElType X){
    IdxType i;

    if (!IsEmpty(T)){
        i = GetFirstIdx(T);
        while ((i < GetLastIdx(T)) && (strcmp(ArrayElmt(T,i),X) != 0)){
            i = i + 1;
        } //i = GetLastIdx(T) atau T[i] = X
        if (strcmp(ArrayElmt(T,i),X) == 0){
            return i;
        } else {
            return IdxUndef;
        }
    } else {
        return IdxUndef;
    }
}

void AddElUnik(TabInt *T, ArrayElType X){
    IdxType i;

    if (!IsFull(*T)){
        if (Search(*T,X) == IdxUndef){
            strcpy(ArrayElmt(*T,GetLastIdx(*T)+1),X);
            Neff(*T) += 1;
        }
    }
}

void AmbilDataArray(TabInt *T){
    FILE *pFile;
    ArrayElType X;

    pFile = fopen("File/DaftarPemain.txt","r");
    while(!feof(pFile)){
        fscanf(pFile,"%s",X);
        AddElUnik(T,X);
    }
    fclose(pFile);
}

void UploadDataArray(TabInt *T){
    FILE *pFile;
    ArrayElType X;
    IdxType i;

    pFile = fopen("File/DaftarPemain.txt","w");
    for (i = GetFirstIdx(*T); i <= GetLastIdx(*T); i++){
        fprintf(pFile,"%s\n",ArrayElmt(*T,i));
    }

    fclose(pFile);
}
