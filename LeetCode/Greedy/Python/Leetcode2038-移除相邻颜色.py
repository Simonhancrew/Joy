class Solution:
    def winnerOfGame(self, colors: str) -> bool:
        f, cur, cnt = [0, 0], 'C', 1
        for c in colors:
            if c != cur:
                cur = c
                cnt = 1
            else:
                cnt += 1
                if cnt >= 3:
                    f[ord(cur) - ord('A')] += 1
        return f[0] > f[1]
