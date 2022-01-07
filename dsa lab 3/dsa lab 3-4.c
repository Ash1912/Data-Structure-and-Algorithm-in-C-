#include <stdio.h>
#include <stdlib.h>

struct node {
    int num;
    struct node * nextptr;
}*stnode;
 

void CircularlinkedListcreation(int n);
void displayCircularlinkedList();

int main()
{
    int n;
    stnode = NULL;
	printf("\n\n Circular Linked List : Create and display a circular linked list :\n");
	printf("-----------------------------------------------------------------------\n");	   	

    printf(" Enter the number of nodes : ");
    scanf("%d", &n);
 
    CircularlinkedListcreation(n); 
    displayCircularlinkedList();
    return 0;
}

void CircularlinkedListcreation(int n)
{
    int i, num;
    struct node *preptr, *newnode;

    if(n >= 1)
    {
        stnode = (struct node *)malloc(sizeof(struct node));

        printf(" Entered data for node 1 : ");
        scanf("%d", &num);
        stnode->num = num;
        stnode->nextptr = NULL;
        preptr = stnode;
        for(i=2; i<=n; i++)
        {
            newnode = (struct node *)malloc(sizeof(struct node));
            printf(" Entered data for node %d : ", i);
            scanf("%d", &num);
            newnode->num = num;
            newnode->nextptr = NULL;	
            preptr->nextptr = newnode;	
            preptr = newnode;   		
        }
        preptr->nextptr = stnode; 	
    }
}

void displayCircularlinkedList()
{
    struct node *tmp;
    int n = 1;

    if(stnode == NULL)
    {
        printf(" No data found in the List yet.");
    }
    else
    {
        tmp = stnode;
        printf("\n\n Data entered in the list are :\n");

        do {
            printf(" Data %d = %d\n", n, tmp->num);

            tmp = tmp->nextptr;
            n++;
        }while(tmp != stnode);
    }
}
