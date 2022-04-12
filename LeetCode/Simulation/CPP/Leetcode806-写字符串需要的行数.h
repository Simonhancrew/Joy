class Solution
{
public:
    vector<int> numberOfLines(vector<int> &widths, string s)
    {
        int cnt = 0, line = 1;
        for (auto &x : s)
        {
            int t = widths[x - 'a'];
            cnt += t;
            if (cnt > 100)
            {
                cnt = t, line++;
            }
        }
        return vector<int>{line, cnt};
    }
};