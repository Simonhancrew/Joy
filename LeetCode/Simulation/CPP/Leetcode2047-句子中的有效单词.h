class Solution {
public:
    stringstream ss;
    string s;
    unordered_set<char> mp = {'!',',','.'};
    int ans = 0;
    int countValidWords(string sentence) {
        ss << sentence;
        while(ss >> s) {
            int cnt = 0,cnt1 = 0,n = s.size();
            bool flag = true;
            for(int i = 0;i < n;i++) {
                if(isdigit(s[i])) {
                    flag = false;
                    break;
                }
                if(s[i] == '-'){
                    cnt++;
                    if(cnt > 1 || i == 0 || i == n - 1) {
                        flag =false;
                        break;
                    }
                    if(!isalpha(s[i - 1]) || !isalpha(s[i + 1])) {
                        flag = false;
                        break;
                    }
                }
                if(mp.count(s[i])){
                    if(i != n - 1) {
                        flag = false;
                        break;
                    }
                    cnt1++;
                    if(cnt1 > 1) {
                        flag =false;
                        break;
                    }
                }
            }
            if(flag) ans++;
        }
        return ans;
    }
};