#include <stdio.h>
#include <stdlib.h>
void insert();
void display();
void delete();
void search();

struct node
{
    int data;
    struct node *link;
} *head = NULL, *p, *k, *q;
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
        
            break;
        default:
        printf("Invalid choice!!!");
        break;
        }
    }
}
void insert()
{
    int n, x, s, count = 0;
    printf("where do you want to insert\n1.beginning\n2.end\n3.anywhere\n");
    scanf("%d", &x);
    switch (x)
    {
    case 1:
        p = (struct node *)malloc(sizeof(struct node));
        printf("Enter the element: ");
        scanf("%d", &n);
        p->data = n;
        if (head != NULL)
        {
            p->link = head;
            head = p;
        }
        else
        {
            p->link = NULL;
            head = p;
        }
        break;
    case 2:
        p = (struct node *)malloc(sizeof(struct node));
        printf("enter the element: ");
        scanf("%d", &n);
        p->data = n;
        p->link = NULL;
        if (head == NULL)
        {
            head = p;
        }
        else
        {
            for (k = head; k->link != NULL; k = k->link)
            {
            }
            k->link = p;
        }
        break;
    case 3:

        p = (struct node *)malloc(sizeof(struct node));
        printf("enter the element: ");
        scanf("%d", &n);
        printf("enter the position to insert: ");
        scanf("%d", &s);
        p->data = n;
        k = head;
        while (k != NULL)
        {
            count++;
            k = k->link;
        }
        if (s > count)
        {
            printf("Out of range!!");
            return;
        }

        if (s == 1)
        {
            head = p;
            p->link = NULL;
        }
        else
        {
            k = head;

            for (int i = 1; i < s - 1; i++)
            {
                k = k->link;
            }
            p->link = k->link;
            k->link = p;
        }

        break;
    }
}

void display()

{
    if (head == NULL)
    {
        printf("data is empty");
    }
    for (p = head; p != NULL; p = p->link)
        printf("%d\t", p->data);
}

void delete()
{
    int n, x, pos, count = 0;
    printf("where do you want to delete\n1.beginning\n2.end\n3.anywhere\n");
    scanf("%d", &x);
    switch (x)
    {
    case 1:
        if (head == NULL)
        {
            printf("there is no element to delete\n");
        }
        else
        {
            k = head;
            head = head->link;
            free(k);
        }
        break;
    case 2:
        if (head == NULL)
        {
            printf("there is no element to delete\n");
        }
        else if (head->link == NULL)
        {
            free(head);
            head = NULL;
        }
        else
        {
            struct node *prev = NULL;
            for (k = head; k->link != NULL; k = k->link)
            {
                prev = k;
            }
            prev->link = NULL;
            free(k);
        }
        break;
    case 3:
        printf("Enter the position of element to be deleted: ");
        scanf("%d", &pos);
        k = head;
        while (k != NULL)
        {
            count++;
            k = k->link;
        }
        if (pos > count)
        {
            printf("Out of range!!");
            return;
        }
        if (pos == 1)
        {
            k = head;
            head = head->link;
            free(k);
        }

        else
        {

            k = head;
            struct node *prev = NULL;
            for (int i = 1; i < pos; i++)
            {
                prev = k;
                k = k->link;
            }
            prev->link = k->link;
            free(k);
        }
        break;
    }
}

void search()
{
    int n, flag = 0;
    printf("Enter the element to search: ");
    scanf("%d", &n);
    for (k = head; k!= NULL; k = k->link)
    {
        if (k->data == n)
        {
            printf("Element found.\n");
            flag = 1;
            break;
        }
    }
    if (flag == 0)
    {
        printf("Element not found\n");
    }
}
