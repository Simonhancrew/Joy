
maxlevel = 8

class Node:

    def __init__(self,val):
        self.val =  val
        self.next = [None] * maxlevel  

class Skiplist:

    def __init__(self):
        self.head = Node(-1)

    def find(self,target):
        pre = [None] * maxlevel 
        p = self.head
        for i in range(maxlevel - 1, -1,-1):
            while p.next[i] and p.next[i].val < target:
                p = p.next[i]
            pre[i] = p
        return pre

    def search(self, target: int) -> bool:
        pre = self.find(target)
        p = pre[0].next[0]
        return p != None and p.val == target

    def add(self, num: int) -> None:
        # pass
        pre = self.find(num)
        p = Node(num)
        for i in range(0,maxlevel):
            p.next[i] = pre[i].next[i]
            pre[i].next[i] = p
            if randint(0,1) == 1: break

    def erase(self, num: int) -> bool:
        pre = self.find(num)
        p = pre[0].next[0]
        if not p or p.val != num: return False
        i = 0
        while i < maxlevel and pre[i].next[i] == p:
            pre[i].next[i] = p.next[i]
            i += 1

        return True