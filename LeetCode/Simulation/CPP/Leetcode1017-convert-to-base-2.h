#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string baseNeg2(int n) {
        if (!n) return "0";
        string res;
        while (n) {
            res.push_back('0' + n % 2);
            n /= 2;
        }
        n = res.size();
        int cnt = 0;
        for (int i = 0;i < n;i++) {
            int cur = cnt + (res[i] - '0');
            res[i] = '0' + cur % 2;
            cnt = cur / 2;
            if (i & 1 && cur & 1) cnt++;
        }
        while (cnt) {
            res.push_back('1');
            if (n % 2 == 0) cnt--; 
            n++;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

