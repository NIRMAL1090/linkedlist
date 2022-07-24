#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *prev;
    struct node *next;

} *head = NULL;

void search()
{
    if (head == NULL)
    {
        printf("\n ----------------------\n | Your List is empty |\n ----------------------\n\n\n");
    }
    else
    {
        int search, found = 0;
        printf("\n\nEnter the the node value you want to search: ");
        scanf("%d", &search);

        struct node *p;
        p = head;

        while (p != NULL)
        {
            if (search == p->data)
            {
                found++;
                break;
            }
            p = p->next;
        }

        if (found >= 1)
        {
            printf("\n\n ----------------------------------\n | Found: %d value in linked list. |\n ----------------------------------", search);
        }
        else
        {
            printf("\n\n --------------------------------------\n | Not found: %d value in linked list. |\n --------------------------------------\n", search);
        }
    }
}

void create()
{
    int value;
    printf("Enter the value: ");
    scanf("%d", &value);

    struct node *temp = malloc(sizeof(struct node));
    temp->data = value;
    temp->prev = NULL;
    temp->next = NULL;

    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        struct node *p;
        p = head;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = temp;
        temp->prev = p;
    }
}

void ins_first()
{
    int value;
    printf("\nEnter the value: ");
    scanf("%d", &value);

    struct node *temp = malloc(sizeof(struct node));
    temp->data = value;
    temp->prev = NULL;
    temp->next = NULL;

    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        head->prev = temp;
        temp->next = head;
        head = temp;
    }
}

void ins_last()
{
    int value;
    printf("\nEnter the value: ");
    scanf("%d", &value);

    struct node *temp = malloc(sizeof(struct node));
    temp->data = value;
    temp->prev = NULL;
    temp->next = NULL;

    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        struct node *p;
        p = head;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = temp;
        temp->prev = p;
    }
}

void ins_pos()
{
    if (head == NULL)
    {
        printf("\n ----------------------\n | Your List is empty |\n ----------------------\n\n\n");
    }
    else
    {
        int count = 1;
        struct node *p3 = head;
        while (p3->next != NULL)
        {
            p3 = p3->next;
            count++;
        }

        int value, pos, i;
        printf("\n\nEnter the the value: ");
        scanf("%d", &value);
        printf("\n\nEnter the position: ");
        scanf("%d", &pos);
        if (pos > count)
        {
            printf("\n ---------------------------\n | Enter a valid position! |\n ---------------------------\n\n\n");
        }
        else
        {
            struct node *temp = malloc(sizeof(struct node));
            temp->data = value;
            temp->prev = NULL;
            temp->next = NULL;

            struct node *p = head, *first, *last;

            for (i = 1; i < pos; i++)
            {
                first = p;
                p = p->next;
            }
            first->next = temp;
            temp->next = p;
            temp->prev = first;
        }
    }
}

void ins_middle()
{
    int value;
    printf("Enter value: ");
    scanf("%d", &value);

    struct node *temp = malloc(sizeof(struct node));
    temp->data = value;
    temp->prev = NULL;
    temp->next = NULL;

    int count = 1;
    struct node *p3 = head;
    while (p3->next != NULL)
    {
        p3 = p3->next;
        count++;
    }
    int pos = count / 2;

    struct node *p = head, *first, *last;

    for (int i = 1; i <= pos; i++)
    {
        first = p;
        p = p->next;
    }
    first->next = temp;
    temp->next = p;
    temp->prev = first;
}

void del_first()
{
    if (head == NULL)
    {
        printf("\n ----------------------\n | Your List is empty |\n ----------------------\n\n\n");
    }
    else if (head->next == NULL)
    {
        printf("\n\n(Deleted one node present in the linklist whose value is %d)\n\n", head->data);
        free(head);
        head = NULL;
    }
    else
    {
        struct node *p = head;
        head = head->next;
        head->prev = NULL;
        printf("\n\n(Deleted a node whose value is %d)\n\n", p->data);
        free(p);
    }
}

void del_last()
{
    if (head == NULL)
    {
        printf("\n ----------------------\n | Your List is empty |\n ----------------------\n\n\n");
    }
    else if (head->next == NULL)
    {
        printf("\n\n(Deleted one node present in the linklist whose value is %d)\n\n", head->data);
        free(head);
        head = NULL;
    }
    else
    {
        struct node *p = head, *second_last;
        while (p->next != NULL)
        {
            second_last = p;
            p = p->next;
        }
        second_last->next = NULL;
        printf("\n\n(Deleted last node whose value is %d)\n\n", p->data);
        free(p);
    }
}

void del_pos()
{

    int pos, i;
    printf("\nEnter the position: ");
    scanf("%d", &pos);

    struct node *p, *last, *last_second;
    p = head;
    for (i = 1; i < pos; i++)
    {
        last_second = p;
        p = p->next;
    }
    last = p->next;
    last_second->next = last;
    last->prev = last_second;
    printf("\n\n(Deleted a node whose value is %d)\n\n", p->data);
    free(p);
}

void del_middle()
{

    int count = 1;
    struct node *p3 = head;
    while (p3->next != NULL)
    {
        p3 = p3->next;
        count++;
    }
    int pos = count / 2;

    struct node *p, *last, *last_second;
    p = head;

    for (int i = 1; i <= pos; i++)
    {
        last_second = p;
        p = p->next;
    }
    last = p->next;
    last_second->next = last;
    last->prev = last_second;
    printf("\n\n(Deleted a node whose value is %d)\n\n", p->data);
    free(p);
}

void display()
{
    if (head == NULL)
    {
        printf("\n ----------------------\n | Your List is empty |\n ----------------------\n\n\n");
    }
    else
    {
        struct node *p = head;
        printf("\n\nNode Values:\n---------------------------------------------------------------\nNULL");

        while (p->next != NULL)
        {
            printf(" <- %d -> ", p->data);
            p = p->next;
        }
        printf(" <- %d -> ", p->data);
        printf("NULL\n---------------------------------------------------------------");
    }
}

int main()
{
    int s;

    do
    {
        printf("\n\n ------------------CHOISE-----------------------");
        printf("\n | 0. To search an element in the list.        |");
        printf("\n -----------------------------------------------");
        printf("\n | 1. To create node.                          |");
        printf("\n ------------------INSERT-----------------------");
        printf("\n | 2. To insert an element at first position   |");
        printf("\n | 3. To insert an element at last position.   |");
        printf("\n | 4. To insert an element by position.        |");
        printf("\n | 10. To insert an element at middel.         |");
        printf("\n ------------------DELETE-----------------------");
        printf("\n | 5. To delete an element at first position.  |");
        printf("\n | 6. To delete an element at last position.   |");
        printf("\n | 7. To delete an element by position.        |");
        printf("\n | 11. To delete an element at middle.         |");
        printf("\n -----------------------------------------------");
        printf("\n | 8. To display the all the nodes.            |");
        printf("\n -----------------------------------------------");
        printf("\n | 9. To exit from program.                    |\n");
        printf(" -----------------------------------------------");
        printf("\n\nEnter your choise: ");
        scanf("%d", &s);

        switch (s)
        {
        case 0:
            search();
            break;
        case 1:
            create();
            break;
        case 2:
            ins_first();
            break;
        case 3:
            ins_last();
            break;
        case 4:
            ins_pos();
            break;
        case 5:
            del_first();
            break;
        case 6:
            del_last();
            break;
        case 7:
            del_pos();
            break;
        case 8:
            display();
            break;
        case 9:
            printf("\n -----------------------\n | Exited the program! |\n -----------------------\n\n\n");
            exit(1);
            break;
        case 10:
            ins_middle();
            break;
        case 11:
            del_middle();
            break;
        default:
            printf("\n\n(Enter a number between 1 - 9)\n\n\n\n\n");
        }

    } while (s != 9);
    return 0;
}

/*

MAIN THING TO REMEMBER IN DOUBLY LINKEDLIST:

p->next=temp;
temp->prev=p;

*/