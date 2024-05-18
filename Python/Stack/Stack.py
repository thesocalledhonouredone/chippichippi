class Node:
    def __init__(self, data) -> None:
        self.data = data
        self.next = None

class Stack:
    def __init__(self, data) -> None:
        self.top = Node(data)
        self.size = 1
    
    def isEmpty(self) -> bool: # method to check if stack is empty:
        return self.top is None

    def push(self, data) -> None: # method to push 'data' into stack
        newNode = Node(data)
        if self.isEmpty():
            self.top = newNode
        else:
            newNode.next = self.top
            self.top = newNode
            self.size += 1
    
    def pop(self) -> int: # method to pop and return popped top element
        if self.isEmpty():
            print("STACK IS EMPTY")
        else:
            temp = self.top
            popped = temp.data
            self.top = temp.next
            del temp
            self.size -= 1
            return popped
    
    def pops(self, times) -> list: # method to perform multiple pops, returns list of popped items
        if self.isEmpty():
            print("STACK IS EMPTY")
        else:
            arr = list()
            for i in range(times):
                arr.append(self.pop())

            self.size -= times
            return arr

    def items(self) -> None: # method to view all the items of the stack
        if self.isEmpty():
            print("STACK IS EMPTY")
        else:
            temp = self.top
            while temp != None:
                print(temp.data)
                temp = temp.next
            print()

    def peek(self) -> int: # method to return value at 'top' of stack
        return self.top.data

    def pushArray(self, arr) -> None: # method to push array elements into stack
        for i in arr:
            self.push(i)
        self.size += len(arr)

    def contains(self, target) -> bool: # method to check if 'target' is in the stack
        if self.isEmpty():
            print("STACK IS EMPTY")
            return None
        else:
            temp = self.top
            while temp != None:
                if temp.data == target:
                    return True
                temp = temp.next
            return False