class Solution:
    def validSquare(self, p1: List[int], p2: List[int], p3: List[int], p4: List[int]) -> bool:
        p = [p1,p2,p3,p4]
        d = []
        def calcu(a,b):
            dx,dy = a[0] - b[0],a[1] - b[1]
            return dx * dx + dy * dy
     
        for i in range(4):
            for j in range(i + 1,4):
                d.append(calcu(p[i],p[j]))
        d.sort()
        if not d[0]: return False 
        return d[0] == d[1] and d[0] == d[2] and d[0] == d[3] and d[4] == d[5]