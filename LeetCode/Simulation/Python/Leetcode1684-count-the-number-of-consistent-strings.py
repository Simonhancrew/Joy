class Solution:
    def countConsistentStrings(self, allowed: str, words: List[str]) -> int:
        ans, mask = 0, 0
        for c in allowed:
            mask |= 1 << (ord(c) - ord('a'))
        for word in words:
            cur = 0
            for c in word:
                cur |= 1 << (ord(c) - ord('a'))
            ans += (mask | cur) == mask
        return ans
