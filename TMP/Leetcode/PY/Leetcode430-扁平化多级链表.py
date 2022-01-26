class Node:
    def __init__(self, val, prev, next, child):
        self.val = val
        self.prev = prev
        self.next = next
        self.child = child

class Solution:
    def flatten(self, head: 'Node') -> 'Node':
        t = head
        while t:
            ne = t.next
            if t.child:
                t.next = self.flatten(t.child)
                t.child = None
                t.next.prev = t
                while t.next:
                    t = t.next
            t.next = ne
            if ne:
                ne.prev = t
            t = ne
        return head