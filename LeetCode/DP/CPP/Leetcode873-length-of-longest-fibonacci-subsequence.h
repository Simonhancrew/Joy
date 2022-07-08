class Solution
{
public:
    int lenLongestFibSubseq(vector<int> &arr)
    {
        unordered_map<int, int> mp;
        int n = arr.size(), res = 0;
        vector<vector<int>> f(n, vector<int>(n));
        for (int i = 0; i < n; i++)
            mp[arr[i]] = i;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                int x = arr[i] - arr[j];
                f[i][j] = 2;
                if (x < arr[j] && mp.count(x))
                {
                    int k = mp[x];
                    f[i][j] = max(f[i][j], f[j][k] + 1);
                }
                res = max(res, f[i][j]);
            }
        }
        if (res < 3)
            return 0;
        return res;
    }
};