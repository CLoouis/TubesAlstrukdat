#include"boas.h"
//#include "tipebentukan.h"

char peta[9][9];// peta adalah peta kitchen
char peta2[9][9];//peta adalah peta ruang 

boolean IsReachable(Player P, int x, int y, int jarak){
// Player P, x,y menyatakan koordinat tujuan, jarak menyatakan jarak yang kita mau, utk room 2, utk kitchen 1
    return (jarak >= (abs(P.Posisi.X - x) + abs(P.Posisi.Y - y)));
}

void Order(Player P){
    if(IsReachable(P, 2, 2, 2)){
        if(P.room == 1){
            strcpy(DaftarOrder[1],arrayCust[1].order);
        }
        else if(P.room == 2){
            strcpy(DaftarOrder[5],arrayCust[5].order);
        }
        else if(P.room == 3){
            strcpy(DaftarOrder[9],arrayCust[9].order);
        }
    }
    if(IsReachable(P, 2, 7, 2)){
        if(P.room == 1){
            strcpy(DaftarOrder[2],arrayCust[2].order);
        }
        else if(P.room == 2){
            strcpy(DaftarOrder[6],arrayCust[6].order);
        }
        else if(P.room == 3){
            strcpy(DaftarOrder[10],arrayCust[10].order);
        }
    }
    if(IsReachable(P, 7, 2, 2)){
        if(P.room == 1){
            strcpy(DaftarOrder[3],arrayCust[3].order);
        }
        else if(P.room == 2){
            strcpy(DaftarOrder[7],arrayCust[7].order);
        }
        else if(P.room == 3){
            strcpy(DaftarOrder[11],arrayCust[11].order);
        }
    }
    if(IsReachable(P, 7, 7, 2)){
        if(P.room == 1){
            strcpy(DaftarOrder[4],arrayCust[4].order);
        }
        else if(P.room == 2){
            strcpy(DaftarOrder[8],arrayCust[8].order);
        }
        else if(P.room == 3){
            strcpy(DaftarOrder[12],arrayCust[12].order);
        }
    }
}

void Put(){
}

void Place(Player P, Customer C, Queue Q){
    int N;
    boolean found;

    found = false;
    N = InfoHead(Q).jumlah;
    int i;
    i = 1;

    while(!found && (i<=4)){
        found = IsReachable(P,DaftarMeja[i].X,DaftarMeja[i].Y,2); //Tidak ada meja yang terjangkau
        if(!found){
            i++;
        }
    }
    if(!found){
        printf("Tidak ada meja yang dapat dijangkau\n");
    }
    else{
        i += (P.room-1) * 4; //i adalah indeks arrayCust
        if(arrayCust[i].jumlah >= C.jumlah){ //Meja cukup besar
            arrayCust[i].isi = true;
            arrayCust[i].jumlah = C.jumlah;
            strcpy(C.order,arrayCust[i].order);
            arrayCust[i].patience = C.patience;
        }
        else{
            printf("Tidak ada meja yang dapat dijangkau\n");
        }
    }
    
    
}



void CH(Player *P){
    infotype temp;

    while(!IsStackEmpty(Hand(*P))){
        Pop(&Hand(*P),temp);
    }
}


void Take(Player *P, POINT *pts){
    boolean found;
    int jarak = 1;
    POINT pt; // pt : Posisi M

    found = false;
    if((!found) && ((*P).Posisi.X != 1)){
        found = (peta[(*P).Posisi.X - 1][(*P).Posisi.Y] == 'M');
        if(found){
            pt.X = (*P).Posisi.X -1;
            pt.Y = (*P).Posisi.Y;
        }
    }
    if((!found) && ((*P).Posisi.Y != 8)){
        found = (peta[(*P).Posisi.X][(*P).Posisi.Y+1] == 'M');
        if(found){
            pt.X = (*P).Posisi.X ;
            pt.Y = (*P).Posisi.Y+1;
        }
    }
    if((!found) && ((*P).Posisi.X != 8)){
        found = (peta[(*P).Posisi.X+1][(*P).Posisi.Y] == 'M');
        if(found){
            pt.X = (*P).Posisi.X+1;
            pt.Y = (*P).Posisi.Y;
        }
    }
    if((!found) && ((*P).Posisi.Y != 1)){
        found = (peta[(*P).Posisi.X][(*P).Posisi.Y-1] == 'M');
        if(found){
            pt.X = (*P).Posisi.X;
            pt.Y = (*P).Posisi.Y-1;
        }
    }
    if((pt.X == 1) && (pt.X == 1)){ //1
        Push(&Hand(*P), "Keju");    
    }
    else if((pt.X == 2) && (pt.Y == 1)){ //2
        Push(&Hand(*P), "Bolognaise");
    }
    else if((pt.X == 3) && (pt.Y == 1)){ //3
        Push(&Hand(*P), "Carbonara");
    }
    else if((pt.X == 4) && (pt.Y == 1)){ //4
        Push(&Hand(*P), "Spaghetti");
    }
    else if((pt.X == 5) && (pt.Y == 1)){ //5
        Push(&Hand(*P), "Roti");
    }
    else if((pt.X == 6) && (pt.Y == 1)){ //6
        Push(&Hand(*P), "Patty");
    }
    else if((pt.X == 7) && (pt.Y == 1)){ //7
        Push(&Hand(*P), "Sosis");
    }
    else if((pt.X == 8) && (pt.Y == 1)){ //8
        Push(&Hand(*P), "Strawberry");
    }
    else if((pt.X == 5) && (pt.Y == 4)){ //9
        Push(&Hand(*P), "Garpu");
    }
    else if((pt.X == 5) && (pt.Y == 5)){ //10
        Push(&Hand(*P), "Piring");
    }
    else if((pt.X == 5) && (pt.Y == 6)){ //11
        Push(&Hand(*P), "Sendok");
    }
    else if((pt.X == 8) && (pt.Y == 4)){ //12
        Push(&Hand(*P), "Pisang");
    }
    else if((pt.X == 8) && (pt.Y == 5)){ //13
        Push(&Hand(*P), "Es Krim");
    }
    else if((pt.X == 8) && (pt.Y == 6)){ //14
        Push(&Hand(*P), "Nasi");
    }
    else if((pt.X == 8) && (pt.Y == 7)){ //15
        Push(&Hand(*P), "Telur");
    }
    else if((pt.X == 8) && (pt.Y == 8)){ //16
        Push(&Hand(*P), "Ayam Goreng");
    }
    (*pts).X = pt.X;
    (*pts).Y = pt.Y;
}




int main(){
    DaftarMeja[1].X = 2;
    DaftarMeja[1].Y = 2;
    DaftarMeja[2].X = 2;
    DaftarMeja[2].Y = 7;
    DaftarMeja[3].X = 7;
    DaftarMeja[3].Y = 2;
    DaftarMeja[4].X = 7;
    DaftarMeja[4].Y = 7;

    infotype temp;
    POINT poin;
    Player pemain;
    peta[1][1] = 'M';
    peta[2][1] = 'M';
    peta[3][1] = 'M';
    peta[4][1] = 'M';
    peta[5][1] = 'M';
    peta[6][1] = 'M';
    peta[7][1] = 'M';
    peta[8][1] = 'M';
    peta[5][4] = 'M';
    peta[5][5] = 'M';
    peta[5][6] = 'M';
    peta[8][4] = 'M';
    peta[8][5] = 'M';
    peta[8][6] = 'M';
    peta[8][7] = 'M';
    peta[8][8] = 'M';

    CreateStackEmpty(&FoodStack(pemain));
    CreateStackEmpty(&Hand(pemain));
	//Push(&FoodStack(pemain),"Kentang");
	//Push(&FoodStack(pemain),"Brokoli");
	//printf("%s",InfoTop(FoodStack(pemain)));
    pemain.Posisi.X = 1;
    pemain.Posisi.Y = 3;   
    Take(&pemain, &poin);
    printf("%s\n",InfoTop(Hand(pemain)));
    //pemain.x = 6;
    //pemain.y = 5;
    //Take(&pemain, &poin);
    //printf("%s\n",InfoTop(Hand(pemain)));
    CH(&pemain);
    printf("%s\n",InfoTop(Hand(pemain)));
    //Pop(&Hand(pemain), temp);
    //printf("%s\n",InfoTop(Hand(pemain)));
    //printf("%s",temp);
    //Pop(&Hand(pemain), temp);
    //printf("%s\n",temp);
    //Pop(&Hand(pemain), temp);
    //printf("%s\n",temp);
    //printf("%s",InfoTop(Hand(pemain)));
    //printf("%d, %d",poin.X, poin.Y);
}





