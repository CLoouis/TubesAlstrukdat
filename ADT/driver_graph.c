#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "graph.h"

int main(){
	Graph G;
	Pintu Pintu1,Pintu2,Pintu3,Pintu4,Pintu5,Pintu6,Pintu7,Pintu8;
	adrNode P1,P2,P3,P4,P5,P6,P7,P8;
	printf("cek1\n");
	CreateGraph(&G);
	printf("cek2\n");
	Pintu1.X = 1;
	Pintu1.Y = 5;
	Pintu1.Z = 8;

	Pintu2.X = 2;
	Pintu2.Y = 2;
	Pintu2.Z = 1;

	Pintu3.X = 2;
	Pintu3.Y = 8;
	Pintu3.Z = 5;

	Pintu4.X = 3;
	Pintu4.Y = 1;
	Pintu4.Z = 5;

	Pintu5.X = 3;
	Pintu5.Y = 2;
	Pintu5.Z = 1;

	Pintu6.X = 4;
	Pintu6.Y = 5;
	Pintu6.Z = 8;

	Pintu7.X = 4;
	Pintu7.Y = 1;
	Pintu7.Z = 5;

	Pintu8.X = 8;
	Pintu8.Y = 8;
	Pintu8.Z = 5;
	printf("cek3\n");
	InsertNode(&G,Pintu1,&P1);
	InsertNode(&G,Pintu2,&P2);
	InsertNode(&G,Pintu3,&P3);
	InsertNode(&G,Pintu4,&P4);
	InsertNode(&G,Pintu5,&P5);
	InsertNode(&G,Pintu6,&P6);
	InsertNode(&G,Pintu7,&P7);
	InsertNode(&G,Pintu8,&P8);
	printf("cek4\n");
	InsertEdge(&G,Pintu1,Pintu2);
	InsertEdge(&G,Pintu2,Pintu1);
	InsertEdge(&G,Pintu3,Pintu4);
	InsertEdge(&G,Pintu4,Pintu3);

	InsertEdge(&G,Pintu5,Pintu6);
	InsertEdge(&G,Pintu6,Pintu5);
	InsertEdge(&G,Pintu7,Pintu8);
	InsertEdge(&G,Pintu8,Pintu7);
	printf("cek5\n");

	return 0;
}