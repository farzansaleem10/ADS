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
  int x, ch1;
  while(1){
  printf("enter the choice :\n1.insert\n2.delete\n3.display\n4.search\n5.exit\n");
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
        printf("Invalid choice!!!\n");
        break;  
  }}
}

void insert()
{
  int n;
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
}

void delete()
{
    int n;
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

void display()

{
  if (head == NULL)
  {
    printf("data is empty");
  }
  for (p = head; p != NULL; p = p->link)
    printf("%d\t", p->data);
}
