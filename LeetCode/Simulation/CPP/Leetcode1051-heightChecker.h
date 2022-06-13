class Solution
{
public:
    int heightChecker(vector<int> &heights)
    {
        vector<int> rec = heights;
        sort(rec.begin(), rec.end());
        int ans = 0;
        for (int i = 0; i < rec.size(); i++)
        {
            if (heights[i] != rec[i])
                ++ans;
        }
        return ans;
    }
};