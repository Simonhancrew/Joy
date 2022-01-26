class Solution:
    def scheduleCourse(self, courses: List[List[int]]) -> int:
        q = []
        courses.sort(key=lambda cs : cs[1])
        tot = 0
        for cs in courses:
            tot += cs[0]
            heapq.heappush(q,-1 * cs[0])
            if tot > cs[1]:
                t = heapq.heappop(q)
                tot += t
        return len(q)