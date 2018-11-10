#include <stdio.h>
#include <string.h>
#include "mesinkar.h"
#include "boolean.h"

int main(){
    FILE * pitakar;
    typedef char Kata[10];
    typedef Kata infotype;
    char peta[9][10];
    int i,j;

    pitakar = fopen("pitakar.txt","r");
    i=1;
    j=1;
    START();
    while(CC != '.'){
        //j++;
        /*if(CC == '|'){
            j = 1;
            i++;
        }*/
        //else{
        peta[i][j] = CC;
            //printf("%s\n",peta[i][j]);
        //}
        ADV();
        while(CC == ' '){
            ADV();
        }
        j++;
        if(j == 10){
            j = 1;
            i++;
        }
    }

    for(i=1;i<=8;i++){
        for(j=1;j<=8;j++){
            printf("%c ",peta[i][j]);
        }
        printf("\n");
    }

    fclose(pitakar);
    return 0;
}
