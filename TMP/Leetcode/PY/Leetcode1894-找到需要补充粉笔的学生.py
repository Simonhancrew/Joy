from typing import List

class Solution:
    def chalkReplacer(self, chalk: List[int], k: int) -> int:
        s = sum(chalk)
        k = k % s
        n,res = len(chalk),-1
        for i in range(n):
            if chalk[i] > k:
                res = i
                break
            else:
                k -= chalk[i]
        return res