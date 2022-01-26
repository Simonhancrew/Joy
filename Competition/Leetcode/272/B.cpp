class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string res;
        int cnt = 0;
        unordered_map<int,int> st;
        for(auto idx : spaces) {
            st[idx] = 1;
        }
        for(int i = 0;i < s.size();i++){
            if(st.count(i)) res += ' ';
            res += s[i];
        }
        return res;
    }
};