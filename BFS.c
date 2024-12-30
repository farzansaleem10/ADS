#include<stdio.h>
int adj[20][20],visited[20],i,j,start,q[20],front=-1,rear=-1,n;

void enq(int node){
    if(rear==-1 && front==-1){
        rear=0;
        front=0;
    }
    else{
        rear++;
    }
    q[rear]=node;
}

int deq(){
    int node=q[front];
    if(rear==front){
        front=-1;
        rear=-1;  
    }
    else{
        front++;
    }
    return node;
}

void bfs(int start)
{
    enq(start);
    visited[start]=1;
    printf("%d ",start);
    while(front!=-1 && rear!=-1){
        int node=deq();
        for(i=0;i<n;i++){
            if(adj[node][i]==1 && visited[i]!=1){
                visited[i]=1;
                printf("%d ",i);
                enq(i);
            }
        }
    }
}

void main(){
    printf("Enter the number of nodes: ");
    scanf("%d",&n);
    printf("Enter the adjacency matrix representation.\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("A[%d][%d] : ",i,j);
            scanf("%d",&adj[i][j]);
        }
    }
    for(i=0;i<n;i++){
        visited[i]=0;
    }
    printf("\nEnter the starting node: ");
    scanf("%d",&start);
    if(start<0 || start>n-1){
        printf("\nInvalid entry!!");
    }
    else{
    printf("\nGraph in BFS : ");
    bfs(start);
    }
}

