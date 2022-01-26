#include <iostream>
#include <cstring>
#include <algorithm>
#include <stack>

using namespace std;
#if 0
const int N = 1e6 + 10;

/*

*/

int main(){
    string s;
    cin >> s;
    int n = s.size();
    int res = 0,cnt = 0;
    stack<int> st;
    st.push(-1);
    for(int i = 0;i < n;i++){
        if(s[i] == '(') {
            st.push(i);
        }else{
            st.pop();
            if(st.empty()) {
                st.push(i);
            }else{
                int t = i - st.top();
                if(res < t) res = t,cnt = 1;
                else if(res == t) cnt++;
            }
        }
    }    
    if(res) cout << res << ' ' << cnt;
    else cout << 0 << ' ' << 1;
}
#endif

/*
    括号序列的题目
    1 左括号大于等于右括号
    2 ( == )
    画图来表示的话，(上升，)下降。
    找到登高的最长匹配的长度
*/

int main(){
    string s;
    cin >> s;
    int resl = 0,resc = 1,n = s.size();
    stack<int> stk;
    for(int i = 0;i < n;i++){
        // 下降才考虑匹配
        if(stk.size() && s[i] == ')' && s[stk.top()] == '(') stk.pop();
        else stk.push(i); // 其余情况压入当前下标
    
        int r;
        // 当前登高的段长度是多少
        if(stk.size()) r = i - stk.top();
        else r = i + 1; // 全空的话代表能从头匹配
        
        if(r > resl) resl = r,resc = 1;
        else if(r > 0 && r == resl) resc++;
    }
    cout << resl << ' ' << resc << endl;
    return 0;
}
