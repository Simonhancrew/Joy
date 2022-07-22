/*
    greedy
*/
class Solution
{
public:
    int intersectionSizeTwo(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end(), [](auto &l, auto &r)
             {
            if(l[1] != r[1]) return l[1] < r[1];
            return l[0] > r[0]; });
        vector<int> rec{-1};
        int cnt = 0;
        for (auto x : intervals)
        {
            if (x[0] > rec.back())
            {
                rec.push_back(x[1] - 1);
                rec.push_back(x[1]);
                cnt += 2;
            }
            else if (x[0] > rec[cnt - 1])
            {
                rec.push_back(x[1]);
                cnt++;
            }
        }
        return cnt;
    }
};