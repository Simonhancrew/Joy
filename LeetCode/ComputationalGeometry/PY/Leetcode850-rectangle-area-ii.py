class Solution:
    def rectangleArea(self, rectangles: List[List[int]]) -> int:
        cox = []
        for rec in rectangles:
            cox.append(rec[0])
            cox.append(rec[2])
        cox.sort()
        n = len(cox)
        res = 0
        
        def calcu(recs,a,b):
            coy = []
            for rec in recs:
                if rec[0] <= a and rec[2] >= b:
                    coy.append([rec[1],rec[3]])
            coy.sort()
            res, st, ed = 0,-1,-1
            for y in coy:
                if y[0] > ed:
                    res += ed - st
                    st,ed = y[0],y[1]
                elif y[1] > ed:
                    ed = y[1]
            res += ed - st
            return res * (b - a)

        for i in range(1,n):
            res += calcu(rectangles,cox[i - 1],cox[i])
        return res % int(1e9 + 7)
