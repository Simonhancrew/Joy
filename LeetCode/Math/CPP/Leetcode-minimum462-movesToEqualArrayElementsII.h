class Solution
{
public:
    int minMoves2(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int res = 0, n = nums.size();
        for (int i = 0; i < n; i++)
            res += abs(nums[i] - nums[n / 2]);
        return res;
    }
};