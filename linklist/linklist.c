#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct double_node
{
    int data;
    struct double_node *prev;
    struct double_node *next;
};
struct circular_node
{
    int data;
    struct circular_node *next;
};
struct node *newnode, *temp, *head = NULL;
struct double_node *newnode2, *temp2, *head2 = NULL;
struct circular_node *newnode3, *temp3, *head3 = NULL;
int count1 = 0;
int count2 = 0;
int count3 = 0;
/* Preserve the existing function bodies while using separate counters. */
#define count count1
void circulardeleate();
void call();
void singlylinklist_menu();
void doublylinklist_menu();
void circularlinklist_menu();
void free_singly_list();
void free_doubly_list();
void free_circular_list();
void create()
{
    int n;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("enter your data");
    scanf("%d", &n);
    if (head == NULL)
    {
        head = temp = newnode;
        newnode->data = n;
        newnode->link = NULL;
        count++;
    }
    else
    {
        newnode->data = n;
        newnode->link = NULL;
        temp->link = newnode;
        temp = newnode;
        count++;
    }
}
void display()
{
    if (head == NULL)
    {
        printf("list is empty create list first");
    }
    else
    {
        temp = head;
        printf("your linklist is : ");
        while (temp != NULL)
        {
            printf("%d", temp->data);
            temp = temp->link;
        }
    }
}
void deleate()
{
    if (head == NULL)
    {
        printf("linklist is empty nothing to deleate : ");
    }
    else
    {
        temp = head;
        head = head->link;
        free(temp);
        count--;
    }
}
void insertatbeg()
{
    if (head == NULL)
    {
        create();
    }
    else
    {
        int n;
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("enter your data");
        scanf("%d", &n);
        newnode->data = n;
        newnode->link = head;
        head = newnode;
        count++;
    }
}
void insertatend()
{
    if (head == NULL)
    {
        create();
    }
    else
    {
        temp = head;
        while (temp->link != NULL)
        {
            temp = temp->link;
        }
        int n;
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("enter your data");
        scanf("%d", &n);
        newnode->data = n;
        newnode->link = NULL;
        temp->link = newnode;
        count++;
    }
}
void insertatany()
{
    int pos;
    printf("enter your position : ");
    scanf("%d", &pos);
    if (pos == 1)
    {
        insertatbeg();
    }
    else if (pos == count + 1)
    {
        insertatend();
    }
    else if (pos < 1 || pos > count + 1)
    {
        printf("Invalid position!");
    }
    else
    {
        temp = head;
        for (int i = 1; i < pos - 1; i++)
        {
            temp = temp->link;
        }
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &newnode->data);
        newnode->link = temp->link;
        temp->link = newnode;
        count++;
    }
}
void deleateatbeg()
{
    deleate();
}
void deleateatend()
{
    if (head == NULL)
    {
        printf("list is empty create one to deleate");
    }
    else if (head->link == NULL)
    {
        free(head);
        head = NULL;
        count--;
    }
    else
    {
        struct node *prev = NULL;
        temp = head;
        while (temp->link != NULL)
        {
            prev = temp;
            temp = temp->link;
        }
        prev->link = NULL;
        free(temp);
        count--;
    }
}
void deleateatany()
{
    int pos;
    printf("Enter position to delete: ");
    scanf("%d", &pos);
    if (head == NULL)
    {
        printf("List is empty.\n");
    }
    else if (pos == 1)
    {
        deleateatbeg();
    }
    else if (pos > count || pos < 1)
    {
        printf("Invalid position!\n");
    }
    else if (pos == count)
    {
        deleateatend();
    }
    else
    {
        struct node *prev;
        temp = head;
        for (int i = 1; i < pos; i++)
        {
            prev = temp;
            temp = temp->link;
        }
        prev->link = temp->link;
        free(temp);
        count--;
    }
}
void free_singly_list()
{
    struct node *current = head;
    while (current != NULL)
    {
        temp = current->link;
        free(current);
        current = temp;
    }
    head = NULL;
    temp = NULL;
    count = 0;
    printf("All singly linked list data has been freed.\n");
}
/* Switch the shared name to the doubly linked list counter. */
#undef count
#define count count2
void createdoublelinklist()
{
    int n;
    newnode2 = (struct double_node *)malloc(sizeof(struct double_node));
    printf("enter your data");
    scanf("%d", &n);
    if (head2 == NULL)
    {
        head2 = temp2 = newnode2;
        newnode2->data = n;
        newnode2->prev = NULL;
        newnode2->next = NULL;
        count++;
    }
    else
    {
        newnode2->data = n;
        newnode2->prev = temp2;
        newnode2->next = NULL;
        temp2->next = newnode2;
        temp2 = temp2->next;
        count++;
    }
}
void displaydoublylinklist()
{
    if (head2 == NULL)
    {
        printf("list is empty create list first");
    }
    else
    {
        temp2 = head2;
        printf("your double linklist is : ");
        while (temp2 != NULL)
        {
            printf("%d", temp2->data);
            temp2 = temp2->next;
        }
    }
}
void deleatedoublylinklist()
{
    if (head2 == NULL)
    {
        printf("list is empty nothing to deleate : ");
    }
    else
    {
        temp2 = head2;
        head2 = head2->next;
        // CRITICAL: if new head exists, clear its prev pointer
        if (head2 != NULL)
        {
            head2->prev = NULL;
        }
        free(temp2);
        count--;
    }
}
void insertatbegningdoublylinklist()
{
    if (head2 == NULL)
    {
        createdoublelinklist();
    }
    else
    {
        int n;
        printf("enter your data");
        scanf("%d", &n);
        newnode2 = (struct double_node *)malloc(sizeof(struct double_node));
        newnode2->data = n;
        newnode2->prev = NULL;
        newnode2->next = head2;
        head2->prev = newnode2;
        head2 = newnode2;
        count++;
    }
}
void insertatenddoubleylinklist()
{
    if (head2 == NULL)
    {
        createdoublelinklist();
    }
    else
    {
        temp2 = head2;
        while (temp2->next != NULL)
        {
            temp2 = temp2->next;
        }
        int n;
        printf("enter your data");
        scanf("%d", &n);
        newnode2 = (struct double_node *)malloc(sizeof(struct double_node));
        newnode2->data = n;
        newnode2->prev = temp2;
        newnode2->next = NULL;
        temp2->next = newnode2;
        temp2 = temp2->next;
        count++;
    }
}
void insertatanyposdoublylinklist()
{
    int pos;
    printf("enter your position : ");
    scanf("%d", &pos);
    if (pos == 1)
    {
        insertatbegningdoublylinklist();
    }
    else if (pos == count + 1)
    {
        insertatenddoubleylinklist();
    }
    else if (pos < 1 || pos > count + 1)
    {
        printf("invalid position");
    }
    else
    {
        temp2 = head2;
        for (int i = 1; i < pos - 1; i++)
        {
            temp2 = temp2->next;
        }
        int n;
        printf("enter your data");
        scanf("%d", &n);
        newnode2 = (struct double_node *)malloc(sizeof(struct double_node));
        newnode2->data = n;
        newnode2->prev = temp2;
        newnode2->next = temp2->next;
        temp2->next->prev = newnode2;
        temp2->next = newnode2;
        count++;
    }
}
void deleateatbegningdoublylinklist()
{
    deleatedoublylinklist();
}
void deleateatenddounlylinklist()
{
    if (head2 == NULL)
    {
        printf("list is empty create one to deleate");
    }
    else if (head2->next == NULL)
    {
        free(head2);
        head2 = NULL;
        count--;
    }
    else
    {
        struct double_node *prev = NULL;
        temp2 = head2;
        while (temp2->next != NULL)
        {
            prev = temp2;
            temp2 = temp2->next;
        }
        prev->next = NULL;
        free(temp2);
        count--;
    }
}
void deleateatanyposdoublylinklist()
{
    int pos;
    printf("Enter position to delete: ");
    scanf("%d", &pos);
    if (head2 == NULL)
    {
        printf("List is empty.\n");
    }
    else if (pos == 1)
    {
        deleateatbegningdoublylinklist();
    }
    else if (pos > count || pos < 1)
    {
        printf("Invalid position!\n");
    }
    else if (pos == count)
    {
        deleateatenddounlylinklist();
    }
    else
    {
        struct double_node *prev;
        temp2 = head2;
        for (int i = 1; i < pos; i++)
        {
            prev = temp2;
            temp2 = temp2->next;
        }
        prev->next = temp2->next;
        temp2->next->prev = prev;
        free(temp2);
        count--;
    }
}
void free_doubly_list()
{
    struct double_node *current = head2;
    while (current != NULL)
    {
        temp2 = current->next;
        free(current);
        current = temp2;
    }
    head2 = NULL;
    temp2 = NULL;
    count = 0;
    printf("All doubly linked list data has been freed.\n");
}
/* Switch the shared name to the circular linked list counter. */
#undef count
#define count count3
void circularlinklist()
{
    int n;
    printf("enter your data : ");
    scanf("%d", &n);
    newnode3 = (struct circular_node *)malloc(sizeof(struct circular_node));
    newnode3->data = n;
    if (head3 == NULL)
    {
        head3 = temp3 = newnode3;
        newnode3->next = head3;
        count++;
    }
    else
    {
        newnode3->next = head3;
        temp3->next = newnode3;
        temp3 = newnode3;
        count++;
    }
}

void deleatecircularatbeg()
{
    circulardeleate();
}
void circulardeleate()
{
    if (head3 == NULL)
    {
        printf("nothing to deleate create one");
    }
    else if (head3->next == head3)
    {
        free(head3);
        head3 = NULL;
        count--;
    }
    else
    {
        struct circular_node *tail = head3;
        temp3 = head3;
        while (tail->next != head3)
        {
            tail = tail->next;
        }
        head3 = head3->next;
        tail->next = head3;
        free(temp3);
        count--;
    }
}
void deleatecircularatend()
{
    if (head3 == NULL)
    {
        printf("nothing to deleate create one");
    }
    else if (head3->next == head3)
    {
        free(head3);
        head3 = NULL;
        count--;
    }
    else
    {
        struct circular_node *prev = NULL;
        temp3 = head3;
        while (temp3->next != head3)
        {
            prev = temp3;
            temp3 = temp3->next;
        }
        prev->next = head3;
        free(temp3);
        count--;
    }
}
void deleateatanyposcircular()
{
    int pos;
    printf("enter your position : ");
    scanf("%d", &pos);
    if (head3 == NULL)
    {
        printf("nothing to deleate create one");
    }
    else if (pos == 1)
    {
        deleatecircularatbeg();
    }
    else if (pos == count)
    {
        deleatecircularatend();
    }
    else if (pos < 1 || pos > count)
    {
        printf("invalid position");
    }
    else
    {
        struct circular_node *prev = NULL;
        temp3 = head3;
        for (int i = 1; i < pos; i++)
        {
            prev = temp3;
            temp3 = temp3->next;
        }
        prev->next = temp3->next;
        free(temp3);
        count--;
    }
}
void free_circular_list()
{
    if (head3 == NULL)
    {
        printf("Circular linked list is already empty.\n");
        return;
    }

    struct circular_node *current = head3->next;
    while (current != head3)
    {
        temp3 = current->next;
        free(current);
        current = temp3;
    }
    free(head3);
    head3 = NULL;
    temp3 = NULL;
    count = 0;
    printf("All circular linked list data has been freed.\n");
}
void addatbegningcircular()
{
    int n;
    printf("enter your data : ");
    scanf("%d", &n);
    newnode3 = (struct circular_node *)malloc(sizeof(struct circular_node));
    newnode3->data = n;
    if (head3 == NULL)
    {
        circularlinklist();
    }
    else
    {
        newnode3->next = head3;
        struct circular_node *tail = head3;
        while (tail->next != head3)
        {
            tail = tail->next;
        }
        tail->next = newnode3;
        head3 = newnode3;
        count++;
    }
}
void addatendcircular()
{
    if (head3 == NULL)
    {
        circularlinklist();
    }
    else
    {
        int n;
        printf("enter your data : ");
        scanf("%d", &n);
        newnode3 = (struct circular_node *)malloc(sizeof(struct circular_node));
        newnode3->data = n;
        newnode3->next = head3;
        struct circular_node *tail = head3;
        while (tail->next != head3)
        {
            tail = tail->next;
        }
        tail->next = newnode3;
        count++;
    }
}
void addatanyposcircular()
{
    int pos;
    printf("enter your position : ");
    scanf("%d", &pos);
    if (pos == 1)
    {
        addatbegningcircular();
    }
    else if (pos == count + 1)
    {
        addatendcircular();
    }
    else if (pos < 1 || pos > count + 1)
    {
        printf("invalid position");
    }
    else
    {
        int n;
        printf("enter your data : ");
        scanf("%d", &n);
        newnode3 = (struct circular_node *)malloc(sizeof(struct circular_node));
        newnode3->data = n;
        temp3 = head3;
        for (int i = 1; i < pos - 1; i++)
        {
            temp3 = temp3->next;
        }
        newnode3->next = temp3->next;
        temp3->next = newnode3;
        count++;
    }
}
void displaycircular()
{
    if (head3 == NULL)
    {
        printf("list is empty create one first");
    }
    else
    {
        temp3 = head3;
        printf("your circular linklist is : ");
        do
        {
            printf("%d", temp3->data);
            temp3 = temp3->next;
        } while (temp3 != head3);
    }
}
/* Menus do not use the counter directly. */
#undef count
void singlylinklist_menu()
{
    while (1)
    {
        int choice1;
        printf("\n========== SINGLY LINKED LIST ==========\n");
        printf("1. Create\n");
        printf("2. Display\n");
        printf("3. Delete from beginning\n");
        printf("4. Insert at beginning\n");
        printf("5. Insert at end\n");
        printf("6. Insert at any position\n");
        printf("7. Delete at beginning\n");
        printf("8. Delete at end\n");
        printf("9. Delete at any position\n");
        printf("10. Free whole list\n");
        printf("11. Exit to Main Menu\n");
        printf("=========================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice1);
        printf("\n");

        switch (choice1)
        {
        case 1:
            create();
            printf("\n");
            break;
        case 2:
            display();
            printf("\n");
            break;
        case 3:
            deleate();
            printf("\n");
            break;
        case 4:
            insertatbeg();
            printf("\n");
            break;
        case 5:
            insertatend();
            printf("\n");
            break;
        case 6:
            insertatany();
            printf("\n");
            break;
        case 7:
            deleateatbeg();
            printf("\n");
            break;
        case 8:
            deleateatend();
            printf("\n");
            break;
        case 9:
            deleateatany();
            printf("\n");
            break;
        case 10:
            free_singly_list();
            printf("\n");
            break;
        case 11:
            printf("You exited Singly Linked List\n\n");
            return;
        default:
            printf("Invalid choice! Try again.\n\n");
        }
    }
}

void doublylinklist_menu()
{
    while (1)
    {
        int choice2;
        printf("\n========== DOUBLY LINKED LIST ==========\n");
        printf("1. Create\n");
        printf("2. Display\n");
        printf("3. Delete\n");
        printf("4. Insert at beginning\n");
        printf("5. Insert at end\n");
        printf("6. Insert at any position\n");
        printf("7. Delete at beginning\n");
        printf("8. Delete at end\n");
        printf("9. Delete at any position\n");
        printf("10. Free whole list\n");
        printf("11. Exit to Main Menu\n");
        printf("=========================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice2);
        printf("\n");

        switch (choice2)
        {
        case 1:
            createdoublelinklist();
            printf("\n");
            break;
        case 2:
            displaydoublylinklist();
            printf("\n");
            break;
        case 3:
            deleatedoublylinklist();
            printf("\n");
            break;
        case 4:
            insertatbegningdoublylinklist();
            printf("\n");
            break;
        case 5:
            insertatenddoubleylinklist();
            printf("\n");
            break;
        case 6:
            insertatanyposdoublylinklist();
            printf("\n");
            break;
        case 7:
            deleateatbegningdoublylinklist();
            printf("\n");
            break;
        case 8:
            deleateatenddounlylinklist();
            printf("\n");
            break;
        case 9:
            deleateatanyposdoublylinklist();
            printf("\n");
            break;
        case 10:
            free_doubly_list();
            printf("\n");
            break;
        case 11:
            printf("You exited Doubly Linked List\n\n");
            return;
        default:
            printf("Invalid choice! Try again.\n\n");
        }
    }
}

void circularlinklist_menu()
{
    while (1)
    {
        int choice3;
        printf("\n========== CIRCULAR LINKED LIST ==========\n");
        printf("1. Create\n");
        printf("2. Display\n");
        printf("3. Delete at beginning\n");
        printf("4. Delete at end\n");
        printf("5. Delete at any position\n");
        printf("6. Insert at beginning\n");
        printf("7. Insert at end\n");
        printf("8. Insert at any position\n");
        printf("9. Free whole list\n");
        printf("10. Exit to Main Menu\n");
        printf("===========================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice3);
        printf("\n");

        switch (choice3)
        {
        case 1:
            circularlinklist();
            printf("\n");
            break;
        case 2:
            displaycircular();
            printf("\n");
            break;
        case 3:
            deleatecircularatbeg();
            printf("\n");
            break;
        case 4:
            deleatecircularatend();
            printf("\n");
            break;
        case 5:
            deleateatanyposcircular();
            printf("\n");
            break;
        case 6:
            addatbegningcircular();
            printf("\n");
            break;
        case 7:
            addatendcircular();
            printf("\n");
            break;
        case 8:
            addatanyposcircular();
            printf("\n");
            break;
        case 9:
            free_circular_list();
            printf("\n");
            break;
        case 10:
            printf("You exited Circular Linked List\n\n");
            return;
        default:
            printf("Invalid choice! Try again.\n\n");
        }
    }
}

void call()
{
    while (1)
    {
        int choice;
        printf("\n================= MAIN MENU =================\n");
        printf("1. Singly Linked List\n");
        printf("2. Doubly Linked List\n");
        printf("3. Circular Linked List\n");
        printf("4. Exit Program\n");
        printf("=============================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice)
        {
        case 1:
            singlylinklist_menu();
            break;
        case 2:
            doublylinklist_menu();
            break;
        case 3:
            circularlinklist_menu();
            break;
        case 4:
            printf("You exited the program successfully!\n");
            exit(0);
            break;
        default:
            printf("Invalid choice! Try again.\n\n");
        }
    }
}
int main()
{
    printf("\n\n╔═══════════════════════════════════════╗\n");
    printf("║       LINKED LIST OPERATIONS          ║\n");
    printf("╚═══════════════════════════════════════╝\n");
    call();
    return 0;
}
