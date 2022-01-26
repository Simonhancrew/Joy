#include <vector>
#include <algorithm>

using namespace std;

// 等价于一个数1，最后他们变小到min_element
// ans = sum(arr) - min*len(arr)
// ans = sum(arr[i] - min) 

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int min = *min_element(nums.begin(),nums.end());
        int res = 0;
        for(auto num:nums) res += num - min;
        return res;
    }
};