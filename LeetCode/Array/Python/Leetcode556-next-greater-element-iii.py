class Solution:
    def nextGreaterElement(self, n: int) -> int:
        s = list(str(n))
        i = len(s) - 1
        while i != 0 and s[i - 1] >= s[i]:
            i -= 1
        if i == 0: return -1
        j = i
        while j + 1 < len(s) and s[j + 1] > s[i - 1]:
            j += 1
        s[j], s[i - 1] = s[i - 1], s[j]
        # print(s[i:],s[-1:i - 1:-1])
        s[i:] = s[-1:i - 1:-1]
        # print(1 << 30)
        if int(''.join(s)) > ((1 << 31) - 1): return -1
        return int(''.join(s))
