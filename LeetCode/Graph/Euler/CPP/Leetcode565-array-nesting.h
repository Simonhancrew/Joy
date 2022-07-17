/*
    大图可能不连通，但是构成的环是一个欧拉图
    可以称这种问题为环图，一定会走完一个环。开标记记录就行了。
*/
class Solution
{
public:
    int arrayNesting(vector<int> &nums)
    {
        int n = nums.size(), ans = 0;
        vector<int> st(n, 0);
        for (int i = 0; i < n; i++)
        {
            if (st[i])
                continue;
            st[i] = true;
            int ne = nums[i], cur = 1;
            while (ne != i)
            {
                ne = nums[ne];
                st[ne] = true;
                cur++;
            }
            ans = max(cur, ans);
        }
        return ans;
    }
};
