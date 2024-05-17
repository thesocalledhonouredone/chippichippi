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
        pass


    

a = SingleLinkedList(100)
a.addStart(200)
a.addStart(300)
a.printList()
