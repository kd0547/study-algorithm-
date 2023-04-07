#ifndef NOMAL_PRIORITY_QUEUE_H
#define NOMAL_PRIORITY_QUEUE_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <memory.h>

typedef struct tagNode
{
	char* Data;
	int Priority; //우선순위 

	struct tagNode* NextNode;

} Node;

typedef struct tagQueue
{
	Node* Front;
	Node* Rear;

	int Count;

} PriorityQueue;

void NPQ_CreateQueue(PriorityQueue** Queue);
void NPQ_DestroyQueue(PriorityQueue* Queue);

Node* NPQ_CreateNode(int Priority ,char* newData);
void NPQ_DestoryNode(Node* _Node);

void NPQ_Enqueue(PriorityQueue* Queue, Node* NewNode);
Node* NPQ_Dequeue(PriorityQueue* Queue);

int NPQ_isEmpty(PriorityQueue* Queue);

void NPQ_PrintQueue(PriorityQueue* Queue);

#endif // !NOMAL_PRIORITY_QUEUE_H
