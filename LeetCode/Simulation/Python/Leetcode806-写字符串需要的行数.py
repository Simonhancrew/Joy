class Solution:
    def numberOfLines(self, widths: List[int], s: str) -> List[int]:
        cnt, line = 0, 1
        for x in s:
            t = widths[ord(x) - ord('a')]
            cnt += t
            if cnt > 100:
                cnt, line = t, line + 1
        return [line, cnt]
