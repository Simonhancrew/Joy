/*
    字符串的最小表示法
*/
class Solution
{
public:
    string orderlyQueue(string s, int k)
    {
        if (k == 1)
        {
            int n = s.size();
            string res = s;
            for (int i = 0; i < n; i++)
            {
                s = s.substr(1) + s[0];
                res = min(res, s);
            }
            return res;
        }
        sort(s.begin(), s.end());
        return s;
    }
};