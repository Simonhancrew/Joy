class Solution:
    def customSortString(self, order: str, s: str) -> str:
        pa = [26] * 26
        for i in range(len(order)):
            pa[ord(order[i]) - ord('a')] = i
        s = list(s)
        s.sort(key = lambda x : pa[ord(x) - ord('a')])
        return ''.join(s)