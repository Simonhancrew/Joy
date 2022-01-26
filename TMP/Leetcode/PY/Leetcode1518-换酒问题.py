class Solution:
    def numWaterBottles(self, numBottles: int, numExchange: int) -> int:
        ans = (numBottles - numExchange) // (numExchange - 1) + 1 + numBottles if numBottles >= numExchange else numBottles
        return ans