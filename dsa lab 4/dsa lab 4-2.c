#include <stdio.h>
#include <stdlib.h>
 
struct node
{
    int val;
    struct node *next;
    struct node *prev;    
};
typedef struct node n;
 
n* create_node(int);
void add_node();
void insert_at_first();
void insert_at_end();
void insert_at_position();
void delete_node_position();
void search();
void display_from_beg();
void display_in_backward();
int getListLength(n *first);
 
n *new, *ptr, *prev;
n *first = NULL, *last = NULL;
int number = 0;
 
void main()
{
    int ch;
 
    printf("\n-----Circular Doubly Linked List-----\n");
    printf("\n1.Insert at beginning \n2.Insert at end \n3.Insert at position \n4.Delete node at position \n5.Search element \n6.Display list from beginning \n7.Display list from end \n8.Count number of nodes \n9.Exit ");
    printf("\n------------------------------\n");
    while (1)
    {
 
        printf("\n Enter your choice :");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1 :
            insert_at_first();
            break;
        case 2 :
            insert_at_end();
            break;
        case 3 :
            insert_at_position();
            break;
        case 4 :
            delete_node_position();
            break;
        case 5 :
            search();
            break;
        case 6 :
            display_from_beg();
            break;
        case 7 :
            display_in_backward();
            break;
        case 8:
            getListLength(first);
            break;
        case 9 :
            exit(0);
        case 10 :
            add_node();
            break;
        default:
            printf("\ninvalid choice");                
        }
    }
}
/*
 *MEMORY ALLOCATED FOR NODE DYNAMICALLY
 */
n* create_node(int info)
{
    number++;
    new = (n *)malloc(sizeof(n));
    new->val = info;
    new->next = NULL;
    new->prev = NULL;
    return new;
}
/*
 *ADDS NEW NODE
 */
void add_node()
{
 
    int info;
 
    printf("\nEnter the value you would like to add:");
    scanf("%d", &info);
    new = create_node(info);
 
    if (first == last && first == NULL)
    {
 
        first = last = new;
        first->next = last->next = NULL;
        first->prev = last->prev = NULL;
    }
    else
    {
        last->next = new;
        new->prev = last;
        last = new;
        last->next = first;
        first->prev = last;
    }
}
/*
 *INSERTS ELEMENT AT FIRST
 */
void insert_at_first()
{
 
    int info;
 
    printf("\nEnter the value to be inserted at first :");
    scanf("%d",&info);
    new = create_node(info);
 
    if (first == last && first == NULL)
    {    
        printf("\nInitially it is empty linked list later insertion is done");
        first = last = new;
        first->next = last->next = NULL;
        first->prev = last->prev = NULL;
    }
    else
    {
        new->next = first;
        first->prev = new;
        first = new;
        first->prev = last;
        last->next = first;
        printf("\n The value is inserted at beginning");
    }
}
/*
 *INSERTS ELEMNET AT END
 */
void insert_at_end()
{
 
    int info;    
 
    printf("\nEnter the value that has to be inserted at last :");
    scanf("%d", &info);
    new = create_node(info);
 
    if (first == last && first == NULL)
    {
        printf("\nInitially the list is empty and now new node is inserted but at first");
        first = last = new;
        first->next = last->next = NULL;    
        first->prev = last->prev = NULL;
    }
    else
    {
        last->next = new;
        new->prev = last;
        last = new;
        first->prev = last;
        last->next = first;
    }
}
/*
 *INSERTS THE ELEMENT AT GIVEN POSITION
 */
void insert_at_position()
{    
    int info, pos, len = 0, i;
    n *prevnode;
 
    printf("\n Enter the value that you would like to insert :");
    scanf("%d", &info);
    printf("\n Enter the position where you have to enter :");
    scanf("%d", &pos);
    new = create_node(info);
 
    if (first == last && first == NULL)
    {
        if (pos == 1)
        {
            first = last = new;
            first->next = last->next = NULL;    
            first->prev = last->prev = NULL;
        }
        else
            printf("\n Empty linked list you cant insert at that particular position");
    }
    else
    {
        if (number < pos)
            printf("\n Node cant be inserted as position is exceeding the linked list length");
 
        else
        {
            for (ptr = first, i = 1;i <= number;i++)
            {
                prevnode = ptr;
                ptr = ptr->next;
                if (i == pos-1)
                {
                    prevnode->next = new;
                    new->prev = prevnode;
                    new->next = ptr;
                    ptr->prev = new;
                    printf("\nInserted at position %d succesfully", pos);
                    break;
                }
            }
        }
    }
}
/*
 *DELETION IS DONE
 */
void delete_node_position()
{    
    int pos, count = 0, i;
    n *temp, *prevnode;
 
    printf("\n Enter the position which u wanted to delete :");
    scanf("%d", &pos);
 
    if (first == last && first == NULL)
        printf("\n Empty linked list you cant delete");
 
    else
    {
        if (number < pos)
            printf("\n Node cant be deleted at position as it is exceeding the linked list length");
 
        else
        {
            for (ptr = first,i = 1;i <= number;i++)
            {
                prevnode = ptr;
                ptr = ptr->next;
                if (pos == 1)
                {    
                    number--;
                    last->next = prevnode->next;
                    ptr->prev = prevnode->prev;
                    first = ptr;
                    printf("%d is deleted", prevnode->val);
                    free(prevnode);
                    break;        
                }
                else if (i == pos - 1)
                {    
                    number--;
                    prevnode->next = ptr->next;
                    ptr->next->prev = prevnode;
                    printf("%d is deleted", ptr->val);
                    free(ptr);
                    break;
                }
            }
        }
    }
}
/*
 *SEARCHING USING SINGLE KEY
 */
void search()
{
    int count = 0, key, i, f = 0;
 
    printf("\nEnter the value to be searched:");
    scanf("%d", &key);
 
    if (first == last && first == NULL)
        printf("\nList is empty no elemnets in list to search");
    else
    {
        for (ptr = first,i = 0;i < number;i++,ptr = ptr->next)
        {
            count++;
            if (ptr->val == key)
            {
                printf("\n The value is found at position at %d", count);
                f = 1;
            }    
        }
        if (f == 0)
            printf("\n The value is not found in linked list");
    }
}
/*
 *DISPLAYING IN BEGINNING
 */
void display_from_beg()
{
    int i;
    if (first == last && first == NULL)
        printf("\nList is empty no elemnts to print");
    else
    {    
        printf("\n Element in Nodes are : ", number);
        for (ptr = first, i = 0;i < number;i++,ptr = ptr->next)
            printf("%2d", ptr->val);
    }
}
/*
 * DISPLAYING IN BACKWARD
 */
void display_in_backward()
{
    int i;        
    if (first == last && first == NULL)
        printf("\nList is empty there are no elments: ");
    else
    {
        printf("\n Element in Nodes are : ", number);
        for (ptr = last, i = 0;i < number;i++,ptr = ptr->prev)
        {
            printf("%2d", ptr->val);
        }
    }
}
int getListLength(n* first)
{
    n* temp=first;
    int count = 0;

    if(first != NULL)
    do
    {
        count++;
        temp = temp->next;
    }   while(temp != first);

    printf("The total number of nodes : %d",count);
}
