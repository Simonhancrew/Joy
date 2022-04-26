class Solution
{
public:
    int projectionArea(vector<vector<int>> &grid)
    {
        int l = 0, r = 0, d = 0;
        int n = grid.size();
        for (int i = 0; i < n; i++)
        {
            int tl = 0, tr = 0;
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j])
                    ++d;
                tl = max(tl, grid[i][j]);
                tr = max(tr, grid[j][i]);
            }
            l += tl, r += tr;
        }
        return d + l + r;
    }
};