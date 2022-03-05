#include <algorithm>
#include <string>

using namespace std;
/*
    一样的话就不存在，不一样长的话返回较长的
*/
class Solution
{
public:
    int findLUSlength(string a, string b)
    {
        if (a == b)
            return -1;
        return max(a.size(), b.size());
    }
};