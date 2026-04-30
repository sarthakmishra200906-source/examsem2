#include<stdio.h>
#include<stdlib.h>
struct node{
    int data ;
    struct node *link;
};
struct double_node{
    int data;
    struct double_node *prev;
    struct double_node *next;
};
struct circular_node{
    int data;
    struct circular_node *prev;
    struct circular_node *next;
};
struct node *newnode,*temp,*head=NULL;
struct double_node *newnode2,*temp2,*head2=NULL;
struct circular_node *newnode3,*temp3,*head3=NULL;
int count=0;
void create(){
    int n ;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("enter your data");
    scanf("%d",&n);
    if(head==NULL){
        head=temp=newnode;
        newnode->data=n;
        newnode->link=NULL;
        count++;
    }else {
        newnode->data=n;
        newnode->link=NULL;
        temp->link=newnode;
        temp=newnode;
        count++;
    }
}
void display(){
    if(head==NULL){
        printf("list is empty create list first");
    }else{
    temp =head;
    printf("your linklist is : ");
    while(temp!=NULL){
        printf("%d",temp->data);
        temp=temp->link;
    }
     }
}
void deleate(){
    if(head==NULL){
        printf("linklist is empty nothing to deleate : ");
    }else{
    temp=head;
    head=head->link;
    free(temp);
    count--;
    }
    
}
void insertatbeg(){
     if(head==NULL){
        create();
    }else{
        int n;
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("enter your data");
        scanf("%d",&n);
        newnode->data=n;
        newnode->link=head;
        head=newnode;
        count++;
    }
}
void insertatend(){
  if(head==NULL){
    create();
  }
  else{
    temp = head;
    while(temp->link != NULL) {
       temp = temp->link;
        }
    int n;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("enter your data");
    scanf("%d",&n);
    newnode->data=n;
    newnode->link=NULL;
    temp->link=newnode;
    count++;
  }
}
void insertatany(){
    printf("enter your position : ");
    scanf("%d",&pos);
    if (pos == 1) {
    insertatbeg();
} 
else if(pos == count + 1) {
    insertatend();
}else if (pos < 1 || pos > count + 1) {
    printf("Invalid position!");
} else {
temp = head;
for (int i = 1; i < pos - 1; i++) {
    temp = temp->link;
}
newnode = (struct node*)malloc(sizeof(struct node));
printf("Enter data: ");
scanf("%d", &newnode->data);
newnode->link = temp->link; 
temp->link = newnode;       
count++;
}
void deleateatbeg(){
    deleate();
}
void deleateatend(){
if(head==NULL){
    printf("list is empty create one to deleate");
}else if(head->link==NULL){
    free(head);
    head=NULL;
    count--;
}
else{
    struct node *prev=NULL;
    temp=head;
   while (temp->link != NULL) {
        prev = temp;     
        temp = temp->link; 
    }
    prev->link=NULL;
    free(temp);
    count--;
}
}
void deleateatany() {
    int pos;
    printf("Enter position to delete: ");
    scanf("%d", &pos);
    if (head == NULL) {
        printf("List is empty.\n");
    } else if (pos == 1) {
        deleateatbeg();
    } else if (pos > count || pos < 1) {
        printf("Invalid position!\n");
    }else if(pos == count) {
        deleateatend();

    } else {
        struct node *prev;
        temp = head;
        for (int i = 1; i < pos; i++) {
            prev = temp;
            temp = temp->link;
        }
        prev->link = temp->link; 
        free(temp);              
        count--;                
    }
}
void createdoublelinklist(){
    int n;
    newnode2=(struct double_node*)malloc(sizeof(struct double_node));
    printf("enter your data");
    scanf("%d",&n);
    if(head2==NULL){
        head2=temp2=newnode2;
        newnode2->data=n;
        newnode2->prev=NULL;
        newnode2->next=NULL;
        count++;
    }else{
        newnode2->data=n;
        newnode2->prev=temp2;
        newnode2->next=NULL;
        temp2->next=newnode2;
        temp2=temp2->next;
        count++;
    }
}
void displaydoublylinklist(){
    if(head2==NULL){
        printf("list is empty create list first");
    }else{
        temp2=head2;
        printf("your double linklist is : ");
        while(temp2!=NULL){
            printf("%d",temp2->data);
            temp2=temp2->next;
        }
    }
}
void deleatedoublylinklist(){
    if(head2==NULL){
        printf("list is empty nothing to deleate : ");
    }else{
        temp2=head2;
        head2=head2->next;
        // CRITICAL: if new head exists, clear its prev pointer
        if (head2 != NULL) {
            head2->prev = NULL;
        }
        free(temp2);
        count--;
    }
}
void insertatbegningdoublylinklist(){
    if(head2==NULL){
        createdoublelinklist();
    }else{
        int n ;
       printf("enter your data");
        scanf("%d",&n);
        newnode2=(struct double_node*)malloc(sizeof(struct double_node));
        newnode2->data=n;
        newnode2->prev=NULL;
        newnode2->next=head2;
        head2->prev = newnode2;
        head2=newnode2;
        count++;
    }
}
void insertatenddoubleylinklist(){
    if(head2==NULL){
        createdoublelinklist();
    }else{
        temp2=head2;
        while(temp2->next!=NULL){
            temp2=temp2->next;
        }
        int n;
        printf("enter your data");
        scanf("%d",&n);
        newnode2=(struct double_node*)malloc(sizeof(struct double_node));
        newnode2->data=n;
        newnode2->prev=temp2;
        newnode2->next=NULL;
        temp2->next=newnode2;
        temp2=temp2->next;
        count++;
    }
}
void insertatanyposdoublylinklist(){
    int pos ;
    printf("enter your position : ");
    scanf("%d",&pos);
    if(pos==1){
        insertatbegningdoublylinklist();
    }else if(pos==count+1){
        insertatenddoubleylinklist();
    }else if(pos<1 || pos>count+1){
        printf("invalid position");
    }else{
        temp2=head2;
        for(int i=1;i<pos-1;i++){
            temp2=temp2->next;
        }
        int n;
        printf("enter your data");  
        scanf("%d",&n);
        newnode2=(struct double_node*)malloc(sizeof(struct double_node));
        newnode2->data=n;
        newnode2->prev=temp2;
        newnode2->next=temp2->next;
        temp2->next->prev=newnode2;
        temp2->next=newnode2;
        count++;
    }
}
void deleateatbegningdoublylinklist(){
    deleatedoublylinklist();
}
void deleateatenddounlylinklist(){
    if(head2==NULL){
        printf("list is empty create one to deleate");
    }else if(head2->next==NULL){
        free(head2);
        head2=NULL;
        count--;
    }else{
        struct double_node *prev=NULL;
        temp2=head2;
       while (temp2->next != NULL) {
            prev = temp2;     
            temp2 = temp2->next; 
        }
        prev->next=NULL;
        free(temp2);
        count--;
    }
}
void deleateatanyposdoublylinklist(){
    int pos;
    printf("Enter position to delete: ");
    scanf("%d", &pos);
    if (head2 == NULL) {
        printf("List is empty.\n");
    } else if (pos == 1) {
        deleateatbegningdoublylinklist();
    } else if (pos > count || pos < 1) {
        printf("Invalid position!\n");
    }else if(pos == count) {
        deleateatenddounlylinklist();

    } else {
        struct double_node *prev;
        temp2 = head2;
        for (int i = 1; i < pos; i++) {
            prev = temp2;
            temp2 = temp2->next;
        }
        prev->next = temp2->next; 
        temp2->next->prev = prev; 
        free(temp2);              
        count--;
    }
}
void circularlinklist(){
    int n 
    printf("enter your data : ");
    scanf("%d",&n);
    newnode3=(struct node*)malloc(sizeof( struct circular_node));
    if(head==NULL){
        head=temp3=newnode3;
        newnode3->data=n;
        newnode3->prev=head;
        newnode->next=head;
    }else{
        newnode3->data=n;
        newnode->prev=temp;
        newnode->next=head;
        temp
    }
}





