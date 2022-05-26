class Solution
{
public:
    vector<int> fallingSquares(vector<vector<int>> &positions)
    {
        const int n = positions.size();
        vector<int> ans(n);
        for (int i = 0; i < n; i++)
        {
            int l1 = positions[i][0], r1 = positions[i][0] + positions[i][1] - 1;
            ans[i] = positions[i][1];
            for (int j = 0; j < i; j++)
            {
                int l2 = positions[j][0], r2 = positions[j][0] + positions[j][1] - 1;
                if (r1 >= l2 && r2 >= l1)
                {
                    ans[i] = max(ans[i], ans[j] + positions[i][1]);
                }
            }
        }
        for (int i = 1; i < n; i++)
        {
            ans[i] = max(ans[i], ans[i - 1]);
        }
        return ans;
    }
};