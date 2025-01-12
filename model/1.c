#include <stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
} *front = NULL, *rear = NULL, *new, *temp;

void main()
{
    int x = 1;
    while (x)
    {
        new = (struct node *)malloc(sizeof(struct node));
        printf("Enter the element to insert: ");
        scanf("%d", &new->data);
        new->next = NULL;
        if (front == NULL && rear == NULL)
        {
            rear = new;
            front = new;
        }
        else
        {
            rear->next = new;
            rear = new;
        }
        printf("queue: ");
        temp = front;
        for (temp = front; temp->next != NULL; temp = temp->next)
        {
            printf("%d ", temp->data);
        }
        printf("%d ",temp->data);
        printf("\nwant to continue 0/1: ");
        scanf("%d",&x);
        if(x==0){
            exit(x);
        }
        else{
            x=1;
        }
    }
}