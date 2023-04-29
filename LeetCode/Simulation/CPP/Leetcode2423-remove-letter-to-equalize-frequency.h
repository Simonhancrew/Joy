class Solution {
public:
    bool equalFrequency(string word) {
        int n = word.size();
        for (int i = 0;i < n;i++) {
            string s = word.substr(0, i) + word.substr(i + 1);
            unordered_map<char, int> mp;
            for (const auto c : s) mp[c]++;
            int bv = -1;
            bool flag = true;
            for (const auto [k, v] : mp) {
                if (bv == -1) bv = v;
                if (bv != v) {
                    flag = false;
                    break;
                }
                bv = v;
            }
            if (flag) return true;
        }
        return false;
    }
};