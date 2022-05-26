class Solution:
    def fallingSquares(self, positions: List[List[int]]) -> List[int]:
        n = len(positions)
        ans = [0] * n
        for i in range(n):
            l1,r1 = positions[i][0],positions[i][1] + positions[i][0] - 1
            ans[i] = positions[i][1]
            for j in range(i):
                l2,r2 = positions[j][0],positions[j][1] + positions[j][0] - 1
                if r1 >= l2 and r2 >= l1:
                    ans[i] = max(ans[i],ans[j] + positions[i][1])
        for i in range(1,n):
            ans[i] = max(ans[i],ans[i - 1])
        return ans