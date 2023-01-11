class Solution {
public:
    bool digitCount(string num) {
        vector<int> mp(10);
        for (auto c : num) {
            mp[c - '0']++;
        } 
        int n = num.size();
        for (int i = 0;i < n;i++) {
            int cnt = num[i] - '0';
            if (mp[i] != cnt) {
                return false;
            }
        }
        return true;
    }
};
