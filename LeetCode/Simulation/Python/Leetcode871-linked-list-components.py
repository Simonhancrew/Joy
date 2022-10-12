class Solution:
    def numComponents(self, head: Optional[ListNode], nums: List[int]) -> int:
        st = set(nums)
        inset, res = False, 0
        while head:
            if head.val in st:
                if not inset:
                    inset = True
                    res += 1
            else:
                inset = False
            head = head.next
        return res