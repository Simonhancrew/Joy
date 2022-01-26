#include <vector>
#include <unordered_map>

using namespace std;

// dp[i][j]，以nums[i]结尾，公差是j的，长度>=2的等差数列的个数
// 所以遍历i，j，k = nums[i] - nums[j],只要dp[j][k]存在，说明存在长度2的等差数列，当前找到了一个新的结尾
// 所以结果可以加一个dp[j][k]
// 之后可以更新dp[i][k] = dp[j][k] + 1(组合)

class Solution {
public:
    typedef long long LL;
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return 0;
        vector<unordered_map<LL,int>> dp(n);
        int res = 0;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < i;j++){
                LL k = (LL)nums[i] - nums[j];
                auto it = dp[j].find(k);
                int t = 0;
                if(it != dp[j].end()){
                    t = it->second;
                    res += t;
                }
                // 长度2的是1，+长度大于2的t
                dp[i][k] += t + 1;
            }
        }
        return res;
    }
};