#include <string>

using namespace std;

// 贪心，遇到左括号 + 1 ，右括号 - 1。如果遇到右括号的时候是0，代表了一个不合理的括号
// 此时每调整一次cnt就要 += 2 ，从后面换一个括号来。

class Solution {
public:
    int minSwaps(string s) {
        int cnt = 0,ans = 0;
        for(auto ch:s){
            if(ch == '['){
                cnt++;
            }else{
                if(cnt > 0){
                    cnt--;
                }else{
                    cnt++;
                    ans++;
                }

            }
        }
        return ans;
    }
};