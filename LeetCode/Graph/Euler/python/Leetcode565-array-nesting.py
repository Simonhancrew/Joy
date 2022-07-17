class Solution:
    def arrayNesting(self, nums: List[int]) -> int:
        n,ans = len(nums),0
        for i in range(n):
            if nums[i] == -1:  continue
            cur,ne = 0,i
            while nums[ne] != -1:
                cur += 1
                t = ne
                ne = nums[ne]
                nums[t] = -1
            ans = max(cur,ans)
        return ans