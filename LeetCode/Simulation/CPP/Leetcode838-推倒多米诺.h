class Solution {
public:
    string pushDominoes(string dominoes) {
        string s = 'L' + dominoes + 'R';
        int n = s.size();
        vector<int> l(n),r(n);
        for(int i = 0,j = 0;i < n;i++){
            if(s[i] != '.') j = i;
            l[i] = j;
        }
        for(int i = n - 1,j = 0;i >= 0;i--) {
            if(s[i] != '.') j = i;
            r[i] = j;
        }
        for(int i = 0;i < n;i++) {
            if(s[l[i]] == 'L' && s[r[i]] == 'L') s[i] = 'L';
            else if(s[l[i]] == 'L' && s[r[i]] == 'R') s[i] = '.';
            else if(s[l[i]] == 'R' && s[r[i]] == 'R') s[i] = 'R';
            else {
                if(i - l[i] < r[i] - i) s[i] = 'R';
                else if(i - l[i] > r[i] - i) s[i] = 'L';
                else s[i] = '.';
            }
        }
        return s.substr(1,n - 2);
    }
};