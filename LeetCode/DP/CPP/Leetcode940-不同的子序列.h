/*
    f[i][j]前i位，结尾是j的不同方案数
*/
class Solution
{
public:
    int distinctSubseqII(string s)
    {
        const int MOD = 1e9 + 7, n = s.size();
        vector<vector<int>> f(n + 1, vector<int>(26));
        for (int i = 0; i < n; i++)
        {
            f[i + 1][s[i] - 'a'] = 1;
            for (int j = 0; j < 26; j++)
            {
                f[i + 1][s[i] - 'a'] = (f[i + 1][s[i] - 'a'] + f[i][j]) % MOD;
                if (s[i] - 'a' != j)
                    f[i + 1][j] = (f[i + 1][j] + f[i][j]) % MOD;
            }
        }
        int res = 0;
        for (auto x : f[n])
            res = (res + x) % MOD;
        return res;
    }
};