#include <stdio.h>
#include <stdlib.h>
void insert();
void display();
void delete();
void deletebeg();
void deleteend();

struct node
{
    int data;
    struct node *next;
    struct node *prev;
} *head = NULL, *tail = NULL, *temp, *new;

void main()
{
    int ch;
    while (1)
    {
        printf("Select the operation\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insert();
            break;
        case 2:
            delete();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("invalid choice!!");
        }
    }
}

void insert()
{
    int ch, pos, count = 0;
    new = (struct node *)malloc(sizeof(struct node));
    printf("Select the position\n1.Insert at beginning\n2.Insert at end\n3.Insert at anywhere\n");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
        printf("Enter the element: ");
        scanf("%d", &new->data);
        new->next = NULL;
        new->prev = NULL;
        if (head == NULL)
        {
            head = new;
            tail = new;
        }
        else
        {
            temp = head;
            new->next = temp;
            temp->prev = new;
            head = new;
        }
        break;
    case 2:
        printf("Enter the element: ");
        scanf("%d", &new->data);
        if (head == NULL)
        {
            head = new;
            tail = new;
            new->next = NULL;
            new->prev = NULL;
        }
        else
        {
            temp = tail;
            temp->next = new;
            new->prev = temp;
            new->next = NULL;
            tail = new;
        }
        break;
    case 3:
        printf("Enter the element: ");
        scanf("%d", &new->data);
        printf("Enter the position: ");
        scanf("%d", &pos);
        temp = head;
        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }
        if (pos == 1)
        {
            new->prev = NULL;
            new->next = NULL;
            if (head == NULL)
            {
                head = new;
                tail = new;
            }
            else
            {
                temp = head;
                new->next = temp;
                temp->prev = new;
                head = new;
            }
            return;
        }
        if (pos == count + 1)
        {
            if (head == NULL)
            {
                head = new;
                tail = new;
                new->next = NULL;
                new->prev = NULL;
            }
            else
            {
                temp = tail;
                temp->next = new;
                new->prev = temp;
                new->next = NULL;
                tail = new;
            }
            return;
        }
        if (pos < 1 || pos > count + 1)
        {
            printf("Out of range!!\n");
            return;
        }
        else
        {
            temp = head;
            for (int i = 1; i < pos - 1; i++)
            {
                temp = temp->next;
            }
            new->next = temp->next;
            new->prev = temp;
            temp->next = new;
            new->next->prev = new;
        }
    }
}

void display()
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    printf("Head : ");
    for (temp = head; temp != NULL; temp = temp->next)
    {
        printf(" %d ", temp->data);
    }
    printf(" : Tail\n");
    printf("Tail : ");
    for (temp = tail; temp != NULL; temp = temp->prev)
    {
        printf(" %d ", temp->data);
    }
    printf(" : Head\n");
}

void deletebeg()
{
    if (head == tail)
    {
        temp = head;
        free(temp);
        head = NULL;
        printf("List is empty now.\n");
    }
    else
    {
        temp = head;
        head->next->prev = NULL;
        head = head->next;
        free(temp);
    }
}

void deleteend()
{
    if (head == tail)
    {
        temp = head;
        free(temp);
        head = NULL;
        printf("List is empty now.\n");
    }
    else
    {
        temp = tail;
        tail = tail->prev;
        tail->next = NULL;
        free(temp);
    }
}

void delete()
{
    int ch, pos, count = 0;
    printf("Select the position\n1.Delete from the beginning\n2.Delete from the end\n3.Delete from anywhere\n");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
        deletebeg();
        break;
    case 2:
        deleteend();
        break;
    case 3:
        printf("Enter the position of element to be deleted: ");
        scanf("%d", &pos);
        temp = head;
        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }
        if (pos == 1)
        {
            deletebeg();
            return;
        }
        if (count == pos)
        {
            deleteend();
            return;
        }
        if (pos > count)
        {
            printf("Out of range!!");
            return;
        }
        else
        {
            temp = head;
            for (int i = 1; i < pos; i++)
            {
                temp = temp->next;
            }
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            free(temp);
        }
    }
}
