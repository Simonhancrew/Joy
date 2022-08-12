class Solution
{
public:
    vector<vector<int>> groupThePeople(vector<int> &groupSizes)
    {
        unordered_map<int, vector<int>> mp;
        vector<vector<int>> ans;
        for (int i = 0; i < groupSizes.size(); i++)
        {
            int gsize = groupSizes[i];
            mp[gsize].push_back(i);
        }
        for (auto [k, v] : mp)
        {
            int cnt = k, tot = v.size();
            vector<int> cur;
            for (int i = 0; i < tot; i += cnt)
            {
                cur.clear();
                for (int j = 0; j < cnt; j++)
                    cur.push_back(v[i + j]);
                ans.push_back(cur);
            }
        }
        return ans;
    }
};