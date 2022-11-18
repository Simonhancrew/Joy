#include <vector>

using namespace std;

class Solution {
public:
    const int P = 1e9 + 7;
    using LL = long long;
    int sumSubseqWidths(vector<int>& nums) {
        if(nums.size() < 2) return 0;
        int n = nums.size();
        vector<int> p(n + 1);
        p[0] = 1;
        for(int i = 1;i <= n;i++) p[i] = p[i - 1] * 2 % P;
        sort(nums.begin(), nums.end());
        int res = 0;
        for(int i = 0;i < n;i++) {
            res = (res + ((LL)nums[i] * p[i] - (LL)nums[i] * p[n - i - 1])) % P;
        }
        return res;
    }
};
