class Solution:
    def maxNumberOfBalloons(self, text: str) -> int:
        cnt = [0] * 5
        for t in text:
            if t == 'b': cnt[0] += 1
            elif t == 'a': cnt[1] += 1
            elif t == 'l': cnt[2] += 1
            elif t == 'o': cnt[3] += 1
            elif t == 'n': cnt[4] += 1
        cnt[2] //= 2
        cnt[3] //= 2
        return min(cnt)