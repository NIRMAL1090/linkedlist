#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *add;
} *head = NULL;

void create()
{

    int value;
    printf("Enter the value: ");
    scanf("%d", &value);

    struct node *temp = malloc(sizeof(struct node));
    temp->data = value;
    temp->add = NULL;

    if (head == NULL)
    {
        head = temp;
        head->add = head;
    }
    else
    {

        struct node *p;
        p = head;
        while (p->add != head)
        {
            p = p->add;
        }
        p->add = temp;
        temp->add = head;
    }
}

void ins_first()
{
    int value;
    printf("\nEnter the value: ");
    scanf("%d", &value);

    struct node *temp = malloc(sizeof(struct node));
    temp->data = value;
    temp->add = NULL;

    if (head == NULL)
    {
        head = temp;
        head = head->add;
    }
    else
    {
        struct node *p = head;
        while (p->add != head)
        {
            p = p->add;
        }

        temp->add = head;
        head = temp;
        p->add = head;
    }
}

void ins_last()
{
    int value;
    printf("Enter value: ");
    scanf("%d", &value);

    struct node *temp = malloc(sizeof(struct node));
    temp->data = value;
    temp->add = NULL;

    if (head == NULL)
    {
        head = temp;
        head = head->add;
    }
    else
    {

        struct node *p;
        p = head;
        while (p->add != head)
        {
            p = p->add;
        }
        p->add = temp;
        temp->add = head;
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
        while (p3->add != head)
        {
            p3 = p3->add;
            count++;
        }

        int pos, value, i;
        printf("\n\nEnter the position:: ");
        scanf("%d", &pos);
        printf("\n\nEnter the value:: ");
        scanf("%d", &value);

        if (pos > count)
        {
            printf("\n ---------------------------\n | Enter a valid position! |\n ---------------------------\n\n\n");
        }
        else
        {
            struct node *temp = malloc(sizeof(struct node));
            temp->data = value;
            temp->add = NULL;

            struct node *p, *p2;
            for (i = 1, p = head; i < pos; i++)
            {
                p2 = p;
                p = p->add;
            }
            p2->add = temp;
            temp->add = p;
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
    temp->add = NULL;

    int count = 1;
    struct node *p3 = head;
    while (p3->add != head)
    {
        p3 = p3->add;
        count++;
    }
    int pos = count / 2;

    struct node *p = head, *p2;
    for (int i = 1; i <= pos; i++)
    {
        p2 = p;
        p = p->add;
    }
    p2->add = temp;
    temp->add = p;
}

void del_first()
{
    if (head == NULL)
    {
        printf("\n ----------------------\n | Your List is empty |\n ----------------------\n\n\n");
    }
    else if (head->add == head)
    {
        printf("\n\n(Deleted one node present in the linklist whose value is %d)\n\n", head->data);
        free(head);
        head = NULL;
    }
    else
    {
        struct node *p = head, *del = head;
        while (p->add != head)
        {
            p = p->add;
        }
        head = del->add;
        p->add = head;
        free(del);
    }
}

void del_last()
{
    if (head == NULL)
    {
        printf("\n ----------------------\n | Your List is empty |\n ----------------------\n\n\n");
    }
    else if (head->add == head)
    {
        printf("\n\n(Deleted one node present in the linklist whose value is %d)\n\n", head->data);
        free(head);
        head = NULL;
    }
    else
    {
        struct node *p = head, *last_second_node;
        while (p->add != head)
        {
            last_second_node = p;
            p = p->add;
        }
        last_second_node->add = head;
        printf("\n\n(Deleted last node whose value is %d)\n\n", p->data);
        free(p);
    }
}

void del_pos()
{
    if (head == NULL)
    {
        printf("\n ----------------------\n | Your List is empty |\n ----------------------\n\n\n");
    }
    else
    {
        int pos, i;
        printf("\n\nEnter the position:: ");
        scanf("%d", &pos);

        struct node *del, *last_second, *last;
        del = head;
        for (i = 1; i < pos; i++)
        {
            last_second = del;
            del = del->add;
        }
        printf("\n\n(Deleted a node whose value is %d)\n\n", del->data);
        last = del->add;
        last_second->add = last;
        free(del);
    }
}

void del_middle()
{
    int count = 1;
    struct node *p3 = head;
    while (p3->add != head)
    {
        p3 = p3->add;
        count++;
    }
    int pos = count / 2;
    struct node *del, *last_second, *last;
    del = head;
    for (int i = 1; i <= pos; i++)
    {
        last_second = del;
        del = del->add;
    }
    printf("\n\n(Deleted a node whose value is %d)\n\n", del->data);
    last = del->add;
    last_second->add = last;
    free(del);
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
        printf("\n\nNode Values:\n------------------------------------------------\n");

        printf("(%p) ", head); // for printing address

        while (p->add != head)
        {
            printf("%d -> ", p->data);
            p = p->add;
        }
        p->add = head;
        printf("%d", p->data);

        printf(" (%p) ", p->add); // for printing address

        printf("\n------------------------------------------------");
    }
}

int main()
{
    int s;

    do
    {
        printf("\n\n ------------------CHOISE-----------------------");
        printf("\n | 1. To create node.                          |");
        printf("\n ------------------INSERT-----------------------");
        printf("\n | 2. To insert an element at first position   |");
        printf("\n | 3. To insert an element at last position.   |");
        printf("\n | 4. To insert an element by position.        |");
        printf("\n | 10. To insert an element at middle.         |");
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