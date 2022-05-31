class Solution
{
public:
    unordered_map<char, vector<char>> mp;
    unordered_map<char, int> din;
    bool flag = true;
    string res;
    void build(const string &l, const string &r)
    {
        int n = min(l.size(), r.size());
        int i = 0;
        while (i < n)
        {
            char a = l[i], b = r[i];
            if (a != b)
            {
                mp[a].push_back(b);
                din[b]++;
                break;
            }
            i++;
        }
        if (i == n && l.size() > r.size())
            flag = false;
    }

    bool topsort()
    {
        queue<char> q;
        for (auto [k, v] : mp)
        {
            if (!din.count(k))
                q.push(k);
        }
        int cnt = 0;
        while (q.size())
        {
            auto t = q.front();
            q.pop();
            res += t;
            cnt++;
            for (auto ne : mp[t])
            {
                if (--din[ne] == 0)
                {
                    q.push(ne);
                }
            }
        }
        if (cnt != mp.size())
            return false;
        return true;
    }

    string alienOrder(vector<string> &words)
    {
        int n = words.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < words[i].size(); j++)
            {
                char c = words[i][j];
                if (!mp.count(c))
                    mp[c] = vector<char>();
            }
        }

        for (int i = 1; i < n && flag; i++)
            build(words[i - 1], words[i]);

        if (!flag)
            return "";

        if (!topsort())
            return "";

        return res;
    }
};