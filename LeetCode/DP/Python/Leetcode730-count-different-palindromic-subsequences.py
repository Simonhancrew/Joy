class Solution:
    def countPalindromicSubsequences(self, s: str) -> int:
        P,n = 10 ** 9 + 7,len(s)
        f = [[1] * (n + 1) for _ in range(n + 1)]
        for i in range(1,n + 1): f[i][i] += 1
        for length in range(2,n + 1):
            q = [deque() for _ in range(4)]
            for j in range(1,n + 1):
                q[ord(s[j - 1]) - ord('a')].append(j)
                i = j - length + 1
                if i >= 1:
                    for k in range(4):
                        while q[k] and q[k][0] < i: q[k].popleft()
                        if len(q[k]) > 0:
                            f[i][j] += 1
                            l,r = q[k][0],q[k][-1]
                            if l < r:
                                f[i][j] = (f[i][j] + f[l + 1][r - 1]) % P
        return (f[1][n] - 1 + P) % P