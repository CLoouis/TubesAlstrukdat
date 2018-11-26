#ifndef graph_H
#define graph_H

#include "../ADT_Lain/boolean.h"

#define Nil NULL

typedef struct {
	int X;
	int Y;
	int Z;
} Pintu;

typedef struct tNode *adrNode;
typedef struct tSuccNode *adrSuccNode;
typedef struct tNode { 
	Pintu Id;
	adrSuccNode Trail;
	adrNode NextNode;
} Node;
typedef struct tSuccNode {
	adrNode Succ;
	adrSuccNode NextSuccNode;
} SuccNode;

typedef struct {
	adrNode First;
} Graph;

/* Definisi list : */
/* List kosong : First(L) = Nil */
/* Setiap elemen dengan address P dapat diacu Info(P), Next(P) */
/* Elemen terakhir list : jika addressnya Last, maka Next(Last)=Nil */
#define First(G) (G).First
#define Id(Pn) (Pn)->Id
#define Trail(Pn) (Pn)->Trail
#define NextNode(Pn) (Pn)->NextNode

#define Succ(Pt) (Pt)->Succ 
#define NextSuccNode(Pt) (Pt)->NextSuccNode

void CreateGraph (Graph *G);
//Create Empty yang ada pada graph

adrNode AlokNode(Pintu A);

void DealokNode(adrNode P);

adrSuccNode AlokSuccNode(adrNode P);

void DealokSuccNode(adrSuccNode P);

adrNode SearchNode(Graph G, Pintu X);

void InsertNode(Graph *G, Pintu A, adrNode *Pn);

void InsertEdge(Graph *G, Pintu prec, Pintu succ);
#endif