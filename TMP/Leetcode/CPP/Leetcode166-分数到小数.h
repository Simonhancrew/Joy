#include <unordered_map>
#include <string>

using namespace std;

// 长除法
/*
    1 判断两数正负可以考虑一个异或
    2 （up = 3 * 4） 结果是12
*/

class Solution {
public:
    using LL = long long;
    string fractionToDecimal(int numerator, int denominator) {
        if((LL)numerator % denominator == 0) return to_string((int64_t)numerator / denominator);
        int64_t up = abs(numerator),down = abs(denominator);
        // 判断二者是不是都是负数利用不进位加法
        string ans = ((numerator < 0) ^ (denominator < 0) ? "-" : "") + to_string(up / down) + "."; 
        unordered_map<int64_t,int> st;
        for(int i = ans.size();up = up % down * 10;i++){
            if(st.count(up)){
                ans.insert(ans.begin() + st[up],'(');
                ans.push_back(')');
                break;
            }
            st[up] = i;
            ans.push_back('0' + up / down);
        } 
        return ans;
    }
};