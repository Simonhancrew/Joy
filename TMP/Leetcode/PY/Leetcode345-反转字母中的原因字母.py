class Solution:
    def reverseVowels(self, s: str) -> str:
        op = 'aeiouAEIOU'
        i,j = 0,len(s) - 1
        s = list(s)
        while i < j:
            while i < j and not (s[i] in op):
                i += 1
            while i < j and not (s[j] in op):
                j -= 1
            if i < j:
                s[i],s[j] = s[j],s[i]
                i += 1
                j -= 1
        return ''.join(s)