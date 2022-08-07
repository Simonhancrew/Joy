class Solution
{
public:
    vector<int> exclusiveTime(int n, vector<string> &logs)
    {
        vector<int> ans(n);
        stack<int> stk;
        int last;
        for (auto &log : logs)
        {
            int x = log.find(':'), y = log.substr(x + 1).find(':') + x + 1;
            int id = stoi(log.substr(0, x)), ts = stoi(log.substr(y + 1));
            if (log.substr(x + 1, y - x - 1) == "start")
            {
                if (stk.size())
                    ans[stk.top()] += ts - last;
                stk.push(id);
                last = ts;
            }
            else
            {
                ans[stk.top()] += ts - last + 1;
                last = ts + 1;
                stk.pop();
            }
        }
        return ans;
    }
};