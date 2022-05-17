class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char,int> mp;
        for(int i = 0;i < order.size();i++) mp[order[i]] = i;
        for(int i = 1;i < words.size();i++) {
            auto &l = words[i - 1],&r = words[i];
            int x = 0,y = 0;
            while(x < l.size() && y < r.size()) {
                if(mp[l[x]] > mp[r[y]]) return false;
                if(mp[l[x]] < mp[r[y]]) break;
                ++x,++y;
            }
            if(x < l.size() && y == r.size()) return false;
        } 
        return true;
    }
};