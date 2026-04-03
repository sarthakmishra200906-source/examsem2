#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL, *tail = NULL, *temp;
int count = 0;
void creatlist()
{
    struct node *newnode;
    int n;
    newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("memory allocation failed\n");
        return;
    }

    printf("enter data ");
    scanf("%d", &n);
    newnode->data = n;
    newnode->next = NULL;

    if (head == NULL)
    {
        head = tail = newnode;
    }
    else
    {
        tail->next = newnode;
        tail = newnode;
    }

    count++;
}

void length()
{
    printf("length of linklist is %d", count);
}

int main()
{
    int choice;
    while (1)
    {
        printf("1.creat\n2.length\n3.exit\n");
        printf("Enter your choice ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            creatlist();
            break;
        case 2:
            length();
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
}