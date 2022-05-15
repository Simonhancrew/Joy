class Solution:
    def largestTriangleArea(self, points: List[List[int]]) -> float:
        n,ans = len(points),-1
        for p in points:
            for p1 in points:
                for p2 in points:
                    x1,y1 = p[0],p[1]
                    x2,y2,x3,y3 = p1[0] - x1,p1[1] - y1,p2[0] - x1,p2[1] - y1
                    ans = max(ans,abs(x2 * y3 - x3 * y2) / 2)
        return ans
