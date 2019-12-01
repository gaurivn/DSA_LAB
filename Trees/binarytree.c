#include<stdio.h>
#include<stdlib.h>

struct node{
 int data;
 struct node *left;
 struct node *right;
};

struct node{
 int data;
 struct node *next;
};

struct queue{
 struct node *front;
 struct node *rear;
};

struct queue *createqueue(){
 struct queue *q;
 struct node *temp;
 q = malloc(sizeof(struct queue));
 if(!q)
 return NULL;
 temp = malloc(sizeof(struct node));
 q->front = q->rear=NULL;
 return q;
}

int isempty(struct queue *q){
 return (q->front==NULL);
}

void enqueue(struct queue *q, int x){
 struct node *newnode;
 newnode = malloc(sizeof(struct node));
 if(!newnode)
 return;
 newnode->data = x;
 newnode->next = NULL;
 if(q->rear) q->rear->next = newnode;
 q->rear = newnode;
 if(q->front==NULL)
 q->front = q->rear;
}

int dequeue(struct queue *q){
 int dat = 0;
 struct node *temp;
 if(isempty(q)){
 printf("Queue is empty");
 return 0; 
 }
 else{
 temp = q->front;
 dat = q->front->data;
 q->front = q->front->next;
 free(temp);
 }
 return dat;
}

void delqueue(struct queue *q){         //function not working properly. it will be fixed in some time
 struct node *temp;
 while(q){
 temp = q->front;
 q->front = q->front->next;
 free(temp);
 }
 free(q);
}

void preorder(struct node *root){
 if(root){
 printf("%d ",root->data);
 preorder(root->left);
 preorder(root->right);
 }
}

void inorder(struct node *root){
 if(root){
 inorder(root->left);
 printf("%d ",root->data);
 inorder(root->right);
 }
}

void postorder(struct node *root){
 if(root){
 postorder(root->left);
 postorder(root->right);
 printf("%d ",root->data);
 }
}

//Finding size of binary tree
int size(struct node *root){
 if(root==NULL)
 return 0;
 else
 return size(root->left)+1+size(root->right);
}

//Finding height of binary tree
int height(struct node *root){
 int lefth,righth;
 if(root==NULL)
 return 0;
 else{
 //Compute the depth of each subtree
 lefth = height(root->left);
 righth = height(root->right);
 if(lefth>righth)
 return (lefth+1);
 else
 return (righth+1);
}





 

