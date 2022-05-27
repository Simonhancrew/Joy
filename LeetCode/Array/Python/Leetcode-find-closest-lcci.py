class Solution:
    def findClosest(self, words: List[str], word1: str, word2: str) -> int:
        n,l,r,ans = len(words),-1,-1,10 ** 5
        for i in range(n):
            if words[i] == word1: l = i
            if words[i] == word2: r = i
            if l >= 0 and r >= 0:
                ans = min(ans,abs(r - l))
        return ans