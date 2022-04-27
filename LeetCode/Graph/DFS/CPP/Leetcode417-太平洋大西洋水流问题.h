#ifdef TWOST
class Solution
{
public:
    vector<vector<int>> res, st1, st2;
    int n, m;
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {
        n = heights.size(), m = heights[0].size();
        st1.resize(n, vector<int>(m)), st2.resize(n, vector<int>(m));
        for (int i = 0; i < n; i++)
            dfs(heights, st1, i, 0), dfs(heights, st2, i, m - 1);
        for (int i = 0; i < m; i++)
            dfs(heights, st1, 0, i), dfs(heights, st2, n - 1, i);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (st1[i][j] && st2[i][j])
                    res.push_back({i, j});
            }
        }
        return res;
    }
    int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
    void dfs(vector<vector<int>> &g, vector<vector<int>> &st, int x, int y)
    {
        if (st[x][y])
            return;
        st[x][y] = true;
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (st[nx][ny])
                continue;
            if (g[nx][ny] < g[x][y])
                continue;
            dfs(g, st, nx, ny);
        }
    }
};
#endif
class Solution
{
public:
    vector<vector<int>> res, st;
    int n, m;
    int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {
        n = heights.size(), m = heights[0].size();
        st.resize(n, vector<int>(m));
        for (int i = 0; i < n; i++)
            dfs(heights, i, 0, 1), dfs(heights, i, m - 1, 2);
        for (int i = 0; i < m; i++)
            dfs(heights, 0, i, 1), dfs(heights, n - 1, i, 2);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (st[i][j] == 3)
                    res.push_back({i, j});
            }
        }
        return res;
    }

    void dfs(vector<vector<int>> &g, int x, int y, int t)
    {
        if (st[x][y] & t)
            return;
        st[x][y] |= t;
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (g[x][y] > g[nx][ny])
                continue;
            dfs(g, nx, ny, t);
        }
    }
};