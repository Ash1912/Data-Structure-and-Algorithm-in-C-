#include <stdio.h>
#include <stdlib.h>
typedef struct BT
{
    int data;
    struct BT *left, *right;
} BT;
void insertBT(BT **root, int data)
{
    BT *newBT = (BT *)malloc(sizeof(BT));
    newBT->data = data;
    newBT->left = newBT->right = NULL;
    if (!(*root))
        *root = newBT;
    else
    {
                BT *prev = NULL, *tmp = *root;
        while (tmp)
        {
            prev = tmp;
            if (tmp->data > data)
                tmp = tmp->left;
            else if (tmp->data < data)
                tmp = tmp->right;
        }
        if (prev->data > data)
            prev->left = newBT;
        else
            prev->right = newBT;
    }
}
void createBT(BT **r)
{
    int ch = 1;
do
    {
        int data = 0;
        printf("\nEnter a number to enter in BT: ");
        scanf("%d", &data);
        insertBT(r, data);
        printf("\nPress 1 to enter a value to BT or 0 to exit: ");
        scanf("%d", &ch);
    } while (ch == 1);
}
int countLeaf(BT *r)
{
    if (r == NULL)
        return 0;
    if (r->left == NULL && r->right == NULL)
        return 1;
    return countLeaf(r->left) + countLeaf(r->right);
}
int countNonLeafNodes(BT *r)
{
    return countNodes(r) - countLeaf(r);
}
int countNodes(BT *r)
{
    if (!r)
        return 0;
    return countNodes(r->left) + countNodes(r->right) + 1;
}
int sumOfNodes(BT *r)
{
    if (!r)
        return 0;
    return r->data + sumOfNodes(r->right) + sumOfNodes(r->left);
}
void findSmallest(BT *r)
{
    if (r == NULL)
        printf("\nBT EMPTY!\n");
    else
     {
        BT *tmp = r;
        while (tmp->left)
            tmp = tmp->left;
        printf("\nSmallest element in BT = %d\n", tmp->data);
    }
}
 
void findLargest(BT *r)
{
    if (r == NULL)
        printf("\nBT EMPTY!\n");
    else
    {
        BT *tmp = r;
        while (tmp->right)
            tmp = tmp->right;
             printf("\nLargest element in BT = %d\n", tmp->data);
    }
}
int maxDepth(BT *r)
{
    if (!r)
        return 0;
    else
    {
        int ldep = maxDepth(r->left);
        int rdep = maxDepth(r->right);
        if (ldep > rdep)
            return ldep + 1;
        else
            return rdep + 1;
    }
}
int main()
{
    BT *r = NULL;
    while (1)
    {
        int ch;
        printf(
               "\tBinary Tree Menu\n"
               "----------------------------------------\n"
               "0.Quit\n"
               "1.Create\n"
               "2.To count number of leaf nodes\n"
               "3.To count number of non-leaf nodes\n"
               "4. To find total number of nodes\n"
               "5. To compute height of the binary tree\n"
               "6. To find sum of all nodes\n"
               "7. To find the minimum element\n"
               "8. To find the maximum element\n"
               "----------------------------------------\n"
               "Enter your choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 0:
            return 0;
            break;
        case 1:
            createBT(&r);
            break;
        case 2:
            printf("\nNumber of leaf nodes = %d\n", countLeaf(r));
            break;
        case 3:
            printf("\nNumber of non-leaf nodes = %d\n", countNonLeafNodes(r));
            break;
        case 4:
            printf("\nTotal Number of nodes = %d\n", countNodes(r));
            break;
        case 5:
            printf("\nDepth of BT = %d\n", maxDepth(r));
            break;
        case 6:
            printf("\nSum of data of all nodes = %d\n", sumOfNodes(r));
            break;
        case 7:
            findSmallest(r);
            break;
        case 8:
            findLargest(r);
            break;
        default:
            printf("\nEnter a choice!\n");
                  break;
        }
    }
    return 0;
}

