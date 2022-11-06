class Solution:
    def interpret(self, s: str) -> str:
        res,i, n = [], 0, len(s)
        while i < n:
            if s[i] == 'G': res.append(s[i])
            else:
                j = i
                while s[j] != ')': j += 1
                if j - i <= 1: res.append('o')
                else: res.append('al')
                i = j
            i += 1
        return ''.join(res)