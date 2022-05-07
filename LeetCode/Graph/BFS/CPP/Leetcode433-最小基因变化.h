class Solution
{
public:
    unordered_set<string> st;
    unordered_map<string, int> dist;
    queue<string> q;
    int minMutation(string start, string end, vector<string> &bank)
    {
        for (auto &x : bank)
            st.insert(x);
        dist[start] = 0;
        q.push(start);
        char id[4] = {'A', 'C', 'G', 'T'};
        while (q.size())
        {
            auto t = q.front();
            q.pop();
            for (int i = 0; i < 8; i++)
            {
                string s = t;
                for (auto const &c : id)
                {
                    s[i] = c;
                    if (st.count(s) && dist.count(s) == 0)
                    {
                        dist[s] = dist[t] + 1;
                        if (s == end)
                            return dist[s];
                        q.push(s);
                    }
                }
            }
        }
        return -1;
    }
};