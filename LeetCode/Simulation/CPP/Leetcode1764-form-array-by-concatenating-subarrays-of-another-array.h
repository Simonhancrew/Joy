class Solution {
public:
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        int j = 0, n = nums.size();
        auto check = [&](const vector<int>&  arr, int idx) {
            if (n - idx + 1 < arr.size()) return false;
            for(int i = 0, j = idx;i < arr.size();i++, j++) {
                if (arr[i] != nums[j]) return false;
            }
            return true;
        };
        for(int i = 0;i < n && j < groups.size();i++) {
            if (groups[j][0] != nums[i]) continue;
            if (check(groups[j], i)) {
                i += groups[j].size() - 1;
                j++;
            }
        }
        return j == groups.size();
    }
};
