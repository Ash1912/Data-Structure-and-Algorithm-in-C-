#include <stdio.h> 
#include <stdlib.h>

struct employee{
    char name[50];
    char gender;
    char designation[50];
    char department[50]; 
    int basic_pay;
    int gross_pay;
};
int main()
{
    int n,i,j;
    struct employees *ptr;
    printf("Enter the number of employees: \n");
    scanf("%d",&n);
    struct employee e[n];
    ptr=(struct employee*)malloc(n * sizeof(struct employee));
    
    for(i=0;i<n;i++)
    {
        printf("Enter employee %d's name: \n",i+1);
        scanf("%s",&e[i].name);
        printf("Enter employee %d's gender: \n",i+1);
        scanf("%s",&e[i].gender);
        printf("Enter employee %d's designation: \n",i+1);
        scanf("%s",&e[i].designation);
        printf("Enter employee %d's department: \n",i+1);
        scanf("%s",&e[i].department);
        printf("Enter employee %d's basic pay: \n",i+1);
        scanf("%d",&e[i].basic_pay);
    }
    
    for(i=0;i<n;i++)
    e[i].gross_pay = e[i].basic_pay + 0.25*e[i].basic_pay + 0.75*e[i].basic_pay;
    
    for(i=0;i<n;i++)
    {
        printf("Employee %d's name: %s\n",i+1,e[i].name);
        printf("Employee %d's gender: %c\n",i+1,e[i].gender);
        printf("Employee %d's designation: %s\n",i+1,e[i].designation);
        printf("Employee %d's department: %s\n",i+1,e[i].department);
        printf("Employee %d's basic pay: %d\n",i+1,e[i].basic_pay);
        printf("Employee %d's gross pay is : %d\n",i+1,e[i].gross_pay);
        printf("\n");
        
    }
    
    
}
