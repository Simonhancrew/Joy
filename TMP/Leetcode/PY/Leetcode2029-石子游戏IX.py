class Solution:
    def stoneGameIX(self, stones: List[int]) -> bool:
        cnt = [0] * 3
        for st in stones: cnt[st % 3] += 1
        if cnt[0] % 2 == 0: return cnt[1] >= 1 and cnt[2] >= 1
        return abs(cnt[1] - cnt[2]) > 2