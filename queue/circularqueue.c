#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int queue[MAX], front = -1, rear = -1;
void enqueue(){
if((rear + 1) % MAX == front)
{
    printf("queue is full");
}
else
{
    int n;
    printf("enter data ");
    scanf("%d", &n);
    rear = (rear + 1) % MAX;
    queue[rear] = n;
    if (front == -1)
    {
        front = 0;
    }
}
}
void dequeue(){
if(front == -1)     
{
    printf("queue is empty");
}
else
{
    printf("deleted element is %d", queue[front]);
    if(front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front = (front + 1) % MAX;
    }
}
}
void peek(){
if(front == -1) 
{
    printf("queue is empty");
}
else
{
    printf("front element is %d", queue[front]);
}
}   
void display(){
if(front == -1)     
{
    printf("queue is empty");
}
else
{
    int i = front;
    while (i != rear)
    {
        printf("%d ", queue[i]);
        i = (i + 1) % MAX;
    }
    printf("%d ", queue[rear]);
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
