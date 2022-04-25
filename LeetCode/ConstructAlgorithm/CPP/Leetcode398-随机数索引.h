class Solution
{
public:
    unordered_map<int, vector<int>> mp;
    Solution(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]].push_back(i);
        }
    }

    int pick(int target)
    {
        return mp[target][rand() % mp[target].size()];
    }
};
#ifdef ReservoirSampling
class Solution
{
public:
    vector<int> arr;
    Solution(vector<int> &nums) : arr(nums)
    {
    }

    int pick(int target)
    {
        int ans, cnt = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] == target)
            {
                cnt++;
                if (rand() % cnt == 0)
                {
                    ans = i;
                }
            }
        }
        return ans;
    }
};
#endif