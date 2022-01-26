from typing import List


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def splitListToParts(self, head: ListNode, k: int) -> List[ListNode]:
        p,n = head,0
        while p:
            n += 1
            p = p.next
        p,ans = head,[]
        for i in range(k):
            base,mod = n // k,n % k
            if i + 1 <= mod:
                base += 1
            ans.append(p)
            for i in range(base - 1):
                p = p.next
            if p:
                q = p.next
                p.next = None
                p = q
        return ans