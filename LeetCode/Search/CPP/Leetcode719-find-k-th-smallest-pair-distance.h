/*
    二分当前值，看看比这个小的对有多少个。符合k的要求的时候就是答案
*/
class Solution
{
public:
    int smallestDistancePair(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int l = 0, r = 1e6;
        auto get = [&](int mid)
        {
            int res = 0;
            for (int i = 0, j = 0; i < nums.size(); i++)
            {
                while (nums[i] - nums[j] > mid)
                    j++;
                res += i - j;
            }
            return res;
        };
        while (l < r)
        {
            int mid = l + r >> 1;
            if (get(mid) >= k)
                r = mid;
            else
                l = mid + 1;
        }
        return r;
    }
};