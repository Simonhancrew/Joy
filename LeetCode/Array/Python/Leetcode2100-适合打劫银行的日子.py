class Solution:
    def goodDaysToRobBank(self, security: List[int], time: int) -> List[int]:
        n, cnt = len(security), 0
        l, r, ans = [0] * n, [0] * n, []
        for i in range(1, n):
            if security[i] <= security[i - 1]: cnt += 1
            else: cnt = 0
            l[i] = cnt
        cnt = 0
        for i in range(n - 2, -1, -1):
            if security[i] <= security[i + 1]: cnt += 1
            else: cnt = 0
            r[i] = cnt
        for i in range(n):
            if l[i] >= time and r[i] >= time: ans.append(i)
        return ans
