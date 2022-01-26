class Solution {
public:
    Solution(vector<int>& nums) {
        memo = nums;
    }
    
    vector<int> reset() {
        return memo;
    }
    
    vector<int> shuffle() {
        auto cp = memo;
        random_device r;
        std::default_random_engine gen(r());
        int n = cp.size();
        for(int i = 0;i < n;i++){
            uniform_int_distribution<int> dis(0,n - i - 1);
            swap(cp[i],cp[i + dis(gen)]);
        }
        return cp;
    }
    vector<int> memo;
};
