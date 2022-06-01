class Solution
{
public:
    int n, sum;
    int edge[4] = {0};
    bool dfs(int u, vector<int> &arr)
    {
        if (u == n)
            return true;
        for (int i = 0; i < 4; i++)
        {
            edge[i] += arr[u];
            if (edge[i] <= sum / 4 && dfs(u + 1, arr))
                return true;
            edge[i] -= arr[u];
        }
        return false;
    }
    bool makesquare(vector<int> &arr)
    {
        sum = accumulate(arr.begin(), arr.end(), 0);
        if (sum % 4 != 0)
            return false;
        n = arr.size();
        sort(arr.begin(), arr.end(), [](int l, int r)
             { return l > r; });
        return dfs(0, arr);
    }
};