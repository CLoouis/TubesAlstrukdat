#include "mesinkata.h"
#include "mesinkar.h"
#include "boolean.h"
#include <stdio.h>

void cetakkata(Kata c){
    int i;
    for(i=1;i<=c.Length;i++){
        printf("%c",c.TabKata[i]);
    }
    printf(" ");
}

boolean IsSama(Kata s1,Kata s2){
    boolean hasil;
    int i;
    hasil = true;
    if(s1.Length != s2.Length){
        hasil = false;
    }
    else{
        for(i=1;i<=s1.Length;i++){
            if(s1.TabKata[i]!=s2.TabKata[i]){
                hasil = false;
            }
        }
    }
    return hasil;
}

int main(){
    int count,length,hitungkuda;
    count =0;
    length=0;
    hitungkuda = 0;
    FILE * pitakar;
    Kata s1;
    s1.TabKata[1]='k';
    s1.TabKata[2]='u';
    s1.TabKata[3]='d';
    s1.TabKata[4]='a';
    s1.Length = 4;


    pitakar = fopen("pitakar.txt","r");
    STARTKATA();
    while(!EndKata){
        count++;
        length += CKata.Length;
        cetakkata(CKata);
        if(IsSama(s1,CKata)){
            hitungkuda++;
        }
        ADVKATA();
    }

    printf("\nBanyaknya kata %d\n",count);
    printf("Total panjang katanya adalah %d\n",length);
    printf("Banyaknya kata kuda %d\n",hitungkuda);
    fclose(pitakar);
    //printf("%s",s1.TabKata);

    return 0;
}