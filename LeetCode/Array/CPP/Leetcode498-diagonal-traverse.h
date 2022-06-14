class Solution
{
public:
    vector<int> findDiagonalOrder(vector<vector<int>> &mat)
    {
        int n = mat.size(), m = mat[0].size();
        vector<int> ans;
        for (int i = 0; i < m + n - 1; i++)
        {
            if (i & 1)
            {
                int x = i < m ? 0 : i - m + 1;
                int y = i < m ? i : m - 1;
                while (x < n && y >= 0)
                {
                    ans.push_back(mat[x][y]);
                    x++, y--;
                }
            }
            else
            {
                int x = i < n ? i : n - 1;
                int y = i < n ? 0 : i - n + 1;
                while (x >= 0 && y < m)
                {
                    ans.push_back(mat[x][y]);
                    x--, y++;
                }
            }
        }
        return ans;
    }
};