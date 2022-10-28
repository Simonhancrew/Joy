class Solution:
    def sumSubarrayMins(self, arr: List[int]) -> int:
        n = len(arr)
        l, r = [0] * n, [0] * n
        stk = []
        for i in range(n):
            while stk and arr[stk[-1]] > arr[i]:
                stk.pop()
            if not stk: l[i] = -1
            else: l[i] =  stk[-1]
            stk.append(i)
        stk = []
        for i in range(n - 1, -1, -1):
            while stk and arr[stk[-1]] >= arr[i]:
                stk.pop()
            if not stk: r[i] = n
            else: r[i] = stk[-1]
            stk.append(i)
        print(r)
        res, mod = 0, int(1e9) + 7
        for i in range(n):
            res = (res + arr[i] * (i - l[i]) * (r[i] - i)) % mod
        return res   
