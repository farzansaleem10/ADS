#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
}*temp=NULL,*head,*tail,*new;

struct node* createnode(int data){
    new=(struct node*)malloc(sizeof(struct node));
    new->data=data;
    new->next=NULL;
    return new;
}

struct node* mergelist(struct node* head1,struct node* head2){
    temp=head1;
    for(temp=head1;temp->next!=NULL;temp=temp->next){
    }
    temp->next=head2;
    struct node* mergehead=head1;
    return head1;
}

void main(){
    struct node* head1=createnode(1);
    head1->next=createnode(2);
    head1->next->next=createnode(3);
    printf("List 1: ");
    for(temp=head1;temp!=NULL;temp=temp->next){
        printf("%d ",temp->data);
    }
    struct node* head2=createnode(4);
    head2->next=createnode(5);
    head2->next->next=createnode(6);
    printf("\nList 1: ");
    for(temp=head2;temp!=NULL;temp=temp->next){
        printf("%d ",temp->data);
    }
    struct node* mergehead=mergelist(head1,head2);
    printf("\nMerged List: ");
    for(temp=mergehead;temp!=NULL;temp=temp->next){
        printf("%d ",temp->data);
    }
}