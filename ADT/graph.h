#ifndef graph_H
#define graph_H

#include "boolean.h"
#include "tipebentukan.h"

#define Nil NULL



void CreateGraph (Graph *G);
//Create Empty yang ada pada graph

adrNode AlokNodeGraph(Pintu A);

void DeAlokNodeGraph(adrNode P);

adrSuccNode AlokSuccNode(adrNode P);

void DealokSuccNode(adrSuccNode P);

adrNode SearchNode(Graph G, Pintu X);

void InsertNodeGraph(Graph *G, Pintu A, adrNode *Pn);

void InsertEdge(Graph *G, Pintu prec, Pintu succ);
#endif