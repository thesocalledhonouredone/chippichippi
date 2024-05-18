class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class SingleLinkedList:
    def __init__(self, data):
        self.head = Node(data)
        self.length = 1
        
    def checkEmpty(self) -> bool: #helper function to check if list is empty
        if self.head == None:
            return True
        else:
            False
    
    def printList(self) -> None: #function to print the list
        if self.checkEmpty():
            print("THE LIST IS EMPTY")
        else:
            temp = self.head
            while temp != None:
                print(temp.data)
                temp = temp.next
            print("END OF LIST")

    def addFirst(self, data) -> None: #function to add Node at the stat of the list
        if self.checkEmpty():
            print("THE LIST IS EMPTY")
        else:
            newNode = Node(data)
            newNode.next = self.head
            self.head = newNode
            
            self.length += 1

    def addLast(self, data) -> None: #function to add Node at the end of the list
        if self.checkEmpty():
            print("THE LIST IS EMPTY")
        else:
            temp = self.head
            while temp.next != None:
                temp = temp.next
            newNode = Node(data)
            temp.next = newNode
            
            self.length += 1

    def deleteFirst(self) -> None: #function to delete Node at the start of the list
        if self.checkEmpty():
            print("THE LIST IS EMPTY")
        else:
            temp = self.head
            self.head = temp.next
            del temp

            self.length -= 1

    def deleteLast(self) -> None: #function to delete Node at the end of the list
        if self.checkEmpty():
            print("THE LIST IS EMPTY")
        else:
            temp = self.head
            shadow = None
            while temp.next != None:
                shadow = temp
                temp = temp.next
            shadow.next = None
            del temp

            self.length -= 1

    def join(self, list) -> None: #function to join two lists
        if self.checkEmpty() or list.checkEmpty():
            print("THE LIST IS EMPTY")
        else:
            temp = self.head
            while temp.next != None:
                temp = temp.next
            temp.next = list.head

            self.length += list.lenght