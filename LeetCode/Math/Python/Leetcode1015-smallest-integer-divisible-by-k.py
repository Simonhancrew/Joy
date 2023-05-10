class Solution:
    def smallestRepunitDivByK(self, k: int) -> int:
        if k == 1: return 1
        st, length = [False] * k, 1
        num = 1
        while True:
            num = (num * 10 + 1) % k
            length += 1
            if num == 0: return length
            elif st[num]: break
            st[num] = True
        return -1