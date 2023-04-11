#define _CRT_SECURE_NO_WARNINGS
#include "Graph.h"


Graph* CreateGraph()
{
	Graph* graph = (Graph*)malloc(sizeof(Graph));
	graph->vertices = NULL;
	graph->VertexCount = 0;

	return graph;
}

void DestroyGraph(Graph* G)
{
	while (G->vertices != NULL)
	{
		Vertex* Vertices = G->vertices->Next;
		DestroyVertex(G->vertices);
		G->vertices = Vertices;
	}

	free(G);
}

Vertex* CreateVertex(ElementType Data)
{
	Vertex* V = (Vertex*)malloc(sizeof(Vertex));

	V->Data = (char*)malloc(strlen(Data) + 1);
	strcpy(V->Data, Data);
	
	//V->Data = Data;

	V->Next = NULL;
	V->AdjacencyList = NULL;
	V->Visited = NotVisited;
	V->index = -1;

	return V;
}

void DestroyVertex(Vertex* V)
{
	while (V->AdjacencyList != NULL)
	{
		Edge* Edge = V->AdjacencyList->next;

		DestroyEdge(V->AdjacencyList);

		V->AdjacencyList = Edge;
	}
}

Edge* CreateEdge(Vertex* From, Vertex* Target, int Weight)
{
	Edge* E = (Edge*)malloc(sizeof(Edge));
	E->From = From;
	E->Target = Target;
	E->next = NULL;
	E->Weight = Weight;


	return E;
}

void DestroyEdge(Edge* E)
{
	free(E);
}

void AddVertex(Graph* G, Vertex* V)
{
	Vertex* VertexList = G->vertices;

	if (VertexList == NULL) 
	{
		G->vertices = V;
	}
	else 
	{
		while (VertexList->Next != NULL)
		{
			VertexList = VertexList->Next;
		}
		VertexList->Next = V;
	}
}

void AddEdge(Vertex* V, Edge* E)
{
	if (V->AdjacencyList == NULL) 
	{
		V->AdjacencyList = E;
	}
	else 
	{
		Edge* AdjacencyList = V->AdjacencyList;

		while (AdjacencyList->next != NULL)
		{
			AdjacencyList = AdjacencyList->next;
		}

		AdjacencyList->next = E;
	}
}

void PrintGraph(Graph* G)
{
	Vertex* V = NULL;
	Edge* E = NULL;


	if ((V = G->vertices) == NULL)
		return;

	while (V != NULL)
	{
		printf_s("%c : ", V->Data);

		if ((E = V->AdjacencyList) == NULL) {
			V = V->Next;
			printf_s("\n");
			continue;
		}

		while (E != NULL)
		{
			printf_s("%c[%d] ", E->Target->Data, E->Weight);
			E = E->next;
		}

		printf_s("\n");

		V = V->Next;
	}
	printf_s("\n");
}

void DFS(Vertex* V)
{
	Edge* E = NULL;

	printf_s("%d ", V->Data);

	V->Visited = Visited;// �湮�� ������ "�湮����" �̶�� ǥ���Ѵ�.

	E = V->AdjacencyList;

	while (E != NULL) // ���� ������ ��� ���� ������ ���� DFS()�� ��������� ȣ���Ѵ�.
	{
		if (E->Target != NULL && E->Target->Visited == NotVisited)
		{
			DFS(E->Target); // ���� ������ �������� �� ���� �켱 Ž���� �����Ѵ�. 
		}
	}

}
/*
void BFS(Vertex* V, LinkedQueue* Queue)
{
	Edge* E = NULL;

	printf_s("%d ", V->Data);
	V->Visited = Visited;

	LQ_Enqueue(&Queue, LQ_CreateNode(V)); //���� ������ ť�� ����

	while (!LQ_isEmpty(Queue))
	{
		Node* Popped = LQ_Dequeue(&Queue);
		V = Popped->Data;

		E = V->AdjacencyList;

		while (E != NULL) /* ���� ������ �ִ��� �˻�  
		{
			V = E->Target;
			if (V != NULL && V->Visited == NotVisited) /*
			{
				printf_s("%d ", V->Data);
				V->Visited = Visited;
				LQ_Enqueue(&Queue, LQ_CreateNode(V));
			}

			E = E->next;
		}
	}


}
*/
void Prim(Graph* G, Vertex* StartVertex, Graph* MST)
{
	int i = 0;


}
