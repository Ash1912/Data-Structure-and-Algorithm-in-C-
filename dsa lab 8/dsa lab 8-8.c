#include<stdio.h>
#define MAX 10

int top1=-1;
int top2=MAX; 
int stack[MAX];

void push1(int n)
{
    if((top1+1)==top2 || top1==MAX-1 )
    {
        printf("Stack overflow!\n");
        return ;
    }
    top1++;
    stack[top1]=n;
}

void push2(int n)
{
   if((top1+1)==top2  || top2==0)
    {
        printf("Stack overflow!\n");
        return ;
    }
    top2--;
    stack[top2]=n; 
}

void pop1()
{
    if(top1==-1)
    {
        printf("Stack underflow\n");
        return ;
    }
    int n=stack[top1];
    printf("The element popped is %d",n);
    top1--;
}

void pop2()
{
    if(top2==MAX+1)
    {
        printf("Stack underflow\n");
        return ;
    }
    int n=stack[top2];
    printf("The element popped is %d",n);
    top2++;
}

void disp_arr()
{
    int i;
    printf("\nDisplaying Array\n");
    for(i=0;i<MAX;i++)
    printf("%d ",stack[i]);
}

void disp_stack1()
{
    int i;
    printf("\nDisplaying Stack 1\n");
    for(i=top1;i>=0;i--)
    printf("%d ",stack[i]);
}

void disp_stack2()
{
    int i;
    printf("\nDisplaying Stack 2\n");
    for(i=top2;i<MAX;i++)
    printf("%d ",stack[i]);
}

int main()
{
    int choice,ct=1,c,ele;
    while(ct)
    {

        printf("\nDo you wish to continue ?(1 for yes, 0 for no):  \n");
        scanf("%d",&ct);
        printf("Enter the stack you want to deal with:\n1 for stack 1\n2 for stack 2 \n3 to print array\n4 to display stack 1\n5 to display stack 2\n");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1: 
            {
                printf("\nPush(1) or pop(2) ? :  \n");
                scanf("%d",&c);
                if(c==1)
                {
                    printf("\nEnter the element you want to push: \n");
                    scanf("%d",&ele);
                    push1(ele);
                }
                if(c==2)
                {
                    pop1();
                }
            }
            break;

            case 2:
            {
                printf("Push(1) or pop(2) ? :  \n");
                scanf("%d",&c);
                if(c==1)
                {
                    printf("\nEnter the element you want to push: \n");
                    scanf("%d",&ele);
                    push2(ele);
                }
                if(c==2)
                {
                    pop2();
                }
            }
            break;

            case 3:
                disp_arr();
            break;

            case 4:
                disp_stack1();
            break;

            case 5:
                disp_stack2();
            break;
        }
    }
    return 0;
}
