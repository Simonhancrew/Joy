class Solution:
    def calPoints(self, ops: List[str]) -> int:
        rec,ans = [],0
        for op in ops:
            if op[0] == 'D':
                ans += rec[-1] * 2
                rec.append(rec[-1] * 2)
            elif op[0] =='+':
                ans += rec[-1] + rec[-2]
                rec.append(rec[-1] + rec[-2])
            elif op[0] == 'C':
                ans -= rec[-1]
                rec.pop()
            else:
                ans += int(op)
                rec.append(int(op))
        return ans
