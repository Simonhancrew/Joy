#include <vector>

using namespace std;

class Solution
{
public:
    int get(int a, int b)
    {
        return a >> b & 1;
    }

    bool validUtf8(vector<int> &data)
    {
        int n = data.size();
        for (int i = 0; i < n; i++)
        {
            if (!get(data[i], 7))
                continue;
            int cnt = 0;
            while (cnt <= 4 && get(data[i], 7 - cnt))
                cnt++;
            if (cnt == 1 || cnt > 4)
                return false;
            for (int j = 1; j < cnt; j++)
            {
                int t = i + j;
                if (t >= n)
                    return false;
                if (!(get(data[t], 7) && !get(data[t], 6)))
                    return false;
            }
            i += cnt - 1;
        }
        return true;
    }
};