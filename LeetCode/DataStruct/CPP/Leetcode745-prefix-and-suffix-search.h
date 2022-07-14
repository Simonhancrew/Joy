const int N = 400000;
int son[N][27], idx;
int w[N];

class WordFilter
{
public:
    void insert(string s, int id)
    {
        int p = 0;
        for (int i = 0; i < s.size(); i++)
        {
            int t = s[i] == '#' ? 26 : s[i] - 'a';
            if (!son[p][t])
                son[p][t] = ++idx;
            p = son[p][t];
            w[p] = id;
        }
    }

    int query(string s)
    {
        int p = 0;
        for (int i = 0; i < s.size(); i++)
        {
            int t = s[i] == '#' ? 26 : s[i] - 'a';
            if (!son[p][t])
                return -1;
            p = son[p][t];
        }
        return w[p];
    }

    WordFilter(vector<string> &words)
    {
        memset(son, 0, sizeof son);
        idx = 0;
        for (int i = 0; i < words.size(); i++)
        {
            string s = '#' + words[i];
            insert(s, i);
            for (int j = words[i].size() - 1; j >= 0; j--)
            {
                s = words[i][j] + s;
                insert(s, i);
            }
        }
    }

    int f(string pref, string suff)
    {
        return query(suff + "#" + pref);
    }
};