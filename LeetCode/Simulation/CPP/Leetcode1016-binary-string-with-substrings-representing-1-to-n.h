class Solution {
public:
    bool queryString(string s, int n) {
        unordered_set<int> st;
        int m = s.size();
        for (int i = 0;i < m;i++) {
            int acc = 0;
            for (int j = i;j < m;j++) {
                acc = 2 * acc + s[j] - '0';
                if (acc > n) break;
                if (acc) st.insert(acc); 
            }
        }
        return st.size() == n;
    }
};
