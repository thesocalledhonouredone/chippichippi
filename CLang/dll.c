#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Node {
    int data;

    struct Node* prev;
    struct Node* next;
};

typedef struct Node Node;

//functions 
bool checkNULL(Node* head);
void init(Node** head, int data);
void printForward(Node** head);
void printBackward(Node** head);
void addStart(Node** head, int data);

int main() {

    Node* a = NULL;
    Node* b = NULL;
    Node* c = NULL;

    a = (Node*)malloc(sizeof(Node));
    b = (Node*)malloc(sizeof(Node));
    c = (Node*)malloc(sizeof(Node));

    a->data = 10;
    b->data = 20;
    c->data = 30;

    a->next = b;
    b->next = c;
    c->next = NULL;

    c->prev = b;
    b->prev = a;
    a->prev = NULL;

    printForward(&a);
    printf("\n");
    printBackward(&a);

    return 0;
}

bool checkNULL(Node* head) { // helper function to check if Node is NULL
    return (head == NULL) ? true : false;
}

void init(Node** head, int data) { // function to initilize double linked-list
    if(checkNULL(*head)) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = data;
        newNode->next = NULL;
        newNode->prev = NULL;

        *head = newNode;
    } else {
        printf("\n\nLIST ALREADY EXITS, TERMINATING PROGRAM\n\n");
        exit(1);
    }
}

void printForward(Node** head) { // function to print list in forward direction
    if(!checkNULL(*head)) {
        Node* temp = *head;
        while(temp != NULL) {
            printf("%d\n", temp->data);
            temp = temp->next;
        }
        printf("END OF LIST\n");
    } else
        printf("UN-initilized liked list\n");
}

void printBackward(Node** head) { // function to print the list in backward direction 
    if(!checkNULL(*head)) {
        Node* temp = *head;
        while(temp->next != NULL)
            temp = temp->next;

        while(temp != NULL) {
            printf("%d\n", temp->data);
            temp = temp->prev;
        }
        printf("END OF LIST\n");
    } else
        printf("UN-initilized liked list\n");
}