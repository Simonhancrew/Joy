class Solution:
    def findKthNumber(self, n: int, k: int) -> int:
        pre = 1

        def get(pre, n):
            a, b = str(n), str(pre)
            d = len(a) - len(b)
            res, p = 0, 1
            for i in range(d):
                res += p
                p *= 10
            if a[0:len(b)] == b: res += n - pre * p + 1
            elif a[0:len(b)] > b: res += p
            return res

        while k > 1:
            cnt = get(pre, n)
            if k > cnt:
                k -= cnt
                pre += 1
            else:
                k -= 1
                pre *= 10
        return pre
