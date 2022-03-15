class Solution
{
public:
    int countMaxOrSubsets(vector<int> &nums)
    {
        int mx = 0, ans = 1, n = nums.size();
        for (auto &num : nums)
            mx |= num;
        for (int i = 1; i < (1 << n) - 1; i++)
        {
            int tmp = 0;
            for (int j = 0; j < n; j++)
            {
                if (i >> j & 1)
                    tmp |= nums[j];
            }
            if (tmp == mx)
                ans++;
        }
        return ans;
    }
};