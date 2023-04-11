#include "LinkedList.h"


Node* SLL_CreateNode(Vertex* NewData)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));
	NewNode->Data = NewData;
	NewNode->NextNode = NULL;

	return NewNode;
}

void SLL_DestroyNode(Node* Node)
{
	free(Node);
}

void SLL_AppendNode(Node** Head, Node* NewNode)
{
	if ((*Head) == NULL)
	{
		*Head = NewNode;
	}
	else
	{
		Node* Tail = (*Head);

		while (Tail->NextNode != NULL)
		{
			Tail = Tail->NextNode;
		}
		Tail->NextNode = NewNode;
	}
}

void SLL_InsertAfter(Node* Current, Node* NewNode)
{
	NewNode->NextNode = Current->NextNode;
	Current->NextNode = NewNode;

}

void SLL_InsertNewHead(Node** Head, Node* NewNode)
{

	if ((*Head) == NULL)
	{
		(*Head) = NewNode;
	}
	else
	{
		NewNode->NextNode = (*Head);
		(*Head) = NewNode;
	}
}

void SLL_RemoveNode(Node** Head, Node* Remove)
{
	if ((*Head) == remove)
	{
		(*Head) = (*Head)->NextNode;
	}
	else
	{
		Node* Current = (*Head);
		while (Current != NULL && Current->NextNode != Remove)
		{
			Current = Current->NextNode;
		}

		if (Current != NULL)
		{
			Current->NextNode = Remove->NextNode;
		}
	}
}

Node* SLL_GetNodeAt(Node* Head, int Location)
{
	Node* Current = Head;

	while (Current != NULL && (--Location) > 0)
	{
		Current = Current->NextNode;
	}

	return Current;
}

int SLL_GetNodeCount(Node* Head)
{
	int Count = 0;
	Node* Current = Head;

	while (Current != NULL)
	{
		Current = Current->NextNode;
		Count++;
	}

	return Count;
}
