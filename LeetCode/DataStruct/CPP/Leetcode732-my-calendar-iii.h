/*
    差分，头+，尾-，看看中间最大是多少
*/
class MyCalendarThree
{
public:
    map<int, int> mp;
    MyCalendarThree()
    {
    }

    int book(int start, int end)
    {
        mp[start]++, mp[end]--;
        int res = 0, sum = 0;
        for (auto &[k, v] : mp)
        {
            sum += v;
            res = max(sum, res);
        }
        return res;
    }
};
