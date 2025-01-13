#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* right;
    struct node* left;
}*root,*new;

struct node* createnode(int data){
    new=(struct node*)malloc(sizeof(struct node));
    new->data=data;
    new->left=NULL;
    new->right=NULL;
    return new;
}

void preorder(struct node* root){
    if(root==NULL)
        return;
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(struct node* root){
    if(root==NULL)
        return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

void postorder(struct node* root){
    if(root==NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}

void display(){
    if(root==NULL){
        printf("tree is empty\n");
        return;
    }
    printf("preorder traversal: ");
    preorder(root);
    printf("\ninorder traversal: ");
    inorder(root);
    printf("\npostorder traversal: ");
    postorder(root);
}

void main(){
    root=createnode(200);
    root->left=createnode(100);
    root->left->left=createnode(50);
    root->left->right=createnode(150);
    root->right=createnode(300);
    root->right->left=createnode(250);
    root->right->right=createnode(350);
    display(root);
}

