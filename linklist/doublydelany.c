#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
    struct node *prev;
};  
struct node *head=NULL,*tail=NULL,*temp,*newnode;
int count=0;
void creatlist()
{
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("enter data ");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    newnode->prev=NULL;
    if(head==NULL)
    {
        head=tail=temp=newnode;
    }
    else
    {
        tail->next=newnode;
        newnode->prev=tail;
        tail=newnode;
    }
    count++;
}
void del_at_beg()
{
    if(head==NULL)
    {
        printf("list is empty");
    }
    else if(head->next==NULL)
    {
        free(head);
        head=tail=NULL;
        return;
    }
    else
    {
        temp=head;
        head=head->next;
        head->prev=NULL;
        free(temp);
        count--;
    }
}
void del_at_end()
{
    if(head==NULL)
    {
        printf("list is empty ");
    }
    else if(head->next==NULL)
    {
        free(head);
        head=tail=NULL;
        return;
    }
    else
    {
        temp=head;
        while(temp->next->next!=NULL)
        {
            temp=temp->next;
        }
        free(temp->next);
        temp->next=NULL;
        tail=temp;
        count--;
    }
}
void del_at_any()
{
    int pos,i=1;
    printf("enter position ");
    scanf("%d",&pos);
    if(pos>count || pos<=0)
    {
        printf("invalid position ");
    }
    else if(pos==1)
    {
        del_at_beg();
    }
    else if(pos==count)
    {
        del_at_end();
    }
    else
    {
        temp=head;
        while(i<pos-1)
        {
            temp=temp->next;
            i++;
        }
        temp->next=temp->next->next;
        free(temp->next->prev);
        temp->next->prev=temp;
        count--;
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
        printf("1.creat\n2.del at beg\n3.del at end\n4.del at any\n5.display\n6.exit\n");
        printf("enter your choice ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:creatlist();
            break;
            case 2:del_at_beg();
            break;
            case 3:del_at_end();
            break;
            case 4:del_at_any();
            break;
            case 5:display();
            break;
            case 6:exit(0);
            default:printf("invalid choice");
        }
    }
}