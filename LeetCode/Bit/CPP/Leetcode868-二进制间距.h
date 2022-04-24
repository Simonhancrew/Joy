class Solution
{
public:
    int binaryGap(int n)
    {
        int res = 0, pre = -1, cur = 0;
        while (n)
        {
            if (n & 1)
            {
                if (pre != -1)
                {
                    res = max(res, cur - pre);
                }
                pre = cur;
            }
            cur++;
            n >>= 1;
        }
        return res;
    }
};