#include <vector>
using namespace std;
class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        int cnt = 0,n = nums.size();
        for(int i = 0;i < n - 3;i++){
            for(int j = i + 1;j < n - 2;j++){
                for(int k = j + 1;k < n - 1;k++){
                    for(int x = k + 1;x < n;x ++){
                        if(nums[i] + nums[j] + nums[k] == nums[x]) cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};