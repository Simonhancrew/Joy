class Solution
{
public:
    vector<int> fa, cnt;
    int find(int x)
    {
        if (fa[x] != x)
            fa[x] = find(fa[x]);
        return fa[x];
    }

    int largestComponentSize(vector<int> &nums)
    {
        int n = nums.size();
        fa.resize(n), cnt.resize(n);
        for (int i = 0; i < n; i++)
        {
            fa[i] = i;
            cnt[i] = 1;
        }

        unordered_map<int, vector<int>> app;
        for (int i = 0; i < n; i++)
        {
            int x = nums[i];
            for (int j = 1; j <= x / j; j++)
            {
                if (x % j == 0)
                {
                    if (j > 1)
                        app[j].push_back(i);
                    app[x / j].push_back(i);
                }
            }
        }
        int res = 1;
        int tot = 0;
        for (auto &[k, v] : app)
        {
            for (int i = 1; i < v.size(); i++)
            {
                int a = v[0], b = v[i];
                if (find(a) != find(b))
                {
                    cnt[find(a)] += cnt[find(b)];
                    fa[find(b)] = find(a);
                    res = max(res, cnt[find(a)]);
                }
            }
        }
        return res;
    }
};