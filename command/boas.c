#include "boas.h"
#include <string.h>
#include "../ADT/graph.h"
#include "../ADT/boolean.h"
#include "../ADT/mesinkata2.h"
#include "../ADT/mesinkar2.h"
#include "SaveLoad.h"
// #include "tipebentukan.h"

// char peta[9][9];// peta adalah peta kitchen
// char peta2[9][9];//peta adalah peta ruang 

void GoUp(Player *P){
    Pintu door;
    if ((*P).Posisi.X == 1){
        if(((*P).Posisi.Y == 5) && ((*P).room == 4)){
            (*P).room = 1;
            (*P).Posisi.X = 8;
            (*P).Posisi.Y = 5;
            Ruang(ruangan,Id(P7).X,Id(P7).Y,Id(P7).Z) = '-';
            Ruang(ruangan,Id(Succ(Trail(P7))).X,Id(Succ(Trail(P7))).Y,Id(Succ(Trail(P7))).Z) = 'P';
        }
        else if(((*P).Posisi.Y == 5) && ((*P).room == 3)){
            (*P).room = 2;
            (*P).Posisi.X = 8;
            (*P).Posisi.Y = 5;
            Ruang(ruangan,Id(P4).X,Id(P4).Y,Id(P4).Z) = '-';
            Ruang(ruangan,Id(Succ(Trail(P4))).X,Id(Succ(Trail(P4))).Y,Id(Succ(Trail(P4))).Z) = 'P';
        }
        else{
            printf("Mentok Bos\n");
        }
    } else if((Ruang(ruangan,(*P).room,((*P).Posisi.X)-1,(*P).Posisi.Y) != '-')){
        printf("Nabrak Bos\n");
    } else {
        Ruang(ruangan,(*P).room,(*P).Posisi.X,(*P).Posisi.Y) = '-';
        Ruang(ruangan,(*P).room,((*P).Posisi.X) - 1,(*P).Posisi.Y) = 'P';
        (*P).Posisi.X--;
    }
    NextTick(P);
}

void GoDown(Player *P){
    if ((*P).Posisi.X == 8){
        if(((*P).Posisi.Y == 5) && ((*P).room == 1)){
            (*P).room = 4;
            (*P).Posisi.X = 1;
            (*P).Posisi.Y = 5;
            Ruang(ruangan,Id(P8).X,Id(P8).Y,Id(P8).Z) = '-';
            Ruang(ruangan,Id(Succ(Trail(P8))).X,Id(Succ(Trail(P8))).Y,Id(Succ(Trail(P8))).Z) = 'P';
        }
        else if(((*P).Posisi.Y == 5) && ((*P).room == 2)){
            (*P).room = 3;
            (*P).Posisi.X = 1;
            (*P).Posisi.Y = 5;
            Ruang(ruangan,Id(P3).X,Id(P3).Y,Id(P3).Z) = '-';
            Ruang(ruangan,Id(Succ(Trail(P3))).X,Id(Succ(Trail(P3))).Y,Id(Succ(Trail(P3))).Z) = 'P';
        }
        else{
            printf("Mentok Bos\n");
        }
    } else if((Ruang(ruangan,(*P).room,((*P).Posisi.X) + 1,(*P).Posisi.Y)  != '-')){
        printf("Nabrak Bos\n");
    } else {
        Ruang(ruangan,(*P).room,(*P).Posisi.X,(*P).Posisi.Y) = '-';
        Ruang(ruangan,(*P).room,((*P).Posisi.X) + 1,(*P).Posisi.Y) = 'P';
        (*P).Posisi.X++;
    }
    NextTick(P);
}

void GoRight(Player *P){
    if ((*P).Posisi.Y == 8){
        if(((*P).Posisi.X == 5) && ((*P).room == 1)){
            (*P).room = 2;
            (*P).Posisi.X = 2;
            (*P).Posisi.Y = 1;
            Ruang(ruangan,Id(P1).X,Id(P1).Y,Id(P1).Z) = '-';
            Ruang(ruangan,Id(Succ(Trail(P1))).X,Id(Succ(Trail(P1))).Y,Id(Succ(Trail(P1))).Z) = 'P';
        }
        else if(((*P).Posisi.X == 5) && ((*P).room == 4)){
            (*P).room = 3;
            (*P).Posisi.X = 2;
            (*P).Posisi.Y = 1;
            Ruang(ruangan,Id(P6).X,Id(P6).Y,Id(P6).Z) = '-';
            Ruang(ruangan,Id(Succ(Trail(P6))).X,Id(Succ(Trail(P6))).Y,Id(Succ(Trail(P6))).Z) = 'P';
        }
        else{
            printf("Mentok Bos\n");
        }
    } else if((Ruang(ruangan,(*P).room,((*P).Posisi.X),((*P).Posisi.Y) + 1) != '-')){
        printf("Nabrak Bos\n");
    } else {
        Ruang(ruangan,(*P).room,(*P).Posisi.X,(*P).Posisi.Y) = '-';
        Ruang(ruangan,(*P).room,((*P).Posisi.X),(*P).Posisi.Y + 1) = 'P';
        (*P).Posisi.Y++;
    }
    NextTick(P);
}

void GoLeft(Player *P){
    if ((*P).Posisi.Y == 1){
        if(((*P).Posisi.X == 2) && ((*P).room == 2)){
            (*P).room = 1;
            (*P).Posisi.X = 5;
            (*P).Posisi.Y = 8;
            Ruang(ruangan,Id(P2).X,Id(P2).Y,Id(P2).Z) = '-';
            Ruang(ruangan,Id(Succ(Trail(P2))).X,Id(Succ(Trail(P2))).Y,Id(Succ(Trail(P2))).Z) = 'P';
        }
        else if(((*P).Posisi.X == 2) && ((*P).room == 3)){
            (*P).room = 4;
            (*P).Posisi.X = 5;
            (*P).Posisi.Y = 8;
            Ruang(ruangan,Id(P5).X,Id(P5).Y,Id(P5).Z) = '-';
            Ruang(ruangan,Id(Succ(Trail(P5))).X,Id(Succ(Trail(P5))).Y,Id(Succ(Trail(P5))).Z) = 'P';
        }
        else{
            printf("Mentok Bos\n");
        }
    } else if((Ruang(ruangan,(*P).room,((*P).Posisi.X),((*P).Posisi.Y) - 1) != '-')){
        printf("Nabrak Bos\n");
        printf("%c\n",Ruang(ruangan,(*P).room,((*P).Posisi.X),((*P).Posisi.Y) - 1));
    } else {
        Ruang(ruangan,(*P).room,(*P).Posisi.X,(*P).Posisi.Y) = '-';
        Ruang(ruangan,(*P).room,((*P).Posisi.X),(*P).Posisi.Y - 1) = 'P';
        (*P).Posisi.Y--;
    }
    NextTick(P);
}

void AddQueue(Player P){
    infotypeCust pasien;

    pasien.patience = (rand() % 30) + 80;
    pasien.qpatience = 30;
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
        strcpy(DaftarOrder(DaftarOrder,i),arrayCust(arrayCust,i).order);
    }
    NextTick(&P);
}

void Put(Player *P){
    if(!(IsReachable(*P, 1, 8, 1))){
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
    NextTick(P);
}

void Place(Player P){//Ubah c ke x
    int N; //Jumlah orang antrian terdepan
    boolean found;
    infotypeCust X;


    //Del(&AntrianLuar,&X);
    found = false;
    // N = X.jumlah;
    int i,j;
    i = 1;

    while(!found && (i<=4)){ //Cari meja yang dapat diraih
        found = IsReachable(P,DaftarMeja[i].X,DaftarMeja[i].Y,2); 
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
        while(!found && (j<=Tail(AntrianLuar))){
            found = KursiMeja[i] >= AntrianLuar.T[j].jumlah;
            if(found){
                // break;
            }
            else{
                j++;
            }
            
        }
        if(!found){
            printf("Kapasitas kursi tidak cukup\n");
        }
        else{
            if(arrayCust(arrayCust,i).isi == false){
                X = AntrianLuar.T[j];
                for(;j<=Tail(AntrianLuar)-1;j++){
                    AntrianLuar.T[j] = AntrianLuar.T[j+1];
                }
                Tail(AntrianLuar)--;
                arrayCust(arrayCust,i).isi = true;
                arrayCust(arrayCust,i).jumlah = X.jumlah;
                strcpy(arrayCust(arrayCust,i).order,X.order);
                arrayCust(arrayCust,i).patience = X.patience;
                arrayCust(arrayCust,i).qpatience = X.qpatience;
            }
            else{
                printf("Meja sudah terisi\n");
            }
        }
    }   
    NextTick(&P);
    UpdatePeta(P,&ruangan, arrayCust);

}

void Give(Player *P){
    int i;
    boolean found;
    KataString temp;

    found = false;
    i=1;
     while(!found && (i<=4)){
        found = IsReachable((*P),DaftarMeja[i].X,DaftarMeja[i].Y,2); //Tidak ada meja yang terjangkau
        if(!found){
            i++;
        }
    }
    if(!found){
        printf("Tidak ada meja yang dapat dijangkau\n");
    }
    else{
        i += ((*P).room-1) * 4; //i adalah indeks arrayCust
        if(strcmp(arrayCust(arrayCust,i).order,InfoTop(FoodStack(*P))) == 0){
            if(strcmp(arrayCust(arrayCust,i).order,"Spaghetti Bolognese") == 0){
                (*P).money += 150;
                // printf("%d\n",P.money);
                // printf("sampe\n");
            }
            else{
                (*P).money += 100;
            }
            arrayCust(arrayCust,i).isi = false;
            Pop(&FoodStack(*P),temp);
        }
        else{
            printf("Pesanan tidak sesuai meja\n");
        }
    }
    NextTick(P);
    UpdatePeta(*P,&ruangan, arrayCust);
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
    NextTick(P);
}

void Take(Player *P){
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
    NextTick(P);
}

void Recipe(){
    PrintTree(Resep,2);
}

void NextTick(Player *P){
    int i; //Elemen queue
    int j; //Buat menggeser queue belakangnya

    (*P).time++;
    //Kurangi kesabaran antrian luar
    for(i=1;i<=Tail(AntrianLuar);i++){
        AntrianLuar.T[i].qpatience--;
        if(AntrianLuar.T[i].qpatience == 0){ //Jika ada yang habis kesabaran
            for(j=i;j<=Tail(AntrianLuar)-1;j++){
                AntrianLuar.T[j] = AntrianLuar.T[j+1];
            }
            Tail(AntrianLuar)--;
            Life(*P)--;
        }
    }

    //Kurangi kesabaran antrian dalam
    for(i=1;i<=12;i++){
        if(arrayCust(arrayCust,i).isi){
            arrayCust(arrayCust,i).patience--;
            if(arrayCust(arrayCust,i).patience == 0){ //Habis kesabaran
                arrayCust(arrayCust,i).isi = false;
                Life(*P)--;
            }
        }
    }

    //Selesaikan permainan jika life 0, panggil credit
    if(Life(*P) <= 0){
        Credit();

    }
    if(((*P).time % 60) == 1){
        AddQueue(*P);
    }
    UpdatePeta(*P,&ruangan, arrayCust);
}

void TampilPeta(int room, ruang ruangan){
    
    for (int i = 1; i<9; i++){
        for (int j = 1; j<9; j++){
            printf("%c ",Ruang(ruangan,room,i,j));
        }
        printf("\n");
    }
}

void UpdatePeta(Player P, ruang *ruangan, arrayC arrayCust){
    int i,baris,kolom;

    for(i=1;i<=4;i++){ // i adalah nomor meja tiap ruangan
        baris = DaftarMeja[i].X;
        kolom = DaftarMeja[i].Y;
        for(int j=1;j<=3;j++){ // j adalah nomor ruangan
            if(arrayCust(arrayCust,i +(j-1)*4).isi){ // Ubah kosong jadi terisi
                if(Ruang(*ruangan,j,baris-1,kolom) == 'X'){
                    Ruang(*ruangan,j,baris-1,kolom) = 'C'; 
                }
                if(Ruang(*ruangan,j,baris+1,kolom) == 'X'){
                    Ruang(*ruangan,j,baris+1,kolom) = 'C'; 
                }
                if(Ruang(*ruangan,j,baris,kolom+1) == 'X'){
                    Ruang(*ruangan,j,baris,kolom+1) = 'C'; 
                }
                if(Ruang(*ruangan,j,baris,kolom-1) == 'X'){
                    Ruang(*ruangan,j,baris,kolom-1) = 'C'; 
                }
                if(arrayCust(arrayCust,(i +(j-1)*4)).jumlah == 2){ 
                    if(i == 2 || i == 4){ // 2 orang, posisi horizontal
                        if(Ruang(*ruangan, j, baris-1, kolom) != 'P'){
                            Ruang(*ruangan, j, baris-1, kolom) = '-';
                        }
                        if(Ruang(*ruangan, j, baris+1, kolom) != 'P'){
                            Ruang(*ruangan, j, baris+1, kolom) = '-';
                        }
                    }
                    else{// 2 orang, posisi vertikal
                        if(Ruang(*ruangan, j, baris, kolom-1) != 'P'){
                            Ruang(*ruangan, j, baris, kolom-1) = 'X';
                        }
                        if(Ruang(*ruangan, j, baris, kolom+1) != 'P'){
                            Ruang(*ruangan, j, baris, kolom+1) = 'X';
                        }
                    }
                }
                if(arrayCust(arrayCust,i +(j-1)*4).jumlah == 3){
                    Ruang(*ruangan, j, baris, kolom-1) = 'X';
                }
            }
            else if(!(arrayCust(arrayCust,i +(j-1)*4).isi)) { // Ubah isi jadi kosong
                if(Ruang(*ruangan,j,baris-1,kolom) == 'C'){
                    Ruang(*ruangan,j,baris-1,kolom) = 'X'; 
                }
                if(Ruang(*ruangan,j,baris+1,kolom) == 'C'){
                    Ruang(*ruangan,j,baris+1,kolom) = 'X'; 
                }
                if(Ruang(*ruangan,j,baris,kolom+1) == 'C'){
                    Ruang(*ruangan,j,baris,kolom+1) = 'X'; 
                }
                if(Ruang(*ruangan,j,baris,kolom-1) == 'C'){
                    Ruang(*ruangan,j,baris,kolom-1) = 'X'; 
                }
            }
        }
    }
    // Ruang(ruangan,P.room,P.Posisi.X,P.Posisi.Y) = 'P';
}

void Credit(){
    printf("GAME ENDED\n");
    printf("CREATED BY:\n");
    printf("Johanes Boas - 13517009\n");
    printf("Kevin Nathaniel - 13517072\n");
    printf("Timothy - 13517087\n");
    printf("Louis Cahyadi - 13517126\n");
    printf("Special thanks to Panawar Hasibuan :)\n");
}

void tampilanAwal(){
    //Menampilkan Tampilan awal permainan
    printf("----------------------------------------------\n");
    printf("-----------ENGI'S KITCHEN EXPANSION-----------\n");
    printf("----------------------------------------------\n");
    printf("Silahkan melakukan perintah-perintah berikut: \n");
    printf("1. NEW GAME \n");
    printf("2. START GAME \n");
    printf("3. LOAD GAME \n");
    printf("4. EXIT\n");
}

void Input(Player *P){
    int i;
    boolean Found;
    i = 0;
    STARTKATA2();
    if(CKata2.Length2 == 2){
        if(CKata2.TabKata2[0] == 'G'){
            if(CKata2.TabKata2[1] == 'L'){
                GoLeft(P);
            }
            else if(CKata2.TabKata2[1] == 'U'){
                GoUp(P);
            }
            else if(CKata2.TabKata2[1] == 'D'){
                GoDown(P);
            }
            else if (CKata2.TabKata2[1] == 'R'){
                GoRight(P);
            }
        }
        else if(CKata2.TabKata2[0] == 'C'){
            if(CKata2.TabKata2[1] == 'T'){
                CT(P);
            }
            else if(CKata2.TabKata2[1] == 'H'){
                CH(P);
            }
        }
    }
    else if(CKata2.Length2 == 3){
        if(CKata2.TabKata2[0] == 'P'){
            if(CKata2.TabKata2[1] == 'U'){
                if(CKata2.TabKata2[2] == 'T'){
                    Put(P);
                }
            }
        }
    }
    else if(CKata2.Length2 == 4){
        if(CKata2.TabKata2[0] == 'T'){
            if(CKata2.TabKata2[1] == 'A'){
                if(CKata2.TabKata2[2] == 'K'){
                    if(CKata2.TabKata2[3] == 'E'){
                        Take(P);
                    }
                }
            }
        }
        else if(CKata2.TabKata2[0] == 'G'){
            if(CKata2.TabKata2[1] == 'I'){
                if(CKata2.TabKata2[2] == 'V'){
                    if(CKata2.TabKata2[3] == 'E'){
                        Give(P);
                    }
                }
            }
        }
        else if(CKata2.TabKata2[0] == 'S'){
            if(CKata2.TabKata2[1] == 'A'){
                if(CKata2.TabKata2[2] == 'V'){
                    if(CKata2.TabKata2[3] == 'E'){
                        Save(*P, AntrianLuar, ruangan, arrayCust, DaftarOrder);
                    }
                }
            }
        }
        else if(CKata2.TabKata2[0] == 'L'){
            if(CKata2.TabKata2[1] == 'O'){
                if(CKata2.TabKata2[2] == 'A'){
                    if(CKata2.TabKata2[3] == 'D'){
                        ADVKATA2();
                        strcpy(Name(*P), CKata2.TabKata2);
                        ceksave(Name(*P), &Found);
                        if (Found){
                            Load(P, &AntrianLuar, &ruangan, &arrayCust, &DaftarOrder);
                            printf("Save %s berhasil diload, game diteruskan dengan state yang baru.\n", Name(*P));
                        }
                        else {
                            printf("Nama tidak ditemukan, game diteruskan dengan state sebelumnya.\n");
                        }
                        
                    }
                }
            }
        }
        else if(CKata2.TabKata2[0] == 'E'){
            if(CKata2.TabKata2[1] == 'X'){
                if(CKata2.TabKata2[2] == 'I'){
                    if(CKata2.TabKata2[3] == 'T'){
                        Credit();
                    }
                }
            }
        }
    }
    else if(CKata2.Length2 == 5){
        if(CKata2.TabKata2[0] == 'O'){
            if(CKata2.TabKata2[1] == 'R'){
                if(CKata2.TabKata2[2] == 'D'){
                    if(CKata2.TabKata2[3] == 'E'){
                        if(CKata2.TabKata2[4] == 'R'){
                            Order(*P);
                        }    
                    }
                }
            }
        }
        else if(CKata2.TabKata2[0] == 'P'){
            if(CKata2.TabKata2[1] == 'L'){
                if(CKata2.TabKata2[2] == 'A'){
                    if(CKata2.TabKata2[3] == 'C'){
                        if(CKata2.TabKata2[4] == 'E'){
                            Place(*P);
                        }    
                    }
                }
            }
        }
    }
    else if(CKata2.Length2 == 6){
        if(CKata2.TabKata2[0] == 'R'){
            if(CKata2.TabKata2[1] == 'E'){
                if(CKata2.TabKata2[2] == 'C'){
                    if(CKata2.TabKata2[3] == 'I'){
                        if(CKata2.TabKata2[4] == 'P'){
                            if(CKata2.TabKata2[5] == 'E'){
                                Recipe();
                            }
                        }    
                    }
                }
            }
        }
    }
}