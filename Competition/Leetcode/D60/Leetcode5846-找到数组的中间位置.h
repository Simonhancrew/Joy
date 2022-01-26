#include <vector>
using namespace std;

// 两侧前缀和

class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> s(n + 2);
        // 因为indx可以是数组两边的位置，所以多开2可以少很多麻烦
        for(int i = 1;i <= n;i++) s[i] += s[i - 1] + nums[i - 1];
        for(int i = 1;i <= n;i++){
            if(s[i - 1] == s[n] - s[i]) return i - 1;
        } 
        return -1;
    }
};