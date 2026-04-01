#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head, *temp, *newnode;

int count = 0;
void creatnode()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("enter data you want to insert: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;

    if (head == NULL) // Use == here!
    {
        head = temp = newnode;
    }
    else
    {
        temp->next = newnode;
        temp = newnode;
    }
    count++; // Moved outside the if/else to keep it clean
}
void insertatbeg()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("enter data you want to insert");
    scanf("%d", &newnode->data);
    newnode->next = head;
    head = newnode;
    count++;
}
void insertatend()
{
    if (head == NULL)
    {
        creatnode();
        return;
    }
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("enter data you want to insert");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    temp = head;
    while (temp->next != NULL)
    { // Travel to the actual end
        temp = temp->next;
    }
    temp->next = newnode;
    count++;
}
void insertatany()
{
    int pos, i = 1;
    printf("Enter position: ");
    scanf("%d", &pos);

    if (pos > count + 1 || pos <= 0)
    {
        printf("Invalid position\n");
    }
    else if (pos == 1)
    {
        insertatbeg();
    }
    else
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &newnode->data);

        temp = head;
        while (i < pos - 1)
        { // Stop at the node BEFORE the position
            temp = temp->next;
            i++;
        }
        newnode->next = temp->next;
        temp->next = newnode;
        count++;
    }
}
void display()
{
    struct node *ptr = head; // Use a local pointer for traversal
    if (ptr == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    while (ptr != NULL)
    {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}
int main()
{
    int choice;

    while (1)
    {
        printf("1. creat a linklist \n 2. insert at begning \n3.insert at end \n4.insert at any position\n 5.display\n6.exit\n");
        printf("enter your choice ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            creatnode();
            break;
        case 2:
            insertatbeg();
            break;
        case 3:
            insertatend();
            break;
        case 4:
            insertatany();
            break;
        case 5:
            display();
            break;
        case 6:
            exit(0);
        default:
            printf("enter valid input ");
        }
    }
}