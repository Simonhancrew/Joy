class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        int n = s.size();
        for(int i = 0;i < n;i += k) {
            string t;
            t = s.substr(i,k);
            while(t.size() < k) t += fill;
            ans.push_back(t);
        }
        return ans;
    }
};