#include<stdio.h>
#include<stdlib.h>
void insert();
void display();
void search();
void delete();

struct node{
    int data;
    struct node* next;
}*head=NULL,*temp,*new;
void main()
{
  int ch;
  while(1){
  printf("Enter the operation\n1.insert\n2.delete\n3.display\n4.search\n5.exit\n");
  scanf("%d",&ch);
  switch(ch){
    case 1:insert();
           break;
    case 2:delete();
        break;
    case 3:display();
           break;
    case 4:search();
           break;
    case 5:exit(0);
           break;
    default:printf("invalid choice");                         
  }
  }
}

void insert(){
  int ch,n,pos,count=0;
  printf("Enter the position\n1.insert at beginning\n2.insert at end\n3.insert at anywhere\n");
  scanf("%d",&ch);
  new=(struct node*)malloc(sizeof(struct node));
  switch(ch){
       case 1:
       printf("Enter the element: ");
       scanf("%d",&n);
       new->data=n;
       new->next=NULL;
       if(head==NULL){
              head=new;
       }
       else{
              new->next=head;
              head=new;
       }
       break;
       case 2:
       printf("Enter the element: ");
       scanf("%d",&n);
       new->data=n;
       new->next=NULL;
       if(head==NULL){
              head=new;
       }
       else{
             for(temp=head;temp->next!=NULL;temp=temp->next)
             {
             }
             temp->next=new;
       }
       break;
       case 3:
       printf("Enter the element: ");
       scanf("%d",&n);
       new->data=n;
       new->next=NULL;
       printf("Enter the position: ");
       scanf("%d",&pos);
       temp=head;
       while(temp!=NULL){
              count++;
              temp=temp->next;
       }
       if(head==NULL){
              head=new;
       }
       else if(pos>count+1){
              printf("Out of range!!\n");
              return;
       }
       else if(pos==1){
              temp=head;
              new->next=temp;
              head=new;
       }
       else{
            temp=head;
            for(int i=1;i<pos-1;i++)  
            {
              temp=temp->next;
            }
            new->next=temp->next;
            temp->next=new;
       }
       break;
  }
}

void display()
{
 if(head==NULL)
 {
       printf("Empty!!");
 }
 for(temp=head;temp!=NULL;temp=temp->next)
 {
       printf("%d\t",temp->data);
 }
 printf("\n");
}

void search()
{
 int n,flag=0;
 printf("Enter the element to be searched: ");
 scanf("%d",&n);
 for(temp=head;temp->next!=NULL;temp=temp->next)
 {
       if(temp->data==n){
          flag=1;
       }
 }
 if(flag==1){
       printf("Element found.\n");
 }
 else{
       printf("Element not found.\n");
 }
}

void delete()
{
 int ch,n,count=0,pos;
 printf("Enter your choice:\n1.delete from beginning\n2.delete from end\n3.delete from anywhere\n");
 scanf("%d",&ch);
 switch(ch){
       case 1:
       if(head==NULL)
       {
              printf("No element to delete.");
       }
       else{
              temp=head;
              head=head->next;
              free(temp);
       }
       break;
       case 2:
       if(head==NULL)
       {
              printf("No element to delete.");
              return;
       }
       else if(head->next==NULL){
              head=NULL;
              free(head);
       }
       else{
              struct node *prev=NULL;
              for(temp=head;temp->next!=NULL;temp=temp->next)
              {
                     prev=temp;
              }
              prev->next=NULL;
              free(temp);
       }
       break;
       case 3:
       printf("Enter the position of element to be deleted: ");
       scanf("%d",&pos);
       temp=head;
       while(temp!=NULL){
              count++;
              temp=temp->next;
       }
       if(head==NULL){
              printf("No element to delete.\n");
              return;
       }
       if(pos>count){
              printf("out of range\n");
       }
       if (pos==1){
              temp=head;
              head=head->next;
              free(temp);
       }
       else{
              struct node *prev=NULL;
              temp=head;
              for(int i=1;i<pos;i++)
              {      
                     prev=temp;
                     temp=temp->next;
              }
              prev->next=temp->next;
              free(temp);
       }
 }
}
