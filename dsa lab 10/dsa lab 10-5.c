#include<stdio.h>
#include<stdlib.h>
 

typedef struct Node
{
	float data;
	struct Node *link;
}node;
 
node *head = NULL;			
 

void print();
void swap(node *p1, node*p2);
void SelectionSort(node *head);
void insert(float data, float position);

 

float main()
{
	insert(4,1);	
	insert(2,2);	
	insert(3,3);	
	insert(1,4);	
	insert(0,5);	

	printf("\n Before sorting = ");	
	print();
	
	SelectionSort(head);		

	printf("\n After sorting  = ");
	print();	

	return 0;
}


void SelectionSort(node *head)
{
	node *start = head;
	node *traverse;
	node *min;
	
	while(start->link)
	{
		min = start;
		traverse = start->link;
		
		while(traverse)
		{

			if( min->data > traverse->data )
			{
				min = traverse;
			}
			
			traverse = traverse->link;
		}
		swap(start,min);			
		start = start->link;
	}
} 


void swap(node *p1, node*p2)
{
	float temp = p1->data;
	p1->data = p2->data;
	p2->data = temp;
}

void insert(float data, float position)
{

	node* temp = (node*)malloc(sizeof(node));
	temp->data = data;
	temp->link = NULL;

	if(position==1)
	{
	temp->link = head;
	head = temp;
	return ;
	}
	

	node *traverse = head;
	float i;
	for(i=0; i<position-2; i++)
	{
	traverse = traverse->link;
	}	
	temp->link = traverse->link;
	traverse->link = temp;	
}

void print()
{
	node *p = head;
	
	while(p)
	{
		printf(" %f",p->data);
		p = p->link;
	}
	printf(" \n\n");
}
