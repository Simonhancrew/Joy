class Solution {
public:
    bool check(unordered_map<char,int>& mp,unordered_map<char,int> &st){
        for(auto [k,v] : mp){
            if(st[k] < v) return false;
        }
        return true;
    }

    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        unordered_map<char,int> mp;
        for(auto c : licensePlate) {
            if(c == ' ' || isdigit(c)) continue;
            mp[tolower(c)]++;
        }
        string res;
        for(auto& str : words){
            unordered_map<char,int> st;
            for(auto ch : str){
                st[ch]++;
            }
            if(check(mp,st)) {
                if(res.empty() || res.size() > str.size()) {
                    res = str;
                }
            }
        }
        return res;
    }
};