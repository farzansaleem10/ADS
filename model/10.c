#include<stdio.h>
#include<stdlib.h>
struct node
{
    char data;
    struct node* next;
    struct node* prev;
}*head=NULL,*temp,*new,*current,*tail;

struct node* createnode(char data){
    new=(struct node*)malloc(sizeof(struct node));
    new->data=data;
    new->prev=NULL;
    new->next=NULL;
    return new;
}

void main(){
    char name[50];
    printf("Enter your name: ");
    gets(name);
    head=createnode(name[0]);
    current=head;
    for(int i=1;name[i]!='\0';i++){
        current->next=createnode(name[i]);
        current->next->prev=current;
        current=current->next;
    }
    tail=current;
    printf("name: ");
    temp=head;
    for(temp=head;temp!=NULL;temp=temp->next){
        printf("%c",temp->data);
    }
    printf("\nreverse name: ");
    temp=tail;
    for(temp=tail;temp!=NULL;temp=temp->prev){
        printf("%c",temp->data);
    }
}
