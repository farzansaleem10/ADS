#include<stdio.h>
#include<stdlib.h>
#define size 6
void display();

int queue[size],front=-1,rear=-1;

int isempty(){
    if(front==-1)
        return 1;
    return 0;    
}

int isfull(){
    if((rear+1)%size==front)
        return 1;
    return 0;    
}

void enque(){
    int value;
    if(isfull()){
        printf("overflow!\n");
        return;
    }
    printf("element: ");
    scanf("%d",&value);
    if(isempty()){
        front=0;
    }
    rear=(rear+1)%size;
    queue[rear]=value;
    display();
}

void deque(){
    if(isempty()){
        printf("underflow!\n");
        return;
    }
    if(front==rear){
        front=rear=-1;
    }
    else{
        front=(front+1)%size;
    }
}

void display(){
    if(isempty()){
        printf("empty!!\n");
        return;
    }
    for(int i=front;i!=rear;i=(i+1)%size){
        printf("%d ",queue[i]);
    }
    printf("%d",queue[rear]);
}

void main(){
    int ch;
    while(1){
        printf("\n1.enque\t2.deque\t3.display\t4.exit\nchoice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:enque();
            break;
            case 2:deque();
            break;
            case 3:display();
            break;
            case 4:exit(0);
            break;
            default:printf("invalid choice!\n");
        }
    }
}
