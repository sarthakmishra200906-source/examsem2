#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL, *temp;
int count = 0;
void creatlist()
{
    int n;
    temp = (struct node *)malloc(sizeof(struct node));
    if (head == NULL)
    {
        head = temp;
        printf("enter data ");
        scanf("%d", &n);
        temp->data = n;
        temp->next = NULL;
        count++;
    }
    else
    {
        printf("enter data ");
        scanf("%d", &n);
        temp->data = n;
        temp->next = NULL;
        head->next = temp;
        head = temp;
        count++;
    }
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
        printf("1.creat\n2.length\n");
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
        default:
            printf("Invalid choice\n");
        }
    }
}