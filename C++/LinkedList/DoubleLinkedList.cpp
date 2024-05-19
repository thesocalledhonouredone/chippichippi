#include<iostream>

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int data) {
        this->data = data;
        this->prev = nullptr;
        this->next = nullptr;
    }
};

class DoubleLinkedList {
private:
    Node* head;

public:
    int length;

    DoubleLinkedList() {
        head = nullptr;
        length = 0;
    }

    DoubleLinkedList(int data) {
        head = new Node(data);
        length = 1;
    }

    void addFirst(int data) {
        Node* newNode = new Node(data);
        if(head == nullptr)
            head = newNode;
        else {
            newNode->next = head;
            head = newNode;
        }
        length++;
    }

    void addLast(int data);
    void deleteFirst();
    void deleteLast();
    void addMiddle(int data, int value);
    void deleteMiddle(int value);
    void printForward();
    void printBackward();
    int get(int index);
    int indexOf(int index);
    void joint(DoubleLinkedList* list);
    void clearList();
    void reverseList();
    ~DoubleLinkedList();

};