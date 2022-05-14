#include <string>
#include <vector>
#include <cstring>

using namespace std;

const int N = 1 << 15, INF = 20;
int f[N], g[N][26];
/*
    f[i]，状态i到最后状态的步数
    做一个记忆化搜索
*/
class Solution
{
public:
    vector<string> str;
    int n;
    string tar;

    int fill(int st, char c)
    {
        int &v = g[st][c - 'a'];
        if (v != -1)
            return v;
        v = st;
        for (int i = 0; i < n; i++)
        {
            if (!(st >> i & 1) && c == tar[i])
            {
                v += (1 << i);
                break;
            }
        }
        return v;
    }

    int dfs(int st)
    {
        int &v = f[st];
        if (v != -1)
            return v;
        if (st == (1 << n) - 1)
            return v = 0;
        v = INF;
        for (auto &s : str)
        {
            int t = st;
            for (auto c : s)
            {
                t = fill(t, c);
            }
            if (t == st)
                continue;
            v = min(v, dfs(t) + 1);
        }
        return v;
    }

    int minStickers(vector<string> &stickers, string target)
    {
        tar = target, str = stickers, n = tar.size();
        memset(f, -1, sizeof f);
        memset(g, -1, sizeof g);
        int res = dfs(0);
        if (res == INF)
            return -1;
        return res;
    }
};