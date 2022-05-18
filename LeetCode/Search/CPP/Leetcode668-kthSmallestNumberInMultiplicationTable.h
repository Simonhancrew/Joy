/*
    二分当前数在整个中排第多少大，check就遍历横单位看有多少个数可以加
    check O(n)
*/
class Solution
{
public:
    int check(int mid, int m, int n)
    {
        int res = 0;
        for (int i = 1; i <= n; i++)
        {
            res += min(m, mid / i);
        }
        // cout << mid << ' ' << res;
        return res;
    }
    int findKthNumber(int m, int n, int k)
    {
        int l = 1, r = m * n;
        while (l < r)
        {
            int mid = l + r >> 1;
            if (check(mid, m, n) >= k)
                r = mid;
            else
                l = mid + 1;
            // cout <<' ' << l << ' ' << r << endl;
        }
        return r;
    }
};