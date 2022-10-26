// 单调队列带两个优化，很特殊。
// 首先求前缀和，单调队列存前缀和数组的下标。
// 尾部
// 假设前缀和数组的下标[i,j], 目前遍历到k, 如果k，s[k] >= s[h..j],
// 则k后面的数匹配[h..j]能成功，一定没有匹配k短，可以弹出
// 头部只要能匹配到k，则k后面匹配的也一定没有k优，也可以弹出 

class Solution {
public:
    using LL = long long;
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<LL> s(n + 1);
        for(int i = 1;i <= n;i++) s[i] = s[i - 1] + nums[i - 1];    
        deque<int> q;
        q.push_back(0);
        int res = INT_MAX;
        for(int i = 1;i <= n;i++) {
            while(q.size() && s[q.front()] + k <= s[i]) {
                res = min(res, i - q.front());
                q.pop_front();
            }
            while(q.size() && s[q.back()] >= s[i]) {
                q.pop_back();
            }
            q.push_back(i);
        }
        if(res == INT_MAX) return -1;
        return res;
    }
};