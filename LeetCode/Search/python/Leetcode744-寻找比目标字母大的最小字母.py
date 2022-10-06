class Solution:
    def nextGreatestLetter(self, letters: List[str], target: str) -> str:
        letters.sort()
        l, r = 0, len(letters) - 1
        while l < r:
            mid = l + r + 1 >> 1
            if letters[mid] <= target: l = mid
            else: r = mid - 1
        if letters[r] <= target: r += 1
        if r == len(letters): r = 0
        return letters[r]
