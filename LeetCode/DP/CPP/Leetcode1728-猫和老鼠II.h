#define MAXSETP 128
int f[8][8][8][8][MAXSETP];
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
class Solution
{
public:
    vector<string> g;
    int n, m, cj, mj;
    // 0 cat 1 mouse
    int dp(int cx, int cy, int mx, int my, int cnt)
    {
        if (cnt >= MAXSETP)
            return 0;
        int &v = f[cx][cy][mx][my][cnt];
        if (v != -1)
            return v;
        if (cnt & 1)
        { // mouse first
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j <= cj; j++)
                {
                    int x = cx + dx[i] * j, y = cy + dy[i] * j;
                    if (x < 0 || x >= n || y < 0 || y >= m || g[x][y] == '#')
                        break;
                    if (x == mx && y == my)
                        return v = 0;
                    if (g[x][y] == 'F')
                        return v = 0;
                    if (!dp(x, y, mx, my, cnt + 1))
                        return v = 0;
                }
            }
            return v = 1;
        }
        else
        { // mouse
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j <= mj; j++)
                {
                    int x = mx + dx[i] * j, y = my + dy[i] * j;
                    if (x < 0 || x >= n || y < 0 || y >= m || g[x][y] == '#')
                        break;
                    if (x == cx && y == cy)
                        continue; // 越过猫
                    if (g[x][y] == 'F')
                        return v = 1;
                    if (dp(cx, cy, x, y, cnt + 1))
                        return v = 1;
                }
            }
            return v = 0;
        }
    }
    bool canMouseWin(vector<string> &grid, int catJump, int mouseJump)
    {
        g = grid, cj = catJump, mj = mouseJump;
        n = grid.size(), m = grid[0].size();
        int cx, cy, mx, my;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 'C')
                    cx = i, cy = j;
                else if (grid[i][j] == 'M')
                    mx = i, my = j;
            }
        }
        memset(f, -1, sizeof f);
        return dp(cx, cy, mx, my, 0);
    }
};