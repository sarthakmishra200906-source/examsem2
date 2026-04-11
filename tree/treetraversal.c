#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
creat()
{
    int x;
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("enter the data of the node");
    scanf("%d", &x);
    if (x == -1)
    {
        return 0;
    }
    else
    {
        newnode->data = x;
        printf("enter the left child of %d", x);
        newnode->left = creat();
        printf("enter the right child of %d", x);
        newnode->right = creat();
        return newnode;
    }
}
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }else{
        return;
    }
}
void preorder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }else{
        return;
    }
}
void postorder(struct node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }else{
        return;
    }
    
}
int main()
{
    struct node *root;
    while (1)
    {
        int choice;
        printf("enter your choice:\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            root = NULL;
            root = creat();
            break;
        case 2:
            printf("preorder traversal is:");
            preorder(root);
            break;
        case 3:
            printf("inorder traversal is:");
            inorder(root);
            break;
        case 4:
            printf("postorder traversal is:");
            postorder(root);
            break;
        case 5:
            exit(0);
        }
    }
}