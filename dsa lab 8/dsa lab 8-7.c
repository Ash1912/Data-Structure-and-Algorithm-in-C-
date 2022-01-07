#include<stdio.h>
#include<stdlib.h>

int f = -1,r = -1;
int q[50];
void enqueue(int data,int l)
{
	if(r==l-1){
		printf("Queue is full");
	}
	else if((f==-1)&&(r==-1)){
		f = r = 0;
		q[r] = data;
	}
	else
	{
		r++;
		q[r] = data;	
	}
}
void deque()
{
    printf("%d\n",q[f]);
    f++;
}
void print()
{
	int i;
	for(i=f;i<=r;i++)
	{
		printf("\n%d",q[i]);
	}
}
void reverse()
{
	int i,j,t;
	for(i=f,j=r;i<j;i++,j--){
		t = q[i];
		q[i] = q[j];
		q[j] = t;
	}
}
void push(int x)
{
    enqueue(x, 50);
}
void pop(){
    reverse();
    deque();
    reverse();
}
int main()
{
    push(10);
    push(20);
	push(30);
    pop();
    push(40);
    pop();
    pop();
    return 0;
}
