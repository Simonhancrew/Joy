class Node:
    def __init__(self,val):
        self.val = val
        self.next = None
        self.prev = None

class MyLinkedList:

    def __init__(self):
        self.dummy = Node(-1)
        self.tail = Node(-1)    
        self.size = 0
        self.dummy.next = self.tail
        self.tail.prev = self.dummy

    def get(self, index: int) -> int:
        if index >= self.size or index < 0: return -1
        t = self.dummy
        while index >= 0:
            t = t.next
            index -= 1
        return t.val

    def addAtHead(self, val: int) -> None:
        t = Node(val)
        t.next = self.dummy.next
        t.prev = self.dummy
        self.dummy.next.prev = t
        self.dummy.next = t
        self.size += 1

    def addAtTail(self, val: int) -> None:
        t = Node(val)
        t.next = self.tail
        t.prev = self.tail.prev 
        self.tail.prev.next = t
        self.tail.prev = t
        self.size += 1

    def addAtIndex(self, index: int, val: int) -> None:
        if index > self.size: return
        if index == self.size: 
            self.addAtTail(val)
            return
        if index < 0: 
            self.addAtHead(val)
            return
        t = self.dummy
        while index > 0:
            t = t.next
            index -= 1
        node = Node(val)
        node.next = t.next
        node.prev = t
        t.next.prev = node
        t.next = node
        self.size += 1

    def deleteAtIndex(self, index: int) -> None:
        if index < 0 or index >= self.size:
            return
        t = self.dummy
        while index >= 0:
            t = t.next
            index -= 1
        pre,ne = t.prev,t.next
        pre.next = ne
        ne.prev = pre
        self.size -= 1


# Your MyLinkedList object will be instantiated and called as such:
# obj = MyLinkedList()
# param_1 = obj.get(index)
# obj.addAtHead(val)
# obj.addAtTail(val)
# obj.addAtIndex(index,val)
# obj.deleteAtIndex(index)
