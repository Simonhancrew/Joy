class Solution:
    def visiblePoints(self, points: List[List[int]], angle: int, location: List[int]) -> int:
        degree = []
        st = 0
        for point in points:
            if location[0] == point[0] and location[1] == point[1]:
                st += 1
                continue
            dx,dy = point[0] - location[0],point[1] - location[1]
            dg = atan2(dy,dx)
            degree.append(dg)
        degree.sort()
        n = len(degree)
        for i in range(n):
            degree.append(degree[i] + 2 * pi)
        j = 0
        cnt = 0
        angle = angle *pi / 180
        for i in range(n):
            while j < len(degree) and degree[j] - degree[i] <= angle:
                j += 1
            cnt = max(cnt,j - i)
        return cnt + st