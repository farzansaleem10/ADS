#include <stdio.h>
#include <stdlib.h>
void insertfro();
void display();
void search();
void deletefro();
void insertrear();
void deleterear();
struct node
{
    int data;
    struct node *next;
    struct node *prev; 

} *head= NULL,*new,*temp;
int main()
{
    int ch1, x;
    while (1)
    {

        printf("\nchoose the option\n1.insert at front\n2.insert at rear\n3.delete from front\n4.delete from rear\n5.display\n6.search\n7.exit\n");
        scanf("%d", &ch1);
        switch (ch1)
        {
        case 1:
            insertfro();
            break;
        case 2:
            insertrear();
            break;
        case 3:
            deletefro();
            break;
        case 4:
            deleterear();
            break;
        case 5:
            display();
            break;
        case 6:
            search();
            break;
        case 7:
            return 0;
            break;
        default:
        printf("Invalid choice!!!\n");
        break;
        }
    }
}
void insertfro()
{
    int x;
     new = (struct node *)malloc(sizeof(struct node));
     printf("enter the data : ");
     scanf("%d",&x);
     new->data=x;
     if(head==NULL)
     {
        head=new;
        new->prev=NULL;
        new->next=NULL;
        
     }
     else{
        new->next=head;
        head=new;
        new->prev=NULL;

        
     }
}
void display()
{
    
{
    if (head == NULL)
    {
        printf("data is empty\n");
    }
    for (temp = head; temp != NULL; temp = temp->next)
        printf("%d\t", temp->data);
}
}
void search()
{
{
    int n, flag = 0;
    printf("Enter the element to search: ");
    scanf("%d", &n);
    for (temp = head; temp!= NULL; temp = temp->next)
    {
        if (temp->data == n)
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

}
void deletefro(){
    if(head==NULL)
    {
        printf("no element to delete\n");

    }
    else
    {
        temp=head;
        head=temp->next;
        free(temp);

    }
}
void insertrear(){
    int n;
    printf("Enter the element to insert : ");
    scanf("%d",&n);
    new = (struct node *)malloc(sizeof(struct node));
    new->data=n;
    if(head==NULL)
    {
       head=new;
        new->prev=NULL;
        new->next=NULL;  
    }
    else{
         for (temp = head; temp->next != NULL; temp = temp->next)
            {
            }
            temp->next = new;
            new->prev=temp;
            new->next=NULL;
    }
    

}
void deleterear()
{
     if(head==NULL)
    {
        printf("no element to delete\n");

    }
    else
    {
        for (temp = head; temp->next != NULL; temp = temp->next)
            {
            }
           temp->prev->next=NULL;
           free(temp);
    }
}