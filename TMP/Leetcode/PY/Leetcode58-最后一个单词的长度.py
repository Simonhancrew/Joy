class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        s = list(s.split())
        return len(s[-1])