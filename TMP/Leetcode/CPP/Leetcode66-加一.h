#include <vector>

using namespace std;

// 简单高精度加法

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size(),carry = 1;
        for(int i = n - 1;i >= 0;i--){
            int cur = carry + digits[i];
            digits[i] = cur % 10;
            carry = cur / 10;
        }
        if(carry) digits.insert(begin(digits),1);
        return digits;
    }
};