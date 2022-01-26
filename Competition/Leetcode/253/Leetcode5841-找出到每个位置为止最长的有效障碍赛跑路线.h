#include <vector>
#include <algorithm>

using namespace std;


// 最长上升子序列的变种，最长不降子序列，找到第一个大于他的数

class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        vector<int> ans;
        vector<int> dp;
        int n = obstacles.size();
        for(int i = 0;i < n;i++){
            auto it = lower_bound(dp.begin(),dp.end(),obstacles[i] + 1);
            if(it == dp.end()){
                dp.push_back(obstacles[i]);
                ans.push_back(dp.size());
            }else{
                *it = obstacles[i];
                ans.push_back(it - dp.begin() + 1);
            }
        }
        return ans;
    }
};