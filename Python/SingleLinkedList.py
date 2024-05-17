class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class SingleLinkedList:
    def __init__(self, data):
        self.head = Node(data)
        
    def printList(self):
        temp = self.head
        while temp != None:
            print(temp.data)
            temp = temp.next
        print("END OF LIST")

    def addStart(self, data):
        newNode = Node(data)
        newNode.next = self.head
        self.head = newNode

    def addLast(self, data):
        temp = self.head
        while temp.next != None:
            temp = temp.next
        newNode = Node(data)
        temp.next = newNode

    def 

    

a = SingleLinkedList(100)
a.addStart(200)
a.addStart(300)
a.addLast(10)
a.addLast(20)
a.printList()
