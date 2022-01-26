from typing import List
class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        lb = [0] * len(nums2)
        stk = []
        n,m = len(nums1),len(nums2)
        for i in range(m - 1,-1,-1):
            t = nums2[i]
            while stk and t >= stk[-1]: stk.pop()
            if not stk: lb[i] = -1
            else: lb[i] = stk[-1]
            stk.append(t)
        mp = dict()
        for i in range(m):
            mp[nums2[i]] = i
        ans = [0] * n
        for i in range(n):
            ans[i] = lb[mp[nums1[i]]]
        return ans