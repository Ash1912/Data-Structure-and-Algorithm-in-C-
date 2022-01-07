#include<stdio.h>
#include<stdlib.h>


struct Node
{
	float data;
	struct Node *next;
};


void insertAtTheBegin(struct Node **start_ref, float data);

void bubbleSort(struct Node *start);


void swap(struct Node *a, struct Node *b);


void printList(struct Node *start);

int main()
{
	float arr[] = {1.1, 1.2, 2.3, 1.4, 1.5, 9};
	float list_size;
	int i;

	struct Node *start = NULL;


	for (i = 0; i< 6; i++)
		insertAtTheBegin(&start, arr[i]);


	printf("\nLinked list before sorting : \n");
	printList(start);

	bubbleSort(start);


	printf("\n\nLinked list after sorting : \n");
	printList(start);

	getchar();
	return 0;
}



void insertAtTheBegin(struct Node **start_ref, float data)
{
	struct Node* ptr1 = (struct Node*)malloc(sizeof(struct Node));
	ptr1->data = data;
	ptr1->next = *start_ref;
	*start_ref = ptr1;
}


void printList(struct Node *start)
{
	struct Node *temp = start;
	printf("\n");
	while (temp!=NULL)
	{
		printf("%f ", temp->data);
		temp = temp->next;
	}
}


void bubbleSort(struct Node *start)
{
	float swapped, i;
	struct Node *ptr1;
	struct Node *lptr = NULL;


	if (start == NULL)
		return;

	do
	{
		swapped = 0;
		ptr1 = start;

		while (ptr1->next != lptr)
		{
			if (ptr1->data > ptr1->next->data)
			{
				swap(ptr1, ptr1->next);
				swapped = 1;
			}
			ptr1 = ptr1->next;
		}
		lptr = ptr1;
	}
	while (swapped);
}


void swap(struct Node *a, struct Node *b)
{
	float temp = a->data;
	a->data = b->data;
	b->data = temp;
}
