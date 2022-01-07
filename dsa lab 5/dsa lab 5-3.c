#include<stdio.h>
#include<stdlib.h>
typedef struct tr{
    int row,col,val;
}tr;
int main()
{
    printf("Give row and column of the matrix: ");
    int i,j;
    int a,b;
	scanf("%d %d",&a,&b);
    if(a != b)
    {
        printf("Not possible as not a square matrix!!!!!");
        return 0;
    }
     int** sparse = (int*)malloc(a*sizeof(int));
    for(i=0;i<a;++i)
    {
        sparse[i] = (int*)malloc(a*sizeof(int));
    }
    int n_z = 0;
    printf("Give values:\n");
    for(i=0;i<a;++i)
    {
        for(j=0;j<a;++j)
        {
            scanf("%d",&sparse[i][j]);
            if(sparse[i][j])
            {
                n_z ++;
            }
        }
    }
    tr* tr1;
    tr* tr2;
    tr1 = (tr*)malloc((n_z + 1)*sizeof(tr));
    tr2 = (tr*)malloc((n_z + 1)*sizeof(tr));
    tr1[0].row = tr1[0].col = a;
    tr1[0].val = n_z;
    int k = 1;
    for(i=0;i<a;++i)
    {
        for(j=0;j<a;++j)
        {
            if(sparse[i][j]!=0)
            {
                tr1[k].row = i;tr1[k].col = j;tr1[k].val = sparse[i][j];
                k++;
            }
        }
    }
    free(sparse);
    for(i=0;i<n_z+1;++i)
    {
        tr2[i].row = tr1[i].col;
        tr2[i].col = tr1[i].row;
        tr2[i].val = tr1[i].val;
    }
    for(i=1;i<n_z+1;++i)
    {
        for(j=i+1;j<n_z+1;++j)
        {
            if(tr2[i].row > tr2[j].row)
            {
                tr temp = tr2[i];
                tr2[i] = tr2[j];
                tr2[j] = temp;
            }
            if(tr2[i].row == tr2[j].row)
            {
                if(tr2[i].col > tr2[j].col)
                {
                    tr temp = tr2[i];
                    tr2[i] = tr2[j];
                    tr2[j] = temp;
                }
            }
        }
    }
    printf("\nSparse matrix:\n");
    for(i=0;i<n_z+1;++i)
    {
        printf("%d %d %d\n",tr1[i].row,tr1[i].col,tr1[i].val);
    }
    printf("\nTranspose of sparse matrix:\n");
    printf("\n\n");
    for(i=0;i<n_z+1;++i)
    {
        printf("%d %d %d\n",tr2[i].row,tr2[i].col,tr2[i].val);
    }
    tr sum[(2*n_z) + 1];
    sum[0].row = tr1[0].row;
    sum[0].col = tr1[0].col;
    sum[0].val = tr1[0].val;
    i = 1,j = 1;
    k = 1;
    printf("\nSum is:\n");
    while(i < n_z+1 || j < n_z + 1)
    {
        if(tr1[i].row < tr2[j].row)
        {
            sum[k] = tr1[i];
            k++;i++;
        }
        if(tr1[i].row > tr2[j].row)
        {
            sum[k] = tr2[j];
            k++;j++;
        }
        if(tr1[i].row == tr2[j].row)
        {
            if(tr1[i].col < tr2[j].col)
            {
                sum[k] = tr1[i];
                k++;i++;
            }
            else if(tr1[i].col > tr2[j].col)
            {
                sum[k] = tr2[j];
                k++;j++;
            }
            else
            {
                sum[k] = tr2[j];
                sum[k].val = tr1[i].val + tr2[j].val;
                i++;k++;j++;
            }
        }
    }
    while(i < n_z+1)
    {
        sum[k] = tr1[i];
        k++;i++;
    }
    while(j < n_z+1)
    {
        sum[k] = tr2[j];
        k++;j++;
    }
    printf("\n\n");
    printf("%d %d %d\n",k-1,k-1,k-1);
    for(i=1;i<k;++i)
    {
        printf("%d %d %d\n",sum[i].row,sum[i].col,sum[i].val);
    }

}
