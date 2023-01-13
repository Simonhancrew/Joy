class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        unordered_map<char, int> pa, mp;
        for (auto c : target) {
            pa[c]++;
        }
        for (auto c : s) {
            if (pa.count(c)) {
                mp[c]++;
            }
        }
        int ans = 0;
        auto check = [&pa, &mp]() {
            for (const auto& [k,v] : pa) {
                if (mp[k] < v) {
                    return false;
                }
            } 
            return true;
        };
        auto remove = [&pa, &mp]() {
            for (auto &[k, v] : mp) {
                v -= pa[k];
            }
        };
        while (check()) {
            ans++;
            remove();
        }
        return ans;
    }
};
