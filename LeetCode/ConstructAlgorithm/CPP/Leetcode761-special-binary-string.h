#include <vector>
#include <string>
#include <algorithm>

using namespace std;
/*
    10出现的规则等价于括号序列。
    需要字典序最大，直接a + b > b + a做一个排序就可以了。
    交换针对的是同级的，递归做就可以
*/

class Solution
{
public:
    string makeLargestSpecial(string s)
    {
        if (s.size() <= 2)
            return s;
        vector<string> rec;
        string tmp;
        int cnt = 0;
        for (auto t : s)
        {
            tmp += t;
            if (t == '1')
                cnt++;
            else
            {
                cnt--;
                if (cnt == 0)
                {
                    rec.push_back('1' + makeLargestSpecial(tmp.substr(1, tmp.size() - 2)) + '0');
                    tmp.clear();
                }
            }
        }
        sort(rec.begin(), rec.end(), [](string &a, string &b)
             { return a + b > b + a; });
        string res;
        for (auto t : rec)
            res += t;
        return res;
    }
};