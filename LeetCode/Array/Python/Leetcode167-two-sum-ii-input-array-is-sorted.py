class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        n = len(numbers)
        i, j = 0, n - 1
        while i < j:
            tot = numbers[i] + numbers[j]
            if tot == target:
                break
            if tot > target:
                j -= 1
                continue
            if tot < target:
                i += 1
        return [i + 1, j + 1]