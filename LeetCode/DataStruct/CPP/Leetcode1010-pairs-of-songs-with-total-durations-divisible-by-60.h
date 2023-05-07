class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int, int> mp;
        int res = 0;
        for (const auto x : time) {
            int y = x % 60;
            int tar = (60 - y) % 60;
            res += mp[tar];
            mp[y]++;
        }
        return res;
    }
};
