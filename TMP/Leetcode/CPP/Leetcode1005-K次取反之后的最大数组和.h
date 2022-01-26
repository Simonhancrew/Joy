#include <vector>
#include <algorithm>
using namespace std;
//首先把负的变成正的，优先变绝对值大的
//然后如果K还有的话，就等价于在全正数的序列中改变
//K = 奇数时必须变一位，就变绝对值最小的，偶数就不变
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int mn = INT_MAX;
        for(auto num : nums) mp[num]++,mn = min(mn,abs(num));
        for(int i = -100;i < 0 && k;i++){
            while(mp.count(i) && mp[i] && k){
                mp[i]--;
                mp[-i]++;
                k--;
            }
        }
        int res = 0;
        for(int i = -100;i <= 100;i++){
            if(mp.count(i) && mp[i]) res += mp[i] * i;
        }
        if(k & 1) res -= 2 * mn;
        return res;
    }
};