#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Node {
    int data;
    struct Node* next;
};

typedef struct Node Node;

// basic operational function of SLL
bool checkNULL(Node* head); //helper function
Node* init(Node** head, int data);
void printList(Node** head);
void addLast(Node** head, int data);
void addFirst(Node** head, int data);
void deleteLast(Node** head);
void deleteFirst(Node** head);
void lengthList(Node** head);
void joinList(Node** list1, Node** list2);

int main() {

    Node* head = NULL;
    head = init(&head, 10);
    addLast(&head, 20);
    addLast(&head, 30);
    addFirst(&head, 100);
    addFirst(&head, 200);
    
    Node* ano = NULL;
    ano = init(&ano, 35);
    addLast(&ano, 15);

    joinList(&head, &ano);

    printList(&head);


    return 0;
}

bool checkNULL(Node* head) { // helper function to check if Node is NULL
    return (head == NULL) ? true : false;
}

Node* init(Node** head, int data) { // function to initlize the linked list
    if(checkNULL(*head)) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = data;
        newNode->next = NULL;

        return newNode;

    } else {
        printf("\n\nHEAD ALREADY EXISTS, terminating program\n\n");
        exit(1);
    }
}

void printList(Node** head) { // function to traverse and print the contents of the list
    Node* temp = *head;
    if(!checkNULL(temp)) {
        while(temp != NULL) {
            printf("%d\n", temp->data);
            temp = temp->next;
        }
        printf("\nEND OF LIST\n");
        } else
            printf("UN-initilized liked list\n");
}

void addLast(Node** head, int data) { // function to add Node at END of list
    Node* temp = *head;
    if(!checkNULL(temp)) {
        while(temp->next != NULL) 
            temp = temp->next;
            
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = data;
        newNode->next = NULL;

        temp->next = newNode;
    } else
        printf("UN-initilized liked list\n");
}

void addFirst(Node** head, int data) { // function to add Node at START of list
    Node* temp = *head;
    if(!checkNULL(temp)) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = data;
        newNode->next = temp;
        *head = newNode;
    } else
        printf("UN-initilized liked list\n");
}

void deleteLast(Node** head) { // function to delete last Node in list
    Node* temp = *head;
    if(!checkNULL(temp)) {
        Node* shadow = NULL;
        while(temp->next != NULL) {
            shadow = temp;
            temp = temp->next;
        }
        shadow->next = NULL;
        free(temp);
    } else
        printf("UN-initilized liked list\n");
}

void deleteFirst(Node** head) { // function to delete first Node in list
    Node* temp = *head;
    if(!checkNULL(temp)) {
        Node* another = temp->next;
        *head = another;
        free(temp);
    } else
        printf("UN-initilized liked list\n");
}

void lengthList(Node** head) { // function to find length of list
    Node* temp = *head;
    if(!checkNULL(temp)) {
        int len = 0;
        while(temp != NULL) {
            len++;
            temp = temp->next;
        }
        printf("Lenght of list: %d\n", len);
    } else
        printf("UN-initilized liked list\n");
}

void joinList(Node** list1, Node** list2) { // function to join two lists
    if(!(checkNULL(*list1) && checkNULL(*list2))) {
        Node* temp = *list1;
        while(temp->next != NULL)
            temp = temp->next;
        
        temp->next = *list2;
    } else
        printf("UN-initilized liked list\n");
}