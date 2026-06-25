#include<stdio.h>
#include<stdlib.h>

struct node{
    int info;
    struct node *next;
};

struct node *head;
struct node node1;

void insertBeg(int data);
void insertEnd(int data);
void insert(int data,int pos);
void deleteBeg();
void deleteEnd();
void del(int pos);
void display();

int main(){
    node1.info = 1;
    head = &node1;
    node1.next = NULL;
    insertBeg(5);
    insertEnd(10);
    insert(8,2);
    insert(9,4);
    display();
    
    del(2);
    deleteBeg();
    deleteEnd();
    display();
    return 0;
}

void insert(int data,int pos){
    int i;
    struct node *ptr;
    struct node *newnode = (struct node *) malloc (sizeof(struct node));
    newnode->info = data;
    ptr = head;
    for(i=0;i<pos-1;i++){
        ptr = ptr -> next;
        if (ptr == NULL){
            printf("Position not found");
            return;
        }
    }
    newnode -> next = ptr -> next;
    ptr -> next = newnode;
}

void insertBeg(int data){
    int i;
    struct node *ptr;
    struct node *newnode = (struct node *) malloc (sizeof(struct node));
    newnode->info = data;
    ptr = head;
    if(head == NULL){
        head = newnode;
        return;
    }
    else{
        newnode -> next= head;
        head = newnode;
    }
}

void insertEnd(int data){
    int i;
    struct node *ptr;
    struct node *newnode = (struct node *) malloc (sizeof(struct node));
    newnode->info = data;
    newnode -> next = NULL;
    if(head == NULL){
        head = newnode;
        return;
    }
    else{
        ptr = head;
        while (ptr -> next != NULL)
            ptr = ptr -> next;
        ptr -> next = newnode;
    }
}

void display(){
    int i;
    struct node *ptr;
    ptr = head;
    printf("\nThe data are:- ");
    printf("%d ",ptr -> info);
    while(ptr -> next != NULL){
        ptr = ptr -> next;
        printf("%d ",ptr -> info);
    }
}

void del(int pos){
    int i;
    struct node *ptr, *temp;
    if(head == NULL){
        printf("\nList is empty.\n");
        return;
    }
    if(pos ==0 ){
        ptr = head;
        head = head -> next;
        printf("\nDeleted element is %d\n",ptr -> info);
        free(ptr);
    }
    else{
        ptr = head;
        for(i=0;i<pos;i++)
        {
            temp = ptr;
            ptr = ptr -> next;
            if (ptr == NULL)
            {
                printf("Position not found");
                return;
            }
        }
        temp -> next = ptr -> next;
        printf("\nDeleted element is %d",ptr -> info);
        free(ptr);
    }
}

void deleteBeg(){
    struct node *ptr;
    if(head == NULL){
        printf("\nList is empty.\n");
        return;
    }
    else{
        ptr = head;
        head = head -> next;
        printf("\nDeleted element is %d\n",ptr -> info);
        free(ptr);
    }
}

void deleteEnd(){
    struct node *ptr, *temp;
    if(head == NULL){
        printf("\nList is empty.\n");
        return;
    }
    else if (head -> next == NULL){
        ptr = head;
        head = NULL;
        printf("\nDeleted element is %d",ptr -> info);
        free(ptr);
    }
    else{
        ptr = head;
        while(ptr -> next != NULL)
        {
            temp = ptr;
            ptr = ptr -> next;
        }
        temp -> next = NULL;
        printf("Deleted element is %d",ptr -> info);
        free(ptr);
    }
}
