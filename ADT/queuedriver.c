#include <stdio.h>
#include "queue.h"
#include "boolean.h"

int main(){
    Queue antrian;
    int i,x;
    
    CreateEmpty(&antrian,5);
    if(IsEmpty(antrian)){
        printf("Tabel Kosong\n");
    }
    else{
        printf("Tabel sudah terisi\n");
    }

    for(i=1;i<=(antrian.MaxEl);i++){
        Add(&antrian,i);
    }
    Del(&antrian,&x);
    printf("%d\n",x);
    printf("%d\n",NBElmt(antrian));

    if(IsEmpty(antrian)){
        printf("Tabel Kosong\n");
    }
    else{
        printf("Tabel sudah terisi\n");
    }
}

