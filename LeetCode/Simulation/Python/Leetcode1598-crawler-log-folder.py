class Solution:
    def minOperations(self, logs: List[str]) -> int:
        stp, n = 0, len(logs)
        for i in range(n):
            if logs[i] == './' or (logs[i] == '../' and stp == 0): continue
            if logs[i] == '../': stp -= 1
            else: stp += 1
        return stp