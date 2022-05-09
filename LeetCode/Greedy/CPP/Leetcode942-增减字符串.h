class Solution
{
public:
    vector<int> diStringMatch(string s)
    {
        int n = s.size(), l = 0, r = n;
        vector<int> ans(n + 1);
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'I')
                ans[i] = l++;
            else
                ans[i] = r--;
        }
        ans[n] = l;
        return ans;
    }
};