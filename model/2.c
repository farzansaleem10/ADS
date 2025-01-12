#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
} *front = NULL, *rear = NULL, *new, *temp;

void enque(int data)
{
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
}
void deq()
{
    int n;
    if (front == NULL && rear == NULL)
    {
        printf("No element to delete\n");
        return;
    }
    else if (front == rear)
    {
        temp = front;
        front = NULL;
        rear = NULL;
        free(temp);
    }
    else
    {
        temp = front;
        front = front->next;
        free(temp);
    }
}

void main()
{
    int ch;
    while (1)
    {
        printf("1.enque\t2.deque\t3.display\t4.exit\nChoice: ");
        scanf("%d", &ch);
        new = (struct node *)malloc(sizeof(struct node));
        switch (ch)
        {
        case 1:
            printf("Enter the element: ");
            scanf("%d", &new->data);
            new->next = NULL;
            enque(new->data);
            break;
        case 2:
            deq();
            break;
        case 3:
            if (front == NULL && rear == NULL)
            {
                printf("Queue is empty!!");
            }
            else
            {
                printf("queue: ");
                temp = front;
                for (temp = front; temp != NULL; temp = temp->next)
                {
                    printf("%d ", temp->data);
                }
            }
            printf("\n");
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Invalid choice!!\n");
        }
    }
}