

#ifndef LINKEDLIST_STACK_H
#define LINKEDLIST_STACK_H
#include "Graph.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct tagNode
{
	Vertex* Data;
	struct tagNode* NextNode;

}Node;

typedef struct tagLinkedListStack
{
	Node* List;
	Node* Top;

}LinkedListStack;

void LLS_CreateStack(LinkedListStack** Stack);
void LLS_DestroyStack(LinkedListStack* Stack);

Node* LLS_CreateNode(Vertex* Data);
void LLS_DestroyNode(Node* _Node);

void LLS_Push(LinkedListStack* Stack, Node* NewNode);
Node* LLS_Pop(LinkedListStack* Stack);

Node* LLS_Top(LinkedListStack* Stack);
int LLS_Size(LinkedListStack* Stack);
int LLS_IsEmpty(LinkedListStack* Stack);

void LLS_PrintStack(LinkedListStack* Stack);


#endif // !LINKEDLIST_STACK_H
