class Solution:
    def grayCode(self, n: int) -> List[int]:
        ans = [0]
        for i in range(n):
            t = len(ans)
            for j in range(t - 1,-1,-1):
                ans[j] *= 2
                ans.append(ans[j] + 1)
        return ans