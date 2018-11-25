#include <stdlib.h>
#include "boolean.h"
#include "graph.h"

void CreateGraph (Graph *G){
	First(*G) = Nil;
}
//Create Empty yang ada pada graph

adrNode AlokNodeGraph(Pintu A){
	adrNode P;
 
    P = (adrNode) malloc (sizeof(NodeGraph));

    if (P != Nil){
        Id(P) = A;
        Trail(P) = Nil;
        NextNode(P) = Nil;
    }
    return P;
}

void DeAlokNodeGraph(adrNode P){
	free(P);
}

adrSuccNode AlokSuccNode(adrNode P){
	adrSuccNode Pn;

	Pn = (adrSuccNode) malloc (sizeof(SuccNode));

	if (Pn != Nil){
		Succ(Pn) = P;
		NextSuccNode(Pn) = Nil; 
	}
	return Pn;
}

void DealokSuccNode(adrSuccNode P){
	free(P);
}

adrNode SearchNode(Graph G, Pintu A){
	adrNode P;
	boolean Found = false;

	P = First(G);
	while (P != Nil && (!Found)){
		if (Id(P).X == A.X && Id(P).Y == A.Y && Id(P).Z == A.Z){
			Found = true;
		} else {
			P = NextNode(P);
		}
	}
	return P;
}

void InsertNodeGraph(Graph *G, Pintu A, adrNode *Pn){
	adrNode P;

	*Pn = AlokNodeGraph(A);
	P = First(*G);
	if (P == Nil){
		First(*G) = *Pn;
	} else {
		while(NextNode(P) != Nil){
			P = NextNode(P);
		}//Next(P) = Nil

		NextNode(P) = *Pn;
	}

}

void InsertEdge(Graph *G, Pintu prec, Pintu succ){
	adrNode Pprec, Psucc;
	adrSuccNode P,Q;

	Pprec = SearchNode(*G,prec);
	Psucc = SearchNode(*G,succ);

	Q = AlokSuccNode(Psucc);
	P = Trail(Pprec);
	if (P == Nil){
		Trail(Pprec) = Q;
	} else {
		while (NextSuccNode(P) != Nil){
			P = NextSuccNode(P);
		}
		NextSuccNode(P) = Q;
	}
}
