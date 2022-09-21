class Solution {
public:
    int n;
    int f(string& s1,string& s2) {
        int res = 0;
        for(int i = 0;i < n;i++) {
            if(s1[i] != s2[i]) res++;
        }
        return (res + 1) / 2;
    }

    bool dfs(string& s1,string& s2,int dep) {
        if(!dep) return s1 == s2;
        if(f(s1,s2) > dep) return false;
        for(int i = 0;i < n;i++) {
            if(s1[i] != s2[i]) {
                for(int j = i + 1;j < n;j++) {
                    if(s2[i] == s1[j]) {
                        swap(s1[i],s1[j]);
                        if(dfs(s1,s2,dep - 1)) return true;
                        swap(s1[i],s1[j]);
                    }
                }
                break;
            }
        }
        return false;
    }

    int kSimilarity(string s1, string s2) {
        if(s1 == s2) return 0;
        int dep = 1;
        n = s1.size();
        // cout << n << endl;
        // cout << f(s1,s2) << '\n';
        while(!dfs(s1,s2,dep)) ++dep;
        return dep;
    }
};
