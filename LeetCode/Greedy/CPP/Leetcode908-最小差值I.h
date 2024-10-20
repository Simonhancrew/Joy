/*
    最小值的上下界[x,y]
    最大值的上下界[a,b]
    假设y和a之间有距离，其余的数一定能规约到这之间（加减的数都是k）
    没有距离的话，全部都可以变成一样，界为0
*/
class Solution {
public:
  int smallestRangeI(vector<int> &nums, int k) {
    return max(0, *max_element(nums.begin(), nums.end()) - k -
                      *min_element(nums.begin(), nums.end()) - k);
  }
};
