#include "Nomal_PriorityQueue.h"

int main()
{
	Node* Popped;

	PriorityQueue* Queue;

	NPQ_CreateQueue(&Queue);

	NPQ_Enqueue(Queue, NPQ_CreateNode(20, "테스트1"));
	NPQ_Enqueue(Queue, NPQ_CreateNode(43, "테스트2"));
	NPQ_Enqueue(Queue, NPQ_CreateNode(10, "테스트3"));
	NPQ_Enqueue(Queue, NPQ_CreateNode(25, "테스트4"));
	NPQ_Enqueue(Queue, NPQ_CreateNode(33, "테스트5"));
	NPQ_Enqueue(Queue, NPQ_CreateNode(22, "테스트6"));
	NPQ_Enqueue(Queue, NPQ_CreateNode(80, "테스트7"));
	NPQ_Enqueue(Queue, NPQ_CreateNode(60, "테스트8"));
	NPQ_Enqueue(Queue, NPQ_CreateNode(3, "테스트9"));
	NPQ_Enqueue(Queue, NPQ_CreateNode(1, "테스트10"));
	NPQ_Enqueue(Queue, NPQ_CreateNode(22, "테스트11"));

	while (NPQ_isEmpty(Queue) == 0)
	{
		Popped = NPQ_Dequeue(Queue);

		printf_s("Dequeue : 우선순위 : %d, 값 : %s \n", Popped->Priority, Popped->Data);

		NPQ_DestoryNode(Popped);



	}

	NPQ_DestroyQueue(Queue);

	return 0;
}