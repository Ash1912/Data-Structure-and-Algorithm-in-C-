
#include <stdio.h>
#include <stdlib.h>

typedef struct polynomial
{
    int coef;
    int expo;
    struct polynomial *next;
} poly;

poly *create_poly(poly *);
poly *insert_poly_node(poly *, int, int);
poly *add_poly(poly *, poly *);
void show_poly(poly *);

int main()
{
    int choice;
    do
    {
        poly *poly1, *poly2, *poly3, *poly4;

        poly1 = NULL;
        poly2 = NULL;
        poly3 = NULL;

        printf("\nCreate 1st expression\n");
        poly1 = create_poly(poly1);
        printf("\nDisplay the 1st expression:\n");
        show_poly(poly1);

        printf("\nCreate 2nd expression\n");
        poly2 = create_poly(poly2);
        printf("\nDisplay the 2nd expression:\n");
        show_poly(poly2);

        printf("\nCreate 3rd expression\n");
        poly3 = create_poly(poly3);
        printf("\nDisplay the 3rd expression:\n");
        show_poly(poly3);

        poly4 = add_poly((add_poly(poly1, poly2)), poly3);
        printf("\nAdditon of three polynomial is:\n");
        show_poly(poly4);

        printf("\nDo you want to add three more polynomials?\n");
        printf("Enter 1 for Yes, 0 for No: ");
        scanf("%d", &choice);
    } while (choice);
    return 0;
}

poly *create_poly(poly *start)
{
    int i, n, ex, co;
    printf("How many terms u want to enter : ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        printf("Enter coeficient for term %d : ", i);
        scanf("%d", &co);
        printf("Enter exponent for term %d : ", i);
        scanf("%d", &ex);
        start = insert_poly_node(start, co, ex);
    }
    return (start);
} 

poly *insert_poly_node(poly *start, int co, int ex)
{
    poly *ptr, *tmp;
    tmp = (poly *)malloc(sizeof(poly));
    tmp->coef = co;
    tmp->expo = ex;
    tmp->next = NULL;

    if (start == NULL)
        start = tmp;
    else
    {
        ptr = start;
        while (ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = tmp;
    }
    return (start);
} 

poly *add_poly(poly *p1, poly *p2)
{
    poly *p3 = NULL;
    if (p1 == NULL && p2 == NULL)
        return p3;

    while (p1 != NULL && p2 != NULL)
    {
        if (p1->expo > p2->expo)
        {
            p3 = insert_poly_node(p3, p1->coef, p1->expo);
            p1 = p1->next;
        }
        else if (p2->expo > p1->expo)
        {
            p3 = insert_poly_node(p3, p2->coef, p2->expo);
            p2 = p2->next;
        }
        else 
        {
            p3 = insert_poly_node(p3, p1->coef + p2->coef, p1->expo);
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    
    while (p1 != NULL)
    {
        p3 = insert_poly_node(p3, p1->coef, p1->expo);
        p1 = p1->next;
    }
    while (p2 != NULL)
    {
        p3 = insert_poly_node(p3, p2->coef, p2->expo);
        p2 = p2->next;
    }
    return p3;
}

void show_poly(poly *ptr)
{
    if (ptr == NULL)
    {
        printf("Empty\n");
        return;
    }
    while (ptr->next != NULL)
    {
        printf("(%dx^%d) + ", ptr->coef, ptr->expo);
        ptr = ptr->next;
    }
    printf("(%dx^%d)", ptr->coef, ptr->expo);
    printf("\n");
}
