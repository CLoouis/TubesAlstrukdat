#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "listrek.h"

int CountPos(List L){
    int hasil;
    
    if(IsEmpty(L)){
        return 0;
    }
    else{
        if(Info(L) > 0){
            return (1 + CountPos(Tail(L)));
        }
        else{
            return(CountPos(Tail(L)));
        }
    }
}

int SumPos(List L){
    if(IsEmpty(L)){
        return 0;
    }
    else{
        if(Info(L) > 0){
            return (Info(L) + SumPos(Tail(L)));
        }
        else{
            return SumPos(Tail(L));
        }
    }
}

boolean IsMember(List L, infotype X){
    if(IsEmpty(L)){
        return false;
    }
    else{
        if(Info(L) == X){
            return true;
        }
        else{
            IsMember(Tail(L),X);
        }
    }
}

boolean IsEqual(List L1, List L2){
    if(IsEmpty(L1) || (IsEmpty(L2))){
        return (IsEmpty(L1) && (IsEmpty(L2)));
    }
    else{
        if(Info(L1) == Info(L2)){
            return IsEqual(Tail(L1),Tail(L2));
        }
        else{
            return false;
        }
    }
}

void MinMax(List L, int *Min, int *Max){
    
    if(NbElmtList(L) == 1){
        *Min = Info(L);
        *Max = Info(L);
    }
    else{
        MinMax(Tail(L), Min, Max);
        if(Info(L) < *Min){
            *Min = Info(L);
        }

        if(Info(L) > *Max){
            *Max = Info(L);
        }
    }
}

List ListPlus(List L1,List L2)
{
    if(IsEmpty(L1))
    {
        return Nil;
    } else
    {
        return Konso((FirstElmt(L1)+FirstElmt(L2)),ListPlus(Tail(L1),Tail(L2)));
    }
}

int main(){
    List LCopy,L,L2;
    int min,max;

    L = Nil;
    L2 = Nil;
    LCopy = Nil;

    L = Konso(5,L);
    L = KonsB(L,-5);
    L = Konso(2,L);
    L = KonsB(L,7);
    L = Konso(10,L);

    L2 = Konso(5,L2);
    L2 = KonsB(L2,-5);
    L2 = Konso(2,L2);
    L2 = KonsB(L2,7);
    L2 = Konso(10,L2);

    printf("List L:\n");
    PrintList(L);

    printf("List L2:\n");
    PrintList(L2);
    printf("Banyak bilangan positif adalah %d\n",CountPos(L));
    printf("Jumlah bilangan positif adalah %d\n",SumPos(L));
    if(IsMember(L,12)){
        printf("ketemu\n");
    }
    else{
        printf("tidak ketemu\n");
    }
    if(IsEqual(L,L2)){
        printf("L dan L2 sama\n");
    }
    else{
        printf("L dan L2 tidak sama\n");
    }

    MinMax(L,&min,&max);
    printf("Min : %d\nMax : %d\n",min,max);
    //MConcat(L,L2,&LCopy);
    //PrintList(LCopy);
    PrintList(ListPlus(L,L2));
    return 0;
}
