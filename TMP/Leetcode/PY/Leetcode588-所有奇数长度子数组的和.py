from typing import List
class Solution:
    def sumOddLengthSubarrays(self, arr: List[int]) -> int:
        arr = [0] + arr
        for i in range(1,len(arr)):
            arr[i] += arr[i - 1]
        res = 0
        for i in range(1,len(arr)):
            for j in range(i,len(arr)):
                if (j - i + 1) & 1:
                    res += arr[j] - arr[i - 1]

        return res
        