class Solution
{
public:
    bool check(const string &a, const string &b)
    {
        int j = 0, n = b.size(), m = a.size();
        for (int i = 0; i < n; i++)
        {
            if (j < m && a[j] == b[i])
                j++;
        }
        return j == m;
    }
    int findLUSlength(vector<string> &strs)
    {
        int n = strs.size(), res = -1;
        for (int i = 0; i < n; i++)
        {
            bool flag = false;
            for (int j = 0; j < n; j++)
            {
                if (i != j && check(strs[i], strs[j]))
                {
                    flag = true;
                    break;
                }
            }
            if (!flag)
                res = max(res, (int)strs[i].size());
        }
        return res;
    }
};