class Solution:
    def finalPrices(self, prices: List[int]) -> List[int]:
        stk, n = [], len(prices)
        for i in range(n - 1, -1, -1):
            while stk and stk[-1] > prices[i]:
                stk.pop()
            t = prices[i]
            if stk: prices[i] -= stk[-1]
            stk.append(t)
        return prices
