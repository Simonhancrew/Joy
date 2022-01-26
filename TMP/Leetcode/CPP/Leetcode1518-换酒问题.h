#if 0
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int res = 0;
        while(numBottles >= numExchange) {
            res += numExchange;
            numBottles -= numExchange;
            numBottles += 1;
        }
        res += numBottles;
        return res; 
    }
};
#endif

// b瓶酒，e瓶能换。实质上每次喝完e瓶酒，损失的瓶子数为e-1
/*
    不难假设出一个能换酒的上限公式为
    b - n(e-1) >= e
    b - n(e-1) < e的时候就不能换了
    n的下限
    n > (b - e) / (e - 1)=> n >= (_) + 1
    考虑边界b >= e
*/ 

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        return numBottles >= numExchange ? (numBottles - numExchange) / (numExchange - 1) + 1 + numBottles : numBottles;
    }
};