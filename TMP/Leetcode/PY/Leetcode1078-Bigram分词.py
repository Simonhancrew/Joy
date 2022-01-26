class Solution:
    def findOcurrences(self, text: str, first: str, second: str) -> List[str]:
        rec = text.split()
        ans = []
        for i in range(len(rec)):
            if rec[i] == first and i + 2 < len(rec):
                if rec[i + 1] == second: ans.append(rec[i + 2])
        return ans