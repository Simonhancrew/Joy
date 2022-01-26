#if 0 
class Solution {
public:
    string simplifyPath(string s) {
        string ans;
        stack<string> stk;
        int n = s.size();
        stk.push("/");
        for(int i = 1;i < n;i++){
            while(i < n && s[i] == '/') i++;
            if(i == n) break;
            int j = i;
            while(j < n && s[j] != '/') j++;
            string t = s.substr(i,j - i);
            if(t == ".") continue;
            if(t == "..") {
                if(stk.size() > 1) stk.pop();
            }else{
                t += '/';
                stk.push(t);
            }
            i = j;
        }
        while(stk.size()){
            ans = stk.top() + ans;
            stk.pop();
        }
        if(ans.size() > 1 && ans.back() == '/') ans.pop_back();
        return ans;
    }
};
#endif

class Solution {
public:
    string simplifyPath(string s) {
        string res,name;
        if(s.back() != '/') s += '/';
        int n = s.size();
        for(int i = 0;i < n;i++){
            if(s[i] != '/') name += s[i];
            else{
                if(name == ".."){
                    while(res.size() && res.back() != '/') res.pop_back();
                    if(res.size()) res.pop_back();
                }else if(name != "." && name != ""){
                    res += '/' + name;
                }
                name.clear();
            }
        }
        if(!res.size()) res += '/';
        return res;
    }
};