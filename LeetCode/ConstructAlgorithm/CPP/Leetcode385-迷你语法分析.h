class Solution
{
public:
    NestedInteger deserialize(string s)
    {
        int u = 0;
        return dfs(s, u);
    }

    NestedInteger dfs(const string &s, int &u)
    {
        NestedInteger res;
        if (s[u] == '[')
        {
            u++; // 左括号
            while (s[u] != ']')
                res.add(dfs(s, u));
            u++;                             // 右括号
            if (u < s.size() && s[u] == ',') // 逗号
                u++;
        }
        else
        {
            int k = u;
            while (k < s.size() && s[k] != ',' && s[k] != ']')
                k++;
            res.setInteger(stoi(s.substr(u, k - u)));
            if (k < s.size() && s[k] == ',')
                k++;
            u = k;
        }
        return res;
    }
};