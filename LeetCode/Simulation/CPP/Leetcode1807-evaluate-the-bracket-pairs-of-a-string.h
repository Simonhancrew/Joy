class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mp;
        for (auto& s : knowledge) {
            mp[s[0]] = s[1];
        }
        int n = s.size();
        string res;
        for (int i = 0;i < n;i++) {
            if (s[i] != '(') res += s[i];
            else {
                int j = i + 1;
                while (j < n && s[j] != ')') j++;
                auto tmp = s.substr(i + 1, j - i - 1);
                if (mp.count(tmp)) {
                    res += mp[tmp];
                } else {
                    res += "?";
                }
                i = j;
            }
        }
        return res;
    }
};
