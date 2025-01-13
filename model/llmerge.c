#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
}*temp,*head1=NULL,*head2=NULL,*new,*current;

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
    return head1;
}

void main(){
    int n1,n2,data;
    printf("no of nodes of list 1: ");
    scanf("%d",&n1);
    for(int i=0;i<n1;i++){
        printf("node data %d: ",i+1);
        scanf("%d",&data);
        if(head1==NULL){
            head1=createnode(data);
            current=head1;
        }
        else{
            current->next=createnode(data);
            current=current->next;
        }
    }
    printf("no of nodes of list 2: ");
    scanf("%d",&n2);
    for(int i=0;i<n2;i++){
        printf("node data %d: ",i+1);
        scanf("%d",&data);
        if(head2==NULL){
            head2=createnode(data);
            current=head2;
        }
        else{
            current->next=createnode(data);
            current=current->next;
        }
    }
    printf("list 1: ");
    for(temp=head1;temp!=NULL;temp=temp->next){
        printf("%d ",temp->data);
    }
    printf("\nlist 2: ");
    for(temp=head2;temp!=NULL;temp=temp->next){
        printf("%d ",temp->data);
    }
    struct node* newhead=mergelist(head1,head2);
    printf("\nmerged list: ");
    for(temp=newhead;temp!=NULL;temp=temp->next){
        printf("%d ",temp->data);
    }
}