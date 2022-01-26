/* 
    思路比较简单，存在二段性，可以考虑二分的处理出字符串的最大长度
    然后考虑一段字符串是否出现可以考虑字符串哈希去做空间的简化
*/
class Solution {
public:
    typedef unsigned long long ULL;
    static const int N = 3e4 + 10,P = 131;
    ULL p[N],h[N];
    int start,n;

    ULL get(int l,int r){
        return h[r] - h[l - 1] * p[r - l + 1];
    }

    bool check(int mid){
        unordered_set<ULL> st;
        for(int i = 1;i + mid - 1 <= n;i++){
            ULL v = get(i,i + mid - 1);
            if(st.count(v)){
                start = i;
                return true;
            }
            st.insert(v);
        }
        return false;
    }

    string longestDupSubstring(string s) {
        n = s.size();
        p[0] = 1;
        for(int i = 1;i <= n;i++){
            p[i] = p[i - 1] * P;
            h[i] = h[i - 1] * P + s[i - 1];
        }
        int l = 0,r = n;
        while(l < r){
            int mid = l + r + 1 >> 1;
            if(check(mid)) l = mid;
            else r = mid - 1;
        }
        check(r);
        return s.substr(start - 1,r);
    }
};