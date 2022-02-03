#include <vector>

using namespace std;

class Solution {
public:
    vector<int> s = vector<int> {1,1};
    int findMinFibonacciNumbers(int k) {
        int pre = 1,aft = 1;
        while(aft < k) {
            int t = aft;
            aft = pre + aft;
            pre = t;
            s.push_back(aft);
        }
        int cnt = 0,idx = s.size() - 1;
        while(k) {
            while(k && s[idx] <= k) k -= s[idx],cnt++;
            idx--;
        }
        return cnt;
    }
};