#include "Stack_DFS.h"

void Stack_DFS(Vertex* V, LinkedListStack* Stack)
{
	Edge* E = NULL;
	printf_s("%s ", V->Data);

	V->Visited = Visited;// 방문한 정점에 "방문했음" 이라고 표시한다.

	LLS_Push(Stack, LLS_CreateNode(V));
	//LLS_PrintStack(Stack);

	E = V->AdjacencyList;
	V = E->Target;
	
	while (!LLS_IsEmpty(Stack))
	{
	
		while (E != NULL)
		{
			if (E->Target != NULL && E->Target->Visited == NotVisited)
			{
				V = E->Target;

				V->Visited = Visited;
				
				LLS_Push(Stack, LLS_CreateNode(V));
				printf_s("%s ", V->Data);
				//LLS_PrintStack(Stack);

				E = V->AdjacencyList;
				
			}

			
			E = E->next;
		}

		Node* Poped = LLS_Pop(Stack);
		Vertex* V = Poped->Data;
		E = V->AdjacencyList;
		V = E->Target;
		
		
	}
}
