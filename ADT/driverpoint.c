#include "../ADT/point.h"
#include "../ADT/boolean.h"
#include <stdio.h>

int main(){
	POINT point1,point2;
	int a,b;
	
	//MakePOINT
	printf("Masukkan point 1\n");
	scanf("%d %d",&a,&b);
	point1 = MakePOINT(a,b);
	
	//BacaPOINT
	printf("Masukkan point 2\n");
	BacaPOINT(&point2);
	
	//TulisPOINT
    printf("Point 1 dan Point 2 bernilai ");
    TulisPOINT(point1);
    printf(" dan ");
    TulisPOINT(point2);
    
    //Panjang
    printf("\nPoint 1 dan Point 2 berjarak %d",Panjang(point1,point2));
    
    //EQ dan NEQ
    if(EQ(point1,point2)){
		printf("\nPoint1 dan Point2 bernilai sama\n");
	}
	else if(NEQ(point1, point2)){
		printf("\nPoint1 dan Point 2 bernilai beda\n");
	}
	
	//IsOrigin, IsOnSbX, IsOnSbY, dan Kuadran
	if(IsOrigin(point1)){
		printf("Point1 berada di titik origin");
	}
	else if(IsOnSbX(point1)){
		printf("Point1 berada di sumbu X");
	}
	else if(IsOnSbY(point1)){
		printf("Point1 berada di sumbu Y");
	}
	else {
		printf("Point 1 berada di kuadran %d",Kuadran(point1));
	}
	
	//Jarak0
	printf("\nJarak point1 dengan 0 adalah %d",Jarak0(point1));
	
	//Mirrorof
	printf("\nJika dicerminkan terhadap sumbu Y, maka menjadi ");
	TulisPOINT(MirrorOf(point1, (5<3)));
	
	//NextX dan NextY
	printf("\nJika absis Point1 ditambah 1, maka akan bernilai ");
	TulisPOINT(NextX(point1));
	printf("\nJika ordinat Point1 ditambah 1, maka akan bernilai ");
	TulisPOINT(NextY(point1));
	
	//PlusDelta
	printf("\nMasukkan nilai modifier absis dan ordinat Point1\n");
	scanf("%d %d",&a,&b);
	printf("Nilai point1 jika diubah akan menjadi ");
	TulisPOINT(PlusDelta(point1,a,b));
	
	//Geser
	Geser(&point2, a,b);
	printf("\nNilai point2 setelah digeser menjadi ");
	TulisPOINT(point2);
	
	//GeserKeSbX & GeserKeSbY
	GeserKeSbX(&point2);
	GeserKeSbY(&point2);
	printf("\nNilai point2 setelah digeser ke sumbu x dan y menjadi ");
	TulisPOINT(point2);
	
	//Mirror
	printf("\nNilai point1 setelah di cerminkan dengan sumbu X menjadi ");
	Mirror(&point1, (5>2));
	TulisPOINT(point1);
	
	//Putar
	int c;
	printf("\nMasukkan sudut putar dalam derajat\n");
	scanf("%d",&c);
	
	Putar(&point1, c);
	TulisPOINT(point1);
    return 0;
}
