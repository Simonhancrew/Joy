/*
    f[i][0 or 1]代表前i位，以0 or 1结尾的最小翻转数
*/
#ifdef ORIGIN
class Solution
{
public:
    int minFlipsMonoIncr(string s)
    {
        int n = s.size();
        vector<vector<int>> f(n + 1, vector<int>(2, 0));
        for (int i = 1; i <= n; i++)
        {
            f[i][0] = f[i - 1][0] + (s[i - 1] == '1');
            f[i][1] = min(f[i - 1][0], f[i - 1][1]) + (s[i - 1] == '0');
        }
        return min(f[n][0], f[n][1]);
    }
};
#endif
class Solution
{
public:
    int minFlipsMonoIncr(string s)
    {
        int f0 = 0, f1 = 0;
        for (char c : s)
        {
            int ff0 = f0, ff1 = min(f0, f1);
            ff0 += (c == '1');
            ff1 += (c == '0');
            f0 = ff0, f1 = ff1;
        }
        return min(f0, f1);
    }
};