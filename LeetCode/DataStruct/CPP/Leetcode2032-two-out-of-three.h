#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        unordered_map<int, int> mp;
        for (auto x : nums1) {
            mp[x] |= 1;
        }
        for (auto x : nums2) {
            mp[x] |= (1 << 1);
        }
        for (auto x : nums3) {
            mp[x] |= (1 << 2);
        }
        vector<int> ans;
        for (auto &[k, v] : mp) {
            if (v & (v - 1)) {
                ans.push_back(k);
            }
        }
        return ans;
    }
};
