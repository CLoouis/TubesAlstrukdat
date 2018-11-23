#include "boas.h"
#include <string.h>
#include "boolean.h"
//#include "tipebentukan.h"

// char peta[9][9];// peta adalah peta kitchen
// char peta2[9][9];//peta adalah peta ruang 

void AddQueue(){
    int sabarluar; //QPatience
    int sabardalam; //Patience
    int banyak; //jumlah 
    int pesan;
    infotypeCust pasien;

    pasien.patience = (rand() % 30) + 80;
    pasien.qpatience = (rand() % 30) + 60;
    pasien.jumlah = (rand() % 3) + 2;
    strcpy(pasien.order, DaftarResep[(rand() % 8) + 1]);
    pasien.isi = false;
    Add(&AntrianLuar,pasien);
}

boolean IsReachable(Player P, int x, int y, int jarak){
// Player P, x,y menyatakan koordinat tujuan, jarak menyatakan jarak yang kita mau, utk room 2, utk kitchen 1
    return (jarak >= (abs(P.Posisi.X - x) + abs(P.Posisi.Y - y)));
}

void Order(Player P){
    int i;
    boolean found;

    found = false;
    i=1;
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
        strcpy(DaftarOrder[i],arrayCust[i].order);
    }
}

void Put(Player *P){
    if(!(((*P).Posisi.X == 1 && (*P).Posisi.Y == 7) || ((*P).Posisi.X == 2 && (*P).Posisi.Y == 7) || ((*P).Posisi.X == 2 && (*P).Posisi.Y == 8))){
        printf("Posisi tidak disebelah tray");
    }
    else{ 
        if(strcmp(InfoTop(Hand(*P)),"Pisang") == 0){
            CH(P);
            Push(&FoodStack(*P), "Banana Split");
        }
        else if(strcmp(InfoTop(Hand(*P)),"Strawberry") == 0){
            CH(P);
            Push(&FoodStack(*P), "Sundae");
        } 
        else if(strcmp(InfoTop(Hand(*P)),"Telur") == 0){
            CH(P);
            Push(&FoodStack(*P), "Nasi Telur Dadar");
        }
        else if(strcmp(InfoTop(Hand(*P)),"Ayam Goreng") == 0){
            CH(P);
            Push(&FoodStack(*P), "Nasi Ayam Goreng");
        }
        else if(strcmp(InfoTop(Hand(*P)),"Patty") == 0){
            CH(P);
            Push(&FoodStack(*P), "Burger");
        }
        else if(strcmp(InfoTop(Hand(*P)),"Sosis") == 0){
            CH(P);
            Push(&FoodStack(*P), "Hot Dog");
        }
        else if(strcmp(InfoTop(Hand(*P)),"Keju") == 0){
            CH(P);
            Push(&FoodStack(*P), "Spaghetti Bolognese");
        }
        else if(strcmp(InfoTop(Hand(*P)),"Carbonara") == 0){
            CH(P);
            Push(&FoodStack(*P), "Spaghetti Carbonara");
        }
        else{
            printf("Loh kok masuk sini?");
        }

    }
}

void Place(Player P){//Ubah c ke x
    int N; //Jumlah orang antrian terdepan
    boolean found;
    infotypeCust X;


    //Del(&AntrianLuar,&X);
    found = false;
    N = X.jumlah;
    int i,j;
    i = 1;

    while(!found && (i<=4)){ //Cari meja yang dapat diraih
        found = IsReachable(P,DaftarMeja[i].X,DaftarMeja[i].Y,2); //Tidak ada meja yang terjangkau
        if(!found){
            i++;
        }
    }
    if(!found){ //Tidak ada meja yang dapat diraih
        printf("Tidak ada meja yang dapat dijangkau\n");
    }
    else{ //ada meja yang dapat diraih
        i += (P.room-1) * 4; //i adalah indeks arrayCust
        j = 1;
        found = false;
        while(!found && (j<=NBElmtQueue(AntrianLuar))){
            found = arrayCust[i].jumlah < AntrianLuar.T[j].jumlah;
            if(found){
                break;
            }
            j++;
        }
        if(!found){
            printf("Kapasitas kursi tidak cukup\n");
        }
        else{
            for(;j<=Tail(AntrianLuar)-1;j++){
                AntrianLuar.T[j] = AntrianLuar.T[j+1];
            }
            Tail(AntrianLuar)--;
            arrayCust[i].isi = true;
            arrayCust[i].jumlah = X.jumlah;
            strcpy(arrayCust[i].order,X.order);
            arrayCust[i].patience = X.patience;
        }
    }   
}

void Give(Player P){
    int i;
    boolean found;

    found = false;
    i=1;
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
        if(strcmp(arrayCust[i].order,InfoTop(P.FoodStack))){
            if(strcmp(arrayCust[i].order,"Spaghetti Bolognese")){
                P.money += 150;
            }
            else{
                P.money += 100;
            }
            arrayCust[i].isi = false;
        }
        else{
            printf("Pesanan tidak sesuai meja\n");
        }
    }
}

void CH(Player *P){
    KataString temp;

    while(!IsStackEmpty(Hand(*P))){
        Pop(&Hand(*P),temp);
    }
}

void CT(Player *P){
    KataString temp;

    while(!IsStackEmpty(FoodStack(*P))){
        Pop(&FoodStack(*P),temp);
    }
}

void Take(Player *P, POINT *pts){
    boolean found;
    // int jarak = 1;
    POINT pt; // pt : Posisi M

    found = false;
    if((!found) && ((*P).Posisi.X != 1)){
        found = (Ruang(ruangan,4,(*P).Posisi.X - 1,(*P).Posisi.Y) == 'M');
        if(found){
            pt.X = (*P).Posisi.X -1;
            pt.Y = (*P).Posisi.Y;
        }
    }
    if((!found) && ((*P).Posisi.Y != 8)){
        found = (Ruang(ruangan,4,(*P).Posisi.X,(*P).Posisi.Y+1) == 'M');
        if(found){
            pt.X = (*P).Posisi.X ;
            pt.Y = (*P).Posisi.Y+1;
        }
    }
    if((!found) && ((*P).Posisi.X != 8)){
        found = (Ruang(ruangan,4,(*P).Posisi.X+1,(*P).Posisi.Y) == 'M');
        if(found){
            pt.X = (*P).Posisi.X+1;
            pt.Y = (*P).Posisi.Y;
        }
    }
    if((!found) && ((*P).Posisi.Y != 1)){
        found = (Ruang(ruangan,4,(*P).Posisi.X,(*P).Posisi.Y-1) == 'M');
        if(found){
            pt.X = (*P).Posisi.X;
            pt.Y = (*P).Posisi.Y-1;
        }
    }
    if((pt.X == 1) && (pt.Y == 1)){ //1
        if(strcmp(InfoTop(Hand(*P)),"Bolognese") == 0){
            Push(&Hand(*P), "Keju");   
        }
        else{
            printf("Eits, jangan ambil keju dulu\n");
        } 
    }
    else if((pt.X == 2) && (pt.Y == 1)){ //2
        if(strcmp(InfoTop(Hand(*P)),"Spaghetti") == 0){
            Push(&Hand(*P), "Bolognese");   
        }
        else{
            printf("Eits, jangan ambil bolognese dulu\n");
        } 
    }
    else if((pt.X == 3) && (pt.Y == 1)){ //3
        if(strcmp(InfoTop(Hand(*P)),"Spaghetti") == 0){
            Push(&Hand(*P), "Carbonara");   
        }
        else{
            printf("Eits, jangan ambil carbonara dulu\n");
        } 
    }
    else if((pt.X == 4) && (pt.Y == 1)){ //4
        if(strcmp(InfoTop(Hand(*P)),"Garpu") == 0){
            Push(&Hand(*P), "Spaghetti");   
        }
        else{
            printf("Eits, jangan ambil Spaghetti dulu\n");
        } 
    }
    else if((pt.X == 5) && (pt.Y == 1)){ //5
        if(strcmp(InfoTop(Hand(*P)),"Garpu") == 0){
            Push(&Hand(*P), "Roti");   
        }
        else{
            printf("Eits, jangan ambil roti dulu\n");
        } 
    }
    else if((pt.X == 6) && (pt.Y == 1)){ //6
        if(strcmp(InfoTop(Hand(*P)),"Roti") == 0){
            Push(&Hand(*P), "Patty");   
        }
        else{
            printf("Eits, jangan ambil patty dulu\n");
        } 
    }
    else if((pt.X == 7) && (pt.Y == 1)){ //7
        if(strcmp(InfoTop(Hand(*P)),"Roti") == 0){
            Push(&Hand(*P), "Sosis");   
        }
        else{
            printf("Eits, jangan ambil sosis dulu\n");
        } 
    }
    else if((pt.X == 8) && (pt.Y == 1)){ //8
        if(strcmp(InfoTop(Hand(*P)),"Es Krim") == 0){
            Push(&Hand(*P), "Strawberry");   
        }
        else{
            printf("Eits, jangan ambil strawberry dulu\n");
        } 
    }
    else if((pt.X == 5) && (pt.Y == 4)){ //9
        if(strcmp(InfoTop(Hand(*P)),"Piring") == 0){
            Push(&Hand(*P), "Garpu");   
        }
        else{
            printf("Eits, jangan ambil garpu dulu\n");
        } 
    }
    else if((pt.X == 5) && (pt.Y == 5)){ //10
        if(IsStackEmpty(Hand(*P))){
            Push(&Hand(*P), "Piring");   
        }
        else{
            printf("Eits, jangan ambil piring dulu\n");
        }
    }
    else if((pt.X == 5) && (pt.Y == 6)){ //11
        if(strcmp(InfoTop(Hand(*P)),"Piring") == 0){
            Push(&Hand(*P), "Sendok");   
        }
        else{
            printf("Eits, jangan ambil sendok dulu\n");
        } 
    }
    else if((pt.X == 8) && (pt.Y == 4)){ //12
        if(strcmp(InfoTop(Hand(*P)),"Es Krim") == 0){
            Push(&Hand(*P), "Pisang");   
        }
        else{
            printf("Eits, jangan ambil pisang dulu\n");
        } 
    }
    else if((pt.X == 8) && (pt.Y == 5)){ //13
        if(strcmp(InfoTop(Hand(*P)),"Sendok") == 0){
            Push(&Hand(*P), "Es Krim");   
        }
        else{
            printf("Eits, jangan ambil es krim dulu\n");
        } 
    }
    else if((pt.X == 8) && (pt.Y == 6)){ //14
        if(strcmp(InfoTop(Hand(*P)),"Sendok") == 0){
            Push(&Hand(*P), "Nasi");   
        }
        else{
            printf("Eits, jangan ambil nasi dulu\n");
        } 
    }
    else if((pt.X == 8) && (pt.Y == 7)){ //15
        if(strcmp(InfoTop(Hand(*P)),"Nasi") == 0){
            Push(&Hand(*P), "Telur");   
        }
        else{
            printf("Eits, jangan ambil telur dulu\n");
        } 
    }
    else if((pt.X == 8) && (pt.Y == 8)){ //16
        if(strcmp(InfoTop(Hand(*P)),"Nasi") == 0){
            Push(&Hand(*P), "Ayam Goreng");   
        }
        else{
            printf("Eits, jangan ambil ayam goreng dulu\n");
        } 
    }
    (*pts).X = pt.X;
    (*pts).Y = pt.Y;
}

void Recipe(){
    PrintTree(Resep,2);
}

void NextTick(Player P){
    int i; //Elemen queue
    int j; //Buat menggeser queue belakangnya

    P.time++;
    //Kurangi kesabaran antrian luar
    for(i=1;i<=Tail(AntrianLuar);i++){
        AntrianLuar.T[i].qpatience--;
        if(AntrianLuar.T[i].qpatience == 0){ //Jika ada yang habis kesabaran
            for(j=i;j<=Tail(AntrianLuar)-1;j++){
                AntrianLuar.T[j] = AntrianLuar.T[j+1];
            }
            Tail(AntrianLuar)--;
            Life(P)--;
        }
    }

    //Kurangi kesabaran antrian dalam
    for(i=1;i<=12;i++){
        if(arrayCust[i].isi){
            arrayCust[i].patience--;
            if(arrayCust[i].patience == 0){ //Habis kesabaran
                arrayCust[i].isi = false;
                Life(P)--;
            }
        }
    }

    //Selesaikan permainan jika life 0, panggil credit
    if(Life(P) == 0){
        Credit();
    }
    if((P.time % 60) == 0){
        AddQueue();
    }
}

void Credit(){
    printf("GAME ENDED\n");
    printf("CREATED BY:");
    printf("Johanes Boas - 13517009\n");
    printf("Kevin Nathaniel - 13517072\n");
    printf("Timothy - 13517087\n");
    printf("Louis Cahyadi - 13517126\n");
    printf("Special thanks to Panawar Hasibuan :)\n");
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

    // Kata temp;
    POINT poin;
    Player pemain;
    Ruang(ruangan,4,1,1) = 'M';
    Ruang(ruangan,4,2,1) = 'M';
    Ruang(ruangan,4,3,1) = 'M';
    Ruang(ruangan,4,4,1) = 'M';
    Ruang(ruangan,4,5,1) = 'M';
    Ruang(ruangan,4,6,1) = 'M';
    Ruang(ruangan,4,7,1) = 'M';
    Ruang(ruangan,4,8,1) = 'M';
    Ruang(ruangan,4,5,4) = 'M';
    Ruang(ruangan,4,5,5) = 'M';
    Ruang(ruangan,4,5,6) = 'M';
    Ruang(ruangan,4,8,4) = 'M';
    Ruang(ruangan,4,8,5) = 'M';
    Ruang(ruangan,4,8,6) = 'M';
    Ruang(ruangan,4,8,7) = 'M';
    Ruang(ruangan,4,8,8) = 'M';

    strcpy(DaftarResep[1],"Banana Split");
    strcpy(DaftarResep[2],"Sundae");
    strcpy(DaftarResep[3],"Nasi Telur Dadar");
    strcpy(DaftarResep[4],"Nasi Ayam Goreng");
    strcpy(DaftarResep[5],"Burger");
    strcpy(DaftarResep[6],"Hot Dog");
    strcpy(DaftarResep[7],"Spaghetti Bolognese");
    strcpy(DaftarResep[8],"Spaghetti Carbonara");


    CreateStackEmpty(&FoodStack(pemain));
    CreateStackEmpty(&Hand(pemain));
    MakeTree("Piring",Tree("Sendok",Tree("Es Krim",Tree("Pisang",Tree("Banana Split",Nil,Nil),Nil),Tree("Stroberi",Tree("Sundae",Nil,Nil),Nil)),Tree("Nasi",Tree("Telur",Tree("Nasi Telur Dadar",Nil,Nil),Nil),Tree("Ayam Goreng",Tree("Nasi Ayam Goreng",Nil,Nil),Nil)))
                     ,Tree("Garpu",Tree("Roti",Tree("Patty",Tree("Burger",Nil,Nil),Nil),Tree("Sosis",Tree("Hot Dog",Nil,Nil),Nil)),Tree("Spaghetti",Tree("Bolognese",Tree("Keju",Tree("Spaghetti Bolognese",Nil,Nil),Nil),Nil),Tree("Carbonara",Tree("Spaghetti Carbonara",Nil,Nil),Nil))),&Resep);
    //Recipe();
	//Push(&FoodStack(pemain),"Kentang");
	//Push(&FoodStack(pemain),"Brokoli");
	//printf("%s",InfoTop(FoodStack(pemain)));
    pemain.Posisi.X = 2;
    pemain.Posisi.Y = 2;   
    pemain.room = 4;
    
    printf("%c\n",Ruang(ruangan,1,1,1));
    //strcpy(arrayCust[1].order,"Kuda Bakar");
    //Order(pemain);
    //printf("%s\n",DaftarOrder[1]);
    //Take(&pemain, &poin);
    //printf("%s\n",InfoTop(Hand(pemain)));
    //pemain.x = 6;
    //pemain.y = 5;
    //Take(&pemain, &poin);
    //printf("%s\n",InfoTop(Hand(pemain)));
    //CH(&pemain);
    //printf("%s\n",InfoTop(Hand(pemain)));
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





