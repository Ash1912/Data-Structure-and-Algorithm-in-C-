#include<stdio.h>
#include<stdlib.h>

typedef struct {
	int front;
	int rear;
	int capacity;
	int *arr;
}cqueue;

cqueue *Q;

void initQueue()
{
	Q = (cqueue*)malloc(sizeof(cqueue));
	printf("Enter the size of the queue: ");
	scanf("%d", &Q->capacity);
	Q->front = Q->rear = -1;
	Q->arr = (int *)malloc(sizeof(int)*Q->capacity);
}

void enQueue()
{
	int item;
	if(Q->front == (Q->rear+1) % Q->capacity)
		printf("Queue Overflow\n");
	else
	{
		printf("Enter the element to be inserted in the queue: ");
		scanf("%d", &item);
		if(Q->front == -1 && Q->rear == -1)
		{
			Q->front = 0;
			Q->rear = 0;
		}
		else
		{
			Q->rear = (Q->rear+1) % Q->capacity;
		}
		Q->arr[Q->rear] = item;
	}	
}

void deQueue()
{
	if(Q->rear == -1 && Q->front == -1)
		printf("Queue Underflow\n");
	else
	{
		printf("Dequeued element: %d\n", Q->arr[Q->front]);
		if(Q->front == Q->rear)
			Q->front = Q->rear = -1;
		else
			Q->front = (Q->front + 1) % Q->capacity;
	}
}

void display()
{
	int i;
	if(Q->front == -1 && Q->rear == -1)
	{
		printf("Queue is empty\n");
		return;
	}
	printf("Queue elements :\n");
	i = Q->front;
	if(Q->front <= Q->rear)
	{
		while(i <= Q->rear)
			printf("%d ",Q->arr[i++]);
	}
	else
	{
		while(i <= Q->capacity - 1)
			printf("%d ",Q->arr[i++]);
		i = 0;
		while(i <= Q->rear)
			printf("%d ",Q->arr[i++]);
	}
	printf("\n");
}

int main()
{
	int choice;
	initQueue();
	while(1)
	{
		printf("1. Enqueue\n");
		printf("2. Dequeue\n");
		printf("3. Display\n");
		printf("4. Quit\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);

		switch(choice)
		{
		case 1 :
			enQueue();
			break;
		case 2 :
			deQueue();
			break;
		case 3:
			display();
			break;
		case 4:
			exit(1);
		default:
			printf("Wrong choice, Try again!!\n");
		}
	}
	return 0;
}
