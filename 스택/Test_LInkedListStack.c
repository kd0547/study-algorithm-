#include "LinkedListStack.h"


int main()
{
	int i = 0;
	int Count = 0;
	Node* Poped = NULL;

	LinkedListStack* Stack;

	LLS_CreateStack(&Stack);

	LLS_Push(Stack, LLS_CreateNode("abc"));
	LLS_Push(Stack, LLS_CreateNode("def"));
	LLS_Push(Stack, LLS_CreateNode("efg"));
	LLS_Push(Stack, LLS_CreateNode("hig"));

	Count = LLS_Size(Stack);

	printf_s("Size: %d, Top: %s \n\n", Count, LLS_Top(Stack)->Data);

	for (int i = 0; i < Count; i++)
	{
		if (LLS_IsEmpty(Stack))
			break;

		Poped = LLS_Pop(Stack);

		printf_s("Poped: %s ", Poped->Data);

		LLS_DestroyNode(Poped);
		
		if (!LLS_IsEmpty(Stack))
		{
			printf_s("Current TOp: %s \n",LLS_Top(Stack)->Data);
		}
		else
		{
			printf_s("Stack Is Empty. \n");
		}

	}
	LLS_CreateStack(Stack);


	return 0;
}