#include <queue>
#include <vector>

using namespace std;

// 利用一个最小堆来维护序列中下一个最小的数。思路还是来自之前丑数的dp.
// 因为下一个数只能乘primes中的数，找到最小的不重复的就可以了。

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int dp[n];
        memset(dp,0,sizeof dp);
        dp[0] = 1;
        typedef pair<int,int> PII;
        priority_queue<PII,vector<PII>,greater<PII>> heap;
        for(int num:primes) heap.push({num,0});
        for(int i = 1;i < n;){
            auto t = heap.top();
            heap.pop();
            if(t.first != dp[i - 1]) dp[i++] =  t.first;
            int idx = t.second,prime = t.first / dp[idx];
            heap.push({prime * dp[idx + 1],idx + 1});
        }
        return dp[n - 1];
    }
};