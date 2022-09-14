class Solution:
    def trimMean(self, arr: List[int]) -> float:
        arr.sort()
        n = len(arr)
        acc = sum(arr[n // 20:(n * 19) // 20])
        return acc / (0.9 * n)
