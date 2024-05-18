class Node:
    def __init__(self, data) -> None:
        self.data = data
        self.prev = None
        self.next = None

class DoubleLinkedList:
    def __init__(self, data) -> None:
        self.head = Node(data)
        self.length = 1

    def checkEmpty(self) -> bool: # helper method check if the list is empty
        if self.head is None:
            return True
        else:
            return False
    
    def addFirst(self, data) -> None: # method to add Node at start
        if self.checkEmpty():
            self.head = Node(data)
        else:
            # create new Node
            newNode = Node(data)
            # make newNode next as head of list
            # make the head of the list as newNode
            newNode.next = self.head
            self.head = newNode

            self.length += 1
    
    def addLast(self, data) -> None: # method to add Node at end
        if self.checkEmpty():
            self.head = Node(data)
        else:
            temp = self.head
            # traverse the list until last Node of list
            while temp.next != None:
                temp = temp.next
            # create newNode
            # set newNode prev as last node of list
            # set last node of list next as newNode
            newNode = Node(data)
            newNode.prev = temp
            temp.next = newNode

            self.length += 1

    def printForward(self) -> None: # method to print list in forward direction
        if self.checkEmpty():
            print("LIST IS EMPTY")
        else:
            temp = self.head
            while temp != None:
                print(temp.data)
                temp = temp.next
            print("END OF LIST")

    def printBackward(self) -> None: # method to print list in backward direction
        if self.checkEmpty():
            print("LIST IS EMPTY")
        else:
            temp = self.head
            # traverse till last node of list
            while temp.next != None:
                temp = temp.next
            # from last node of list, traverse backward using 'prev'
            while temp != None:
                print(temp.data)
                temp = temp.prev
            print("END OF LIST")

    def deleteFirst(self) -> None: # method to delete Node at start of list
        if self.checkEmpty():
            print("LIST IS EMPTY")
        else:
            temp = self.head
            # setting second node prev as None, so it does not refrence deleted Node
            temp.next.prev = None
            # updating head to next node
            self.head = temp.next
            # deleting previous head
            del temp

            self.length -= 1

    def deleteLast(self) -> None: # method to delete Node at end of list
        if self.checkEmpty():
            print("LIST IS EMPTY")
        else:
            temp = self.head
            # create a 'shadow' to keep track of second-last Node
            shadow = None
            # traverse until last Node
            while temp.next != None:
                # shadow will hold the Node of 'temp' before the update
                shadow = temp
                # update temp
                temp = temp.next
            shadow.next = None
            del temp
            
    def searchList(self, target) -> bool: # method to check if target is present in the list
        if self.checkEmpty():
            print("LIST IS EMPTY")
            return False
        else:
            temp = self.head
            while temp != None:
                if temp.data == target:
                    return True
                temp = temp.next
            return False
        
    def get(self, index) -> int: # method to return data at 'index'
        if self.checkEmpty():
            print("LIST IS EMPTY")
            return None
        else:
            if index >= self.length:
                return None
            else:
                temp = self.head
                num = 0

                while temp != None:
                    if num == index:
                        return temp.data
                    temp = temp.next
                    num += 1

    def indexOf(self, target) -> int: # method return index of 'target'
        if self.checkEmpty():
            print("LIST IS EMPTY")
        else:
            temp = self.head
            index = 0
            while temp != None:
                if temp.data == target:
                    return index
                index += 1
                temp = temp.next
            return None

    def join(self, list) -> None: # method to join to lists
        if self.checkEmpty() or list.checkEmpty():
            print("LIST IS EMPTY")
        else:
            temp = self.head
            while temp.next != None:
                temp = temp.next
            # set the 'head prev' of the list to be joined to the last node in list
            # set last node 'next' to list to be joined 'head'
            list.head.prev = temp
            temp.next = list.head

    def clearList(self) -> None:
        if self.checkEmpty():
            print("LIST IS ALREADY CLEAR")
        else:
            self.head = None