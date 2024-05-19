#include<iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

class SingleLinkedList {
private:
    Node* head;

public:
    int length;

    SingleLinkedList() {
        head = NULL;
        length = 0;
    }

    SingleLinkedList(int data) {
        head = new Node(data);
        length++;
        head->next = NULL;
    }

    void addFirst(int data) {
        Node* newNode = new Node(data);
        if(head == NULL) {
            head = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
        length++;
    }

    void addLast(int data) {
        Node* newNode = new Node(data);
        if(head ==  NULL) {
            head = newNode;
        } else {
            Node* temp = head;
            while(temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
        length++;
    }

    void printList() {
        if(head == NULL) {
            std::cout << "LIST IS EMPTY" << std::endl;
        } else {
            Node* temp = head;
            while(temp != NULL) {
                std::cout << temp->data << '\n';
                temp = temp->next;
            }
            std::cout << "\nEND OF LIST\n";
        }
    }

    void deleteFirst() {
        if(head == NULL) 
            std::cout << "LIST IS EMPTY\n";
        else {
            Node* temp = head;
            head = temp->next;
            delete temp;
            length--;
        }
    }

    void deleteLast() {
        if(head == NULL)
            std::cout << "LIST IS EMPTY\n";
        else if(head->next == NULL) {
            delete head;
            head = NULL;
            length--;
        } else {
            Node* temp = head;
            Node* shadow = NULL;
            while(temp->next != NULL) {
                shadow = temp;
                temp = temp->next;
            }
            shadow->next = NULL;
            delete temp;
            length--;
        }
    }

    void addMiddle(int data, int value) {
        Node* newNode = new Node(data);
        if(head == NULL) {
            std::cout << "EMPTY LIST\n";
            return;
        }
        else {
            Node* temp = head;
            Node* shadow = NULL;
            while(temp != NULL) {
                shadow = temp;
                temp = temp->next;
                if(shadow->data == value) {
                    shadow->next = newNode;
                    newNode->next = temp;
                    length++;
                    return;
                }
            }
            std::cout << "\nINSERTION FAILED, could not find value\n";
        }
    }

    void deleteMiddle(int value) {
        if(head == NULL)
            std::cout << "EMPTY LIST\n";
        else {
            Node* temp = head;
            Node* shadow = NULL;
            while(temp != NULL) {
                shadow = temp;
                temp = temp->next;
                if(shadow->data == value) {
                    shadow->next = temp->next;
                    delete temp;
                    length--;
                    return;
                }
            }
            std::cout << "\nDELETION FAILED, could not find value\n";
        }
    } 

    int get(int index) {
        if(head == NULL) {
            std::cout << "EMPTY LIST\n";
            return INT_MIN;
        }
        else {
            if(index >= length)
                return INT_MIN;
            Node* temp = head;
            while(index > 0) {
                temp = temp->next;
                index--;
            }
            return temp->data;
        }
    }

    int indexOf(int target) {
        if(head == NULL) {
            std::cout << "EMPTY LIST\n";
            return -1;
        } else {
            Node* temp = head;
            int index {0};
            while(temp != NULL) {
                if(temp->data == target) 
                    return index;
                temp = temp->next;
                index++;
            }
            return -1;
        }
    }

    void join(SingleLinkedList *list) {
        if(head == NULL || list->head == NULL) 
            std::cout << "EMPTY LIST\n";
        else {
            Node* temp = head;
            while(temp->next != NULL)
                temp = temp->next;
            temp->next = list->head;
        }
    }

    void clearList() {
        if(head ==  NULL) 
            std::cout << "LIST IS ALREADY CLEAR\n";
        else {
            Node* temp = head;
            Node* shadow = NULL;
            while(temp != NULL) {
                shadow = temp;
                temp = temp->next;
                delete shadow;
            }
            head = NULL;
        }
    }

    void reverseList() {
        if(head == NULL) 
            std::cout << "EMPTY LIST\n";
        else {
            SingleLinkedList* rev = new SingleLinkedList();
            Node* temp = head;
            while(temp != NULL) {
                rev->addFirst(temp->data);
                temp = temp->next;
            }
            this->clearList();
            head = rev->head;
        }
    }

    ~SingleLinkedList() {
        clearList();
    }
};

/*

    ADD main() 
    OR 
    INCLUDE TO USE SingleLinkedList

*/