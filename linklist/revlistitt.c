#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL, *temp,*currentnode = NULL, *prevnode, *nextnode;
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
void reverse_ittrative()
{
prevnode = NULL;
currentnode = head;
while(nextnode != NULL)
{
    nextnode = currentnode->next;
    currentnode->next = prevnode;
    prevnode = currentnode;
    currentnode = nextnode;
}
head = prevnode;
}
void display()
if(head == NULL)
{
    printf("list is empty");
}else{
    temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}
int main()
{
    int choice;
    while (1)
    {
        printf("\n1.create list\n2.reverse list\n3.display list\n4.exit");
        printf("\nenter your choice ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            creatlist();
            break;
        case 2:
            reverse_ittrative();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("invalid choice");
        }
    }
}
  