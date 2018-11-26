#include <stdio.h>
#include <stdlib.h>
#include "stacktangka.h"

int main(){
    StackAngka S;
    CreateEmptyAngka(&S);
    PushAngka(&S,5);
    printf("%d\n",InfoTop(S));
}