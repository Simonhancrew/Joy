class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.size() != goal.size()) return false;
        if(s == goal) {
            unordered_map<char,int> mp;
            for(auto ch : s){
                mp[ch]++;
                if(mp[ch] > 1) return true;
            }
            return false;
        }
        vector<int> idx;
        for(int i = 0;i < s.size();i++){
            if(s[i] != goal[i]) idx.push_back(i);
        }
        if(idx.size() != 2) return false;
        int x = idx[0],y = idx[1];
        return s[x] == goal[y] && s[y] == goal[x];
    }
};