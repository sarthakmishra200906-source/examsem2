#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *front=NULL, *rear=NULL, *temp, *newNode;
void enqueue(){
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    printf("enter data ");
    scanf("%d", &newNode->data);
    newNode->next = NULL;
    if(rear == NULL)
    {
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
}   
void dequeue(){
    if(front == NULL)
    {
        printf("queue is empty");
    }
    else
    {
        temp = front;
        printf("deleted element is %d", temp->data);
        front = front->next;
        free(temp);
    }
}
void peek(){
    if(front == NULL)
    {
        printf("queue is empty");
    }
    else
    {
        printf("front element is %d", front->data);
    }
}
void display(){
    if(front == NULL)
    {
        printf("queue is empty");
    }
    else
    {
        temp = front;
        printf("queue elements are: ");
        while(temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
}
int main()
{
    int choice;
    while(1)
    {
        printf("1.enqueue\n2.dequeue\n3.peek\n4.display\n5.exit\n");
        printf("enter your choice ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:enqueue();
            break;
            case 2:dequeue();
            break;
            case 3:peek();
            break;
            case 4:display();
            break;
            case 5:exit(0);
            default:printf("invalid choice");
        }
    }
}