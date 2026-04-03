#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL, *temp, *newnode;
int count = 0;
void creatlist()
{
    int n;
    newnode = (struct node *)malloc(sizeof(struct node));
    if (head == NULL)
    {
        head = temp = newnode;
        printf("enter data ");
        scanf("%d", &n);
        newnode->data = n;
        newnode->next = NULL;
        count++;
    }
    else
    {
        printf("enter data ");
        scanf("%d", &n);
        newnode->data = n;
        newnode->next = NULL;
        temp->next = newnode;
        temp = newnode;
        count++;
    }
}
void display()
{
    temp = head;
    while (temp != NULL)
    {
        printf("%d", temp->data);
        temp = temp->next;
    }
}
void del_at_beg()
{
    if (head == NULL)
    {
        printf("list is empty ");
    }
    else
    {
        temp = head;
        head = head->next;
        free(temp);
        count--;
    }
}

void del_at_end()
{
    temp = head;
    if (head == NULL)
    {
        printf("list is empty ");
    }
    else if (head->next == NULL)
    {
        free(head);
        head = NULL;
        return;
    }
    else
    {
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
        count--;
    }
}
void del_at_any()
{
    int pos, i = 1;
    printf("enter position ");
    scanf("%d", &pos);
    if (pos > count || pos <= 0)
    {
        printf("invalid position ");
    }
    else if (pos == 1)
    {
        del_at_beg();
    }
    else
    {
        temp = head;
        while (i < pos - 1)
        {
            temp = temp->next;
            i++;
        }
        struct node *todel = temp->next;
        temp->next = todel->next;
        free(todel);
        count--;
    }
}
int main()
{
    int choice;
    while (1)
    {
        printf("1.creat\n2.display\n3.delete at beginning\n4.delete at end\n5.delete at any position\n");
        printf("Enter your choice ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            creatlist();
            break;
        case 2:
            display();
            break;
        case 3:
            del_at_beg();
            break;
        case 4:
            del_at_end();
            break;
        case 5:
            del_at_any();
            break;

        case 6:
            exit(0);
        default:
            printf("invalid choice ");
        }
    }
}
