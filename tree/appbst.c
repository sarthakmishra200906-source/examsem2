#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *rootnode=NULL;
 struct node *creat(){
    int x;
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("enter the data of the node");
    scanf("%d",&x);
    if(x==-1){
        return 0;
    }else{
        newnode->data=x;
        printf("enter the left child of %d",x);
        newnode->left=creat();
        printf("enter the right child of %d",x);
        newnode->right=creat();
        return newnode;}
 }
int main(){
    struct node *root;
    root=NULL;
    root=creat();
}