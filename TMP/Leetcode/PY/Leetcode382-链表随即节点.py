class Solution:

    def __init__(self, head: Optional[ListNode]):
        self.node = []
        while head:
            self.node.append(head.val)
            head = head.next
    def getRandom(self) -> int:
        return self.node[randint(0,len(self.node) - 1)]