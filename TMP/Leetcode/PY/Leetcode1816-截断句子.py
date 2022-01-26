class Solution:
    def truncateSentence(self, s: str, k: int) -> str:
        arr = s.split()
        arr = arr[:k]
        return ' '.join(arr)