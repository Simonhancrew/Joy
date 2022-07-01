class Solution:
    def diffWaysToCompute(self, expression: str) -> List[int]:
        res,n = [],len(expression)
        for i in range(n):
            if not expression[i].isdigit():
                left = self.diffWaysToCompute(expression[:i])
                right = self.diffWaysToCompute(expression[i + 1:])
                for lhs in left:
                    for rhs in right:
                        if expression[i] == '+':
                            res.append(lhs + rhs)
                        elif expression[i] == '-':
                            res.append(lhs - rhs)
                        else:
                            res.append(lhs * rhs)
        if not res:
            res.append(int(expression))
        return res
