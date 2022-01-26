class Node:
    def __init__(self,key = 0,val = 0):
        self.pre = None
        self.ne = None
        self.val = val
        self.key = key

class LRUCache:

    def __init__(self, capacity: int):
        self.mp = dict()
        self.cap = capacity
        self.size = 0
        self.head= Node()
        self.tail = Node()
        
        self.head.ne = self.tail
        self.tail.pre = self.head

    def get(self, key: int) -> int:
        if key not in self.mp:
            return -1
        node = self.mp[key]
        self.move(node)
        return node.val
            
    def remove(self,node):
        pre,ne = node.pre,node.ne
        pre.ne = ne
        ne.pre = pre
    
    def move(self,node):
        self.remove(node)
        self.add(node)

    def add(self,node):
        node.pre = self.head
        node.ne = self.head.ne
        self.head.ne.pre = node
        self.head.ne = node

    def put(self, key: int, value: int) -> None:
        if key not in self.mp:
            node = Node(key,value)
            self.mp[key] = node
            self.add(node)
            self.size += 1
            if self.size > self.cap:
                rm = self.removet()
                del self.mp[rm.key]
                self.size -= 1
        else:
            node = self.mp[key]
            node.val = value
            self.move(node)
            
    def removet(self):
        node = self.tail.pre
        self.tail.pre = node.pre
        node.pre.ne = self.tail
        return node