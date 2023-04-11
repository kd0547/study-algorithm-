#include "Graph.h"
#include "LinkedListStack.h"
#include "Stack_DFS.h"
int main(void)
{
	Graph* graph = CreateGraph();

	Vertex* A = CreateVertex("A");
	Vertex* B = CreateVertex("B");
	Vertex* C = CreateVertex("C");
	Vertex* D = CreateVertex("D");
	Vertex* E = CreateVertex("E");
	Vertex* F = CreateVertex("F");
	Vertex* G = CreateVertex("G");

	LinkedListStack* Stack;
	//LinkedQueue* Queue;
	LLS_CreateStack(&Stack);
	//LQ_CreateQueue(&Queue);

	/* 그래프에 정점을 추가  */
	AddVertex(graph, A);
	AddVertex(graph, B);
	AddVertex(graph, C);
	AddVertex(graph, D);
	AddVertex(graph, E);
	AddVertex(graph, F);
	AddVertex(graph, G);

	/* 정점과 정점을 간선으로 잇기 */
	AddEdge(A, CreateEdge(A, B, 0));
	AddEdge(A, CreateEdge(A, C, 0));


	AddEdge(B, CreateEdge(B, A, 0));
	AddEdge(B, CreateEdge(B, D, 0));
	AddEdge(B, CreateEdge(B, E, 0));

	AddEdge(C, CreateEdge(C, A, 0));
	AddEdge(C, CreateEdge(C, A, 0));

	AddEdge(D, CreateEdge(D, B, 0));
	AddEdge(D, CreateEdge(D, G, 0));

	AddEdge(E, CreateEdge(E, B, 0));
	AddEdge(E, CreateEdge(E, C, 0));
	AddEdge(E, CreateEdge(E, G, 0));

	AddEdge(F, CreateEdge(F, G, 0));
	
	AddEdge(G, CreateEdge(G, D, 0));
	AddEdge(G, CreateEdge(G, E, 0));
	AddEdge(G, CreateEdge(G, F, 0));
	



	/*Stack DFS*/
	Stack_DFS(A, Stack);
	printf_s("\n");
	

	/* 그래프 소멸  */
	DestroyGraph(G);


	return 0;
}
