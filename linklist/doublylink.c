#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head = NULL, *temp,*newnode;
void creatlist()
{
   newnode=(struct node *)malloc(sizeof(struct node));
   printf("enter data ");
   scanf("%d",&newnode->data);
    newnode->next=NULL; 
    newnode->prev=NULL;
    if(head==NULL)
    {
        head=temp=newnode;
    }
    else
    {
        temp->next=newnode;
        newnode->prev=temp;
        temp=newnode;
    }

}
void display()
{
if(head==NULL)
{
    printf("list is empty");
}
else
{
    temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}
}
int main()
{
    int choice;
    while(1)
    {
        printf("1.creat\n2.display\n3.exit\n");
        printf("enter your choice ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:creatlist();
            break;
            case 2:display();
            break;
            case 3:exit(0);
            default:printf("invalid choice");
        }
    }
}