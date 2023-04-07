#include "Nomal_PriorityQueue.h"

int main()
{
	Node* Popped;

	PriorityQueue* Queue;

	NPQ_CreateQueue(&Queue);

	NPQ_Enqueue(Queue, NPQ_CreateNode(20, "�׽�Ʈ1"));
	NPQ_Enqueue(Queue, NPQ_CreateNode(43, "�׽�Ʈ2"));
	NPQ_Enqueue(Queue, NPQ_CreateNode(10, "�׽�Ʈ3"));
	NPQ_Enqueue(Queue, NPQ_CreateNode(25, "�׽�Ʈ4"));
	NPQ_Enqueue(Queue, NPQ_CreateNode(33, "�׽�Ʈ5"));
	NPQ_Enqueue(Queue, NPQ_CreateNode(22, "�׽�Ʈ6"));
	NPQ_Enqueue(Queue, NPQ_CreateNode(80, "�׽�Ʈ7"));
	NPQ_Enqueue(Queue, NPQ_CreateNode(60, "�׽�Ʈ8"));
	NPQ_Enqueue(Queue, NPQ_CreateNode(3, "�׽�Ʈ9"));
	NPQ_Enqueue(Queue, NPQ_CreateNode(1, "�׽�Ʈ10"));
	NPQ_Enqueue(Queue, NPQ_CreateNode(22, "�׽�Ʈ11"));

	while (NPQ_isEmpty(Queue) == 0)
	{
		Popped = NPQ_Dequeue(Queue);

		printf_s("Dequeue : �켱���� : %d, �� : %s \n", Popped->Priority, Popped->Data);

		NPQ_DestoryNode(Popped);



	}

	NPQ_DestroyQueue(Queue);

	return 0;
}