/*
    黑名单长m，则可选的数总共只有n-m。且前面n-m中在黑名单出现过的数
    应该映射到后面没有出现在黑名单的数中去。开map记录这个映射，构造过程中
    将[n - m,n - 1]中不在黑名单的数记录，并在遍历[0,n - m - 1]的过程中建立映射
*/
class Solution
{
public:
    int m, n;
    unordered_map<int, int> mp;
    Solution(int n, vector<int> &blacklist)
    {
        this->n = n, m = blacklist.size();
        unordered_set<int> st;
        for (auto x : blacklist)
            if (x >= n - m)
            {
                st.insert(x);
            }
        auto it = n - m;
        for (auto num : blacklist)
        {
            if (num < n - m)
            {
                while (st.count(it))
                    ++it;
                mp[num] = it;
                it++;
            }
        }
    }

    int pick()
    {
        int k = rand() % (n - m);
        if (mp.count(k))
            return mp[k];
        return k;
    }
};
