#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    typedef long long LL;
    string nearestPalindromic(string n)
    {
        LL len = n.size();
        vector<LL> st({(LL)pow(10, len) + 1, (LL)pow(10, len - 1) - 1});
        LL m = stoll(n.substr(0, (len + 1) / 2));
        for (int i = m - 1; i <= m + 1; i++)
        {
            string a = to_string(i), b = a;
            reverse(b.begin(), b.end());
            if (len & 1)
                st.push_back(stoll(a + b.substr(1)));
            else
                st.push_back(stoll(a + b));
        }
        LL res = 2e18;
        LL k = stoll(n);

        for (LL s : st)
        {
            // cout << s << endl;
            if (s == k)
                continue;
            if (abs(s - k) < abs(res - k))
                res = s;
        }
        return to_string(res);
    }
};