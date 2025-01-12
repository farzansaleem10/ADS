#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
}*head=NULL,*temp=NULL,*current,*new;
 
struct node *createnode(int data){
    new=(struct node*)malloc(sizeof(struct node));
    new->data=data;
    new->next=NULL;
    return new;
}

void main()
{
    int el[]={1,2,3,4,5,6};
    head=createnode(el[0]);
    current=head;
    for(int i=1;i<6;i++){
        current->next=createnode(el[i]);
        current=current->next;
    }
    printf("Linkedlist: ");
    for(temp=head;temp!=NULL;temp=temp->next){
        printf("%d ",temp->data);
    }
    int sum=0;
    temp=head;
    for(int i=0;i<6;i++){
        if(i%2!=0){
            sum+=temp->data;
        }
        temp=temp->next;
    }
    printf("\nSum=%d",sum);
}