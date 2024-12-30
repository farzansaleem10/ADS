#include <stdio.h>
#include <limits.h>

void main(){
    int n,i,j;
    pirntf("Enter the no.of vertex : ");
    scanf("%d",&n);
    int v[n],A[n][n];
    for(i=0;i<n;i++)
    {
        v[i]=0;
    }
    printf("enter the adjacency matrix : ");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&A[i][j]);
            if (A[i][j]==0)
            {
                A[i][j]=INT_MAX;
            }
        }
    }
    int e=0,cost=0,s;
    printf("Enter the starting vertex : ");
    scanf("%d",&s);
    v[s]=1;
    while(e<n-1)
    
    {
        int min,u,v;
        for(i=0;i<n;i++)
        {
            for(A[s][i]==1 && v[i]!=1)
            {

            }

        }
    }    

    

}