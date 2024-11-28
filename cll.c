#include <stdio.h>
#include <stdlib.h>
void display();
void search();
void insert();
void delete();
struct node
{
    int data;
    struct node *next;
} *head = NULL, *new, *temp;
int main()
{
    int ch1, x;
    while (1)
    {

        printf("\nchoose the option\n1.insert\n2.delete\n3.display\n4.search\n5.exit\n");
        scanf("%d", &ch1);
        switch (ch1)
        {
        case 1:
            insert();
            break;
        case 2:
            delete ();
            break;
        case 3:
            display();
            break;
        case 4:
            search();
            break;
        case 5:
            return 0;
            break;
        default:
            printf("Invalid choice!!!");
            break;
        }
    }
}
void insert()
{
    int n, x, s, count = 1;
    printf("where do you want to insert\n1.beginning\n2.end\n3.anywhere\n");
    scanf("%d", &x);
    switch (x)
    {
    case 1:
        new = (struct node *)malloc(sizeof(struct node));
        printf("Enter the element: ");
        scanf("%d", &n);
        new->data = n;
        if (head != NULL)
        {
            new->next = head;
            for (temp = head; temp->next != head; temp = temp->next)
            {
            }
            temp->next = new;
            head = new;
        }
        else
        {
            head = new;
            new->next = head;
        }
        break;
    case 2:
        new = (struct node *)malloc(sizeof(struct node));
        printf("Enter the element: ");
        scanf("%d", &n);
        new->data = n;
        if (head != NULL)
        {
            new->next = head;
            for (temp = head; temp->next != head; temp = temp->next)
            {
            }
            temp->next = new;
            new->next=head;
        }
        else
        {
            head = new;
            new->next = head;
        }
        break;
    case 3:

        new = (struct node *)malloc(sizeof(struct node));
        printf("enter the element: ");
        scanf("%d", &n);
        printf("enter the position to insert: ");
        scanf("%d", &s);
        new->data = n;
        temp = head;
        while (temp->next != head)
        {
            count++;
            temp = temp->next;
        }
        if (s > count)
        {
            printf("Out of range!!");
            return;
        }

        if (s == 1)
        {
            if (head == NULL)
            {
                head = new;
                new->next = head;
            }
            else
            {
                new->next = head;
                for (temp = head; temp->next != head; temp = temp->next)
                {
                }
                temp->next = new;
                head = new;
            }
        }
        else
        {
            temp = head;

            for (int i = 1; i < s-1 ; i++)
            {
                temp = temp->next;
            }
            new->next = temp->next;
            temp->next = new;

        }break;
    }
}

void display()
{
    if (head == NULL)
    {
        printf("data is empty");
    }
    temp = head;
    do
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    } while (temp != head);
}
void search()
{
}
void delete()
{
}
