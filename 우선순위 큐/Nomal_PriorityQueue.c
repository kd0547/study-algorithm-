#define _CRT_SECURE_NO_WARNINGS
#include "Nomal_PriorityQueue.h"


void NPQ_CreateQueue(PriorityQueue** Queue)
{
    (*Queue)  = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    (*Queue)->Front = NULL;
    (*Queue)->Rear = NULL;
    (*Queue)->Count = 0;
}

void NPQ_DestroyQueue(PriorityQueue* Queue)
{
    while (!NPQ_isEmpty(Queue))
    {
        Node* Popped = NPQ_Dequeue(&Queue);

        NPQ_DestoryNode(Popped);
    }
    free(Queue);
}

Node* NPQ_CreateNode(int Priority, char* newData)
{
    Node* _node = (Node*)malloc(sizeof(Node));
    _node->Data = (char*)malloc(strlen(newData) + 1);
    strcpy(_node->Data, newData);

    _node->Priority = Priority;


    _node->NextNode = NULL;



    return _node;
}

void NPQ_DestoryNode(Node* _Node)
{
    free(_Node->Data);
    free(_Node);
}

void NPQ_Enqueue(PriorityQueue* Queue, Node* NewNode)
{
    if (Queue->Front == NULL)
    {
        Queue->Front = NewNode;
        Queue->Rear = NewNode;
        Queue->Count++;
    }
    else
    {
        

        
        Node* FrontNode = Queue->Front;
        
        
        if (NewNode->Priority < FrontNode->Priority) {
            Node* Temp = FrontNode;

            Queue->Front = NewNode;
            NewNode->NextNode = Temp;

            Queue->Count++;
            
            return;
        }

        Node* RearNode = Queue->Rear;

        if (NewNode->Priority > RearNode->Priority) {

            RearNode->NextNode = NewNode;
            Queue->Rear = NewNode;

            Queue->Count++;

            return;
        }
        

        Node* PrevNode = Queue->Front;
        Node* CurrentNode = Queue->Front->NextNode;

        while (CurrentNode->NextNode != NULL)
        {
            if (NewNode->Priority < CurrentNode->Priority) 
            {

                PrevNode->NextNode = NewNode;
                NewNode->NextNode = CurrentNode;

                Queue->Count++;

                return;
            }
            PrevNode = CurrentNode;
            CurrentNode = CurrentNode->NextNode;
        }

        if (CurrentNode->NextNode == NULL) {
            if (NewNode->Priority < CurrentNode->Priority)
            {

                PrevNode->NextNode = NewNode;
                NewNode->NextNode = CurrentNode;
            }
        }



        Queue->Count++;
        return;
    }
}

Node* NPQ_Dequeue(PriorityQueue* Queue)
{
    Node* Front = Queue->Front;
    
    if (Queue->Front->NextNode == NULL)
    {
        Queue->Front = NULL;
        Queue->Rear = NULL;
        Queue->Count--;

    }
    else
    {
        Queue->Front = Queue->Front->NextNode;
    }


    return Front;
}

int NPQ_isEmpty(PriorityQueue* Queue)
{
    return (Queue->Front == NULL);
}

void NPQ_PrintQueue(PriorityQueue* Queue)
{
    Node* Current = Queue->Front;

    if (Current == NULL)
        return;

    if (Current->NextNode == NULL) 
    {
        printf_s("우선순위[%d] - %s \n", Current->Priority, Current->Data);
    }
    else 
    {
        while (Current->NextNode != NULL)
        {
            printf_s("우선순위[%d] - %s \n", Current->Priority, Current->Data);

            Current = Current->NextNode;
        }
    }


}
