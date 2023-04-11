
#ifndef GRAPH_H

#define GRAPH_H
//#include "LinkedListStack.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//#include "LinkedQueue.h"

enum VisitMode {Visited, NotVisited};

typedef char* ElementType;

typedef struct tagVertex
{
	ElementType Data;
	int Visited;
	int index;

	struct tagVertex* Next;
	struct tagEdge* AdjacencyList;
} Vertex;

typedef struct tagEdge
{
	int Weight;
	struct tagEdge* next;
	Vertex* From;
	Vertex* Target;
} Edge;

typedef struct tagGraph
{
	Vertex* vertices;
	int VertexCount;
}Graph;

//그래프 생성, 삭제
Graph*	CreateGraph();
void	DestroyGraph(Graph* G);

Vertex*	CreateVertex(ElementType Data);
void	DestroyVertex(Vertex* V);

Edge*	CreateEdge(Vertex* From, Vertex* Target, int Weight);
void	DestroyEdge(Edge* E);

void	AddVertex(Graph* G, Vertex* V);
void	AddEdge(Vertex* V, Edge* E);
void	PrintGraph(Graph* G);






#endif // !GRAPH_H

