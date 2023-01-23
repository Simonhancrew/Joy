class Solution:
    def calculateTax(self, brackets: List[List[int]], income: int) -> float:
        ans, pre = 0, 0
        for x in brackets:
            if income >= x[0]:
                ans += (x[0] - pre) * x[1] / 100
                pre = x[0]
            else:
                ans += (income - pre) * x[1] / 100
                break
        return ans