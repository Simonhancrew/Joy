class Solution:
    def canBeEqual(self, target: List[int], arr: List[int]) -> bool:
        arr.sort()
        target.sort()
        for i in range(len(arr)):
            if arr[i] != target[i]: return False
        return True
