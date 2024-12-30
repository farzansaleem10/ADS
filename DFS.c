#include <stdio.h>
int adj[20][20], visited[20], i, j, n, start;

void dfs(int node)
{
    visited[node] = 1;
    printf("%d ", node);
    for (i = 0; i < n; i++)
    {
        if (adj[node][i] == 1 && visited[i] != 1)
        {
            dfs(i);
        }
    }
}

void main()
{
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix representation.\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("A[%d][%d] : ", i, j);
            scanf("%d", &adj[i][j]);
        }
    }
    for (i = 0; i < n; i++)
    {
        visited[i] = 0;
    }
    printf("\nEnter the starting node: ");
    scanf("%d", &start);
    if (start < 0 || start > n - 1)
    {
        printf("\nInvalid entry!!");
    }
    else
    {
        printf("\nGraph in DFS : ");
        dfs(start);
    }
}
