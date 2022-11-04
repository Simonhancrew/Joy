class Solution:
    def reachNumber(self, target: int) -> int:
        cnt, acc = 0, 0
        target = abs(target)
        while acc < target or (acc - target) & 1: 
            cnt += 1
            acc += cnt
        return cnt
