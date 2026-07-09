#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *next;
    struct node *prev;
};

struct node *head = NULL;

void insertBeg(int data);
void insertEnd(int data);
void insert(int data, int pos);
void deleteBeg();
void deleteEnd();
void del(int pos);
void display();

int main()
{
   
    struct node *node1 = (struct node *)malloc(sizeof(struct node));
    node1->info = 1;
    node1->next = NULL;
    node1->prev = NULL;
    head = node1;

    insertBeg(5);
    insertEnd(10);
    insert(8, 2);   
    insert(9, 4);   
    printf("After Insertions:\n");
    display();

    del(3);         
    deleteBeg();
    deleteEnd();
    printf("\nAfter Deletions:\n");
    display();

    return 0;
}

void insertBeg(int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->info = data;
    newnode->prev = NULL;
    newnode->next = head;

    if (head != NULL)
        head->prev = newnode;

    head = newnode;
}


void insertEnd(int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->info = data;
    newnode->next = NULL;
    newnode->prev = NULL;

    if (head == NULL)
    {
        head = newnode;
        return;
    }

    struct node *ptr = head;
    while (ptr->next != NULL)
        ptr = ptr->next;

    ptr->next = newnode;
    newnode->prev = ptr;
}

void insert(int data, int pos)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->info = data;
    newnode->next = NULL;
    newnode->prev = NULL;

    if (head == NULL)
    {
        printf("List is empty.\n");
        free(newnode);
        return;
    }

    struct node *ptr = head;
    for (int i = 1; i < pos; i++)
    {
        ptr = ptr->next;

        if (ptr == NULL)
        {
            printf("Position not found.\n");
            free(newnode);
            return;
        }
    }

    newnode->next = ptr->next;
    newnode->prev = ptr;
    if (ptr->next != NULL)
        ptr->next->prev = newnode;
    ptr->next = newnode;
}


void deleteBeg()
{
    if (head == NULL)
    {
        printf("\nList is empty.\n");
        return;
    }

    struct node *ptr = head;
    head = head->next;
    if (head != NULL)
        head->prev = NULL;
    printf("\nDeleted element is %d", ptr->info);
    free(ptr);
}


void deleteEnd()
{
    if (head == NULL)
    {
        printf("\nList is empty.\n");
        return;
    }

    if (head->next == NULL)
    {
        printf("\nDeleted element is %d", head->info);
        free(head);
        head = NULL;
        return;
    }

    struct node *ptr = head;
    while (ptr->next != NULL)
        ptr = ptr->next;
    ptr->prev->next = NULL;
    printf("\nDeleted element is %d", ptr->info);
    free(ptr);
}

void del(int pos)
{
    if (head == NULL)
    {
        printf("\nList is empty.");
        return;
    }

    if (pos == 1)
    {
        deleteBeg();
        return;
    }

    struct node *ptr = head;
    for (int i = 1; i < pos; i++)
    {
        ptr = ptr->next;

        if (ptr == NULL)
        {
            printf("Position not found.\n");
            return;
        }
    }
    if (ptr->next != NULL)
        ptr->next->prev = ptr->prev;
    ptr->prev->next = ptr->next;
    printf("\nDeleted element is %d", ptr->info);
    free(ptr);
}


void display()
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    struct node *temp, *ptr = head;

    printf("List: ");
    while (ptr != NULL)
    {
        printf("%d ", ptr->info);
        temp = ptr;
        ptr = ptr->next;
    }
    printf("\n");
    printf("Reverse List: ");
    ptr = temp;
    while (ptr != NULL)
    {
        printf("%d ", ptr->info);
        ptr = ptr->prev;
    }
}
