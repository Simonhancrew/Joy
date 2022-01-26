#include <vector>

using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& a) {
        int n = a.size();
        if(n < 3) return 0;
        for(int i = n - 1;i > 0;i--) a[i] -= a[i - 1];
        int res = 0;
        for(int i = 1;i < n;i++){
            int j = i;
            while(j < n && a[j] == a[i]) j++;
            int k = j - i;
            /*
                长度[1,k]，左端点为1，有右端点可以去取[2,k]。因为差分数组相等，实际等差数列要包含前一个数
                左端点取2，右端点可以取[3,k]......
            */
            res += k * (k - 1) / 2;
            i = j - 1;
        }
        return res;
    }
};s