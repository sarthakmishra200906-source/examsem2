#include<stdio.h>
#include<stdlib.h>
struct node {
    int data ;
    struct node *next;
};
struct node *temp ,*top=NULL;
void push(){
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    printf("enter data ");
    scanf("%d",&newnode->data);
    newnode->next=top;
    top=newnode;
}
void pop(){
    if(top==NULL)
    {
        printf("stack is empty");
    }
    else
    {
        struct node *temp=top;
        printf("deleted element is %d", temp->data);
        top=top->next;
        free(temp);
    }
}
void peek (){
     if(top==NULL)
    {
        printf("stack is empty");
    }else{
        printf(" your element is %d",top->data);
    }
}
void display (){
    if (top == NULL){
        printf("stack is empty nothing to display ");
    }else {
        temp =top ;
        printf(" your element of stack are ");
        while(temp !=NULL) {
            printf("%d ", temp->data);
            temp=temp->next;
        }
    }
}
int main()
{
    int choice;
    while(1)
    {
        printf("1.push\n2.pop\n3.peek\n4.display\n5.exit\n");
        printf("enter your choice ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:push();
            break;
            case 2:pop();
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