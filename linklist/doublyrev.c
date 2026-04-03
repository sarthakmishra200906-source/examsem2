#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head = NULL, *tail = NULL;

void creatlist()
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("memory allocation failed\n");
        return;
    }

    printf("enter data ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    newnode->prev = NULL;

    if (head == NULL)
    {
        head = tail = newnode;
    }
    else
    {
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    }
}

void display_forward()
{
    struct node *temp = head;
    if (temp == NULL)
    {
        printf("list is empty");
        return;
    }

    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

void display_reverse()
{
    struct node *temp = tail;
    if (temp == NULL)
    {
        printf("list is empty");
        return;
    }

    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
}

int main()
{
    int choice;
    while (1)
    {
        printf("1.creat\n2.display forward\n3.display reverse\n4.exit\n");
        printf("enter your choice ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            creatlist();
            break;
        case 2:
            display_forward();
            break;
        case 3:
            display_reverse();
            break;
        case 4:
            exit(0);
        default:
            printf("invalid choice");
        }
    }
}
