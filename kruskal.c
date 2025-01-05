#include <stdio.h>
#include <limits.h>

#define size 50
int i, j, A[size][size], parent[size], u, v, n;

int find(int vertex)
{
    if (parent[vertex] != vertex)
    {
        parent[vertex] = find(parent[vertex]);
    }
    return parent[vertex];
}

void Union(int u, int v)
{
    int rootu = find(u);
    int rootv = find(v);
    parent[rootv] = rootu;
}

void kruskal()
{
    for (i = 0; i < n; i++)
    {
        parent[i] = i;
    }
    int e = 1, cost = 0;
    while (e < n)
    {
        int min = INT_MAX;
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (A[i][j] < min)
                {
                    min = A[i][j];
                    u = i;
                    v = j;
                }
            }
        }
        if (find(u) != find(v))
        {
            printf("{%d,%d}=%d\n", u, v, min);
            cost += min;
            Union(u, v);
            e++;
        }
        A[u][v] = A[v][u] = INT_MAX;
    }
    printf("Total cost: %d", cost);
}

int main()
{
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Insert adjacency matrix:\nNote:insert weight if the nodes have edge bw them else insert 0\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("A[%d][%d] : ", i, j);
            scanf("%d", &A[i][j]);
            if (A[i][j] == 0)
            {
                A[i][j] = INT_MAX;
            }
        }
    }
    kruskal();
    return 0;
}
