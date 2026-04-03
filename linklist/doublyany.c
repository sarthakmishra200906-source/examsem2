#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head = NULL, *tail = NULL, *temp = NULL, *newnode = NULL;
int count = 0;
void creatlist()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("enter data ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    newnode->prev = NULL;
    if (head == NULL)
    {
        head = tail = temp = newnode;
    }
    else
    {
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    }
    count++;
}
void insert_at_beg()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("enter data ");
    scanf("%d", &newnode->data);
    newnode->next = head;
    newnode->prev = NULL;
    head->prev = newnode;
    head = newnode;
    count++;
}
void insert_at_end()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("enter data ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    newnode->prev = tail;
    tail->next = newnode;
    tail = newnode;
    count++;
}
void insert_at_any()
{
    int pos, i = 1;
    printf("enter position ");
    scanf("%d", &pos);
    if (pos > count + 1 || pos <= 0)
    {
        printf("invalid position ");
    }
    else if (pos == 1)
    {
        insert_at_beg();
    }
    else if (pos == count + 1)
    {
        insert_at_end();
    }
    else
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("enter data ");
        scanf("%d", &newnode->data);
        temp = head;
        while (i < pos - 1)
        {
            temp = temp->next;
            i++;
        }
        newnode->next = temp->next;
        newnode->prev = temp;
        temp->next->prev = newnode;
        temp->next = newnode;
        count++;
    }
}
void display()
{
    if (head == NULL)
    {
        printf("list is empty");
    }
    else
    {
        temp = head;
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
}
int main()
{
    int choice;
    while (1)
    {
        printf("1.creat\n2.insert at beg\n3.insert at end\n4.insert at any\n5.display\n6.exit\n");
        printf("enter your choice ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            creatlist();
            break;
        case 2:
            insert_at_beg();
            break;
        case 3:
            insert_at_end();
            break;
        case 4:
            insert_at_any();
            break;
        case 5:
            display();
            break;
        case 6:
            exit(0);
        default:
            printf("invalid choice");
        }
    }
}