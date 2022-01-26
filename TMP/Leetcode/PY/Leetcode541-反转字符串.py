class Solution:
    def reverseStr(self, s: str, k: int) -> str:
        n,it= len(s),0
        s = list(s)
        def rev(l,r):
            while l < r:
                s[l],s[r] = s[r],s[l]
                l += 1
                r -= 1
        while it < n:
            ed = it + k - 1
            if ed < n:
                rev(it,ed)
            else:
                rev(it,n - 1)
            it = it + 2 * k
        return ''.join(s)