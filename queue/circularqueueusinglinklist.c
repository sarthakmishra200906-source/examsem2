#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
    
};
struct node *front = NULL, *rear = NULL, *temp, *newNode;
void enqueue(){
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    printf("enter data ");
    scanf("%d", &newNode->data);
    newNode->next = NULL;
    if(rear == NULL)
    {
        front = rear = newNode;
        rear->next=front;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
        rear->next=front;
    }
}
void dequeue(){
    if(front == NULL)
    {
        printf("queue is empty");
    }
    else if(front == rear)
    {
        printf("deleted element is %d", front->data);
        free(front);
        front = rear = NULL;
    }
    else
    {
        temp = front;
        printf("deleted element is %d", temp->data);
        front = front->next;
        rear->next=front;
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
        do
        {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != front);
        
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