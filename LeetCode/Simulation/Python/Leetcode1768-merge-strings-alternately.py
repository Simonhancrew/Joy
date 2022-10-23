class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        n, ans = min(len(word1), len(word2)), []
        for i in range(n):
            ans.append(word1[i])
            ans.append(word2[i])
        if n != len(word1): ans.append(word1[n:])
        if n != len(word2): ans.append(word2[n:])
        return ''.join(ans)