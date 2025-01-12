#include<stdio.h>
#include<stdlib.h>
struct node
{
    char data;
    struct node* next;
    struct node* prev;
}*head=NULL,*temp,*new,*current;

struct node* createnode(char data){
    new=(struct node*)malloc(sizeof(struct node));
    new->data=data;
    new->prev=NULL;
    new->next=NULL;
    return new;
}

void main(){
    char str[50];
    char vow[]={'a','e','i','o','u'};
    printf("Enter the string: ");
    gets(str);
    head=createnode(str[0]);
    current=head;
    for(int i=1;str[i]!='\0';i++){
        current->next=createnode(str[i]);
        current->next->prev=current;
        current=current->next;
    }
    printf("string: ");
    for(temp=head;temp!=NULL;temp=temp->next){
        printf("%c",temp->data);
    }
    printf("\nvowels: ");
    for(temp=head;temp!=NULL;temp=temp->next){
        for(int i=0;i<5;i++){
            if(temp->data==vow[i]){
                printf("%c",temp->data);
            }
        }
    }
}