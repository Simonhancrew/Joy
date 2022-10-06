class Solution:
    def sumOfUnique(self, nums: List[int]) -> int:
        st, ans = [0] * 101, 0
        for num in nums:
            st[num] += 1
        for i in range(1, 101):
            if st[i] == 1: ans += i
        return ans
