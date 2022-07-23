/*
    topsort
*/
class Solution
{
public:
    bool sequenceReconstruction(vector<int> &nums, vector<vector<int>> &sequences)
    {
        int n = nums.size();
        vector<unordered_set<int>> g(n + 1);
        vector<int> din(n + 1);
        for (auto &path : sequences)
        {
            int len = path.size();
            int st = path[0];
            for (int i = 1; i < len; i++)
            {
                if (!g[st].count(path[i]))
                    din[path[i]]++;
                g[st].insert(path[i]);
                st = path[i];
            }
        }
        queue<int> q;
        for (int i = 1; i <= n; i++)
        {
            if (din[i] == 0)
            {
                q.push(i);
                if (q.size() > 1)
                    return false;
            }
        }
        vector<int> path;
        while (q.size())
        {
            auto t = q.front();
            path.push_back(t);
            q.pop();
            for (auto ne : g[t])
            {
                din[ne]--;
                if (din[ne] == 0)
                {
                    q.push(ne);
                    if (q.size() > 1)
                        return false;
                }
            }
        }
        return path == nums;
    }
};