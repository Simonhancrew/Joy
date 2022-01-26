class Solution:
    def findMinDifference(self, timePoints: List[str]) -> int:
        trans = []
        for s in timePoints:
            h,m = int(s[:2]),int(s[3:])
            trans.append(h * 60 + m)
        trans.sort()
        ans = int(1e9) + 7
        for i in range(len(trans) - 1):
            ans = min(ans,trans[i + 1] - trans[i])
        ans = min(ans,trans[0] + 1440 - trans[-1])
        return ans