#include <string>
#include <cstring>

using namespace std;


// 括号匹配最原初的做法就是栈匹配，存左括号，遇到右括号弹出
// 但仔细想完之后用一个cnt记录左括号也是可以的
// 这里加入了特殊符号，因此就会引入一个范围的问题，*可以是左括号，右括号，和其余字符
// 所以，不如设置一个范围，cnt1是最小的左括号数，cnt2是最大的左括号数
// 遇到(都要++，遇到*这个范围的时候取一个并集，但此时的细节就是左括号的值不会小于0，要特判
// 且这个界限如果不成立的时候i就是false的

class Solution {
public:
    bool checkValidString(string s) {
        int cnt1 = 0,cnt2 = 0;
        for(int i = 0;i < s.size();i++){
            if(s[i] == '(') cnt1++,cnt2++;
            else if(s[i] == '*') cnt1--,cnt2++;
            else cnt1--,cnt2--;
            cnt1 = max(cnt1,0);
            if(cnt1 > cnt2) return false;
        }
        return !cnt1;
    }
};

// 动态规划的做法，dp[i][j] 前i的序列中，能否存在j个左括号.遇到*的时候有三种情况，其中i，j的关系要满足要求才能做下去
#if 0 
class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();
        int dp[n + 1][n + 1];
        memset(dp,0,sizeof dp);
        dp[0][0] = 1;
        for(int i = 1;i <= n;i++){
            auto t = s[i - 1];
            for(int j = 0;j <= n;j++){
                if(t == '('){
                    if(j >= 1) dp[i][j] = dp[i - 1][j - 1];
                }else if(t == '*'){
                    dp[i][j] = dp[i - 1][j];
                    if(j < i) dp[i][j] |= dp[i - 1][j + 1];
                    if(j >= 1) dp[i][j] |= dp[i - 1][j - 1];
                }else{
                    if(j < i){
                        dp[i][j] = dp[i - 1][j + 1];
                    }
                }
            }
        }
        return dp[n][0];
    }
};
#endif