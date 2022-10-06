class Solution:
    def nearestPalindromic(self, n: str) -> str:
        length = len(n)
        st = [10**(length - 1) - 1, 10**length + 1]
        m = int(n[:(length + 1) // 2])
        for i in range(m - 1, m + 2):
            a = str(i)
            b = a[::-1]
            if length % 2 == 0: st.append(int(a + b))
            else: st.append(int(a + b[1:]))

        res = int(2e18)
        _n = int(n)
        for s in st:
            if s == _n: continue
            if abs(s - int(n)) < abs(res - int(n)):
                res = s
        return str(res)
