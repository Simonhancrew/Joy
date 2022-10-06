class Solution:
    def platesBetweenCandles(self, s: str,
                             queries: List[List[int]]) -> List[int]:
        n = len(s)
        ans, pre, idx = [], [0] * (n + 1), []
        for i in range(1, n + 1):
            if s[i - 1] == '*':
                pre[i] = pre[i - 1] + 1
            else:
                pre[i] = pre[i - 1]
                idx.append(i - 1)
        if not idx: return [0] * len(queries)
        for a, b in queries:
            l, r = 0, len(idx) - 1
            while l < r:
                mid = l + r >> 1
                if idx[mid] >= a: r = mid
                else: l = mid + 1
            ll = l
            l, r = 0, len(idx) - 1
            while l < r:
                mid = l + r + 1 >> 1
                if idx[mid] <= b: l = mid
                else: r = mid - 1
            rr = l
            if rr < ll: ans.append(0)
            else: ans.append(pre[idx[rr]] - pre[idx[ll]])

        return ans
