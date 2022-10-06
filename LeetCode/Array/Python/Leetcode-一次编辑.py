class Solution:
    def oneEditAway(self, first: str, second: str) -> bool:
        n, m = len(first), len(second)
        if abs(n - m) > 1: return False
        if n > m:
            first, second = second, first
            n, m = m, n
        i, j, cnt = 0, 0, 0
        while i < n and j < m and cnt <= 1:
            if first[i] == second[j]:
                i, j = i + 1, j + 1
            else:
                if n == m:
                    i, j, cnt = i + 1, j + 1, cnt + 1
                else:
                    j, cnt = j + 1, cnt + 1
        return cnt <= 1
