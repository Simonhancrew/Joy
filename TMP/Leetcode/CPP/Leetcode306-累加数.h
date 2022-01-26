class Solution {
public:
    int n;
    string s;
    vector<vector<int>> rec;
    bool isAdditiveNumber(string num) {
        n = num.size(),s = num;
        return dfs(0);
    }
     
    bool dfs(int u){
        int cnt = rec.size();
        if(u == n) return cnt >= 3;
        int rhs = s[u] == '0' ? u + 1 : n;
        vector<int> cur;
        for(int i = u;i < rhs;i++){
            cur.push_back(s[i] - '0');
            if(cnt < 2 || check(rec[cnt - 2],rec[cnt - 1],cur)) {
                rec.push_back(cur);
                if(dfs(i + 1)) return true;
                rec.pop_back();
            }
        }
        return false;
    }
    bool check(vector<int> l,vector<int> r,vector<int> res){
        reverse(l.begin(),l.end()),reverse(r.begin(),r.end());
        reverse(res.begin(),res.end());
        int carry = 0;
        vector<int> arr;
        for(int i = 0;i < l.size() || i < r.size();i++){
            if(i < l.size()) carry += l[i];
            if(i < r.size()) carry += r[i];
            arr.push_back(carry % 10);
            carry /= 10;
        }
        if(carry) arr.push_back(carry);
        if(arr.size() != res.size()) return false;
        for(int i = 0;i < arr.size();i++) {
            if(arr[i] != res[i]) return false;
        }
        return true;
    }
};