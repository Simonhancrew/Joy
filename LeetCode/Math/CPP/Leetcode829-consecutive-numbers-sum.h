class Solution
{
public:
    int consecutiveNumbersSum(int n)
    {
        n *= 2;
        int res = 0;
        for (int b = 1; b <= n / b; b++)
        {
            if (n % b == 0)
            {
                if ((n / b - b + 1) % 2 == 0)
                    res++;
            }
        }
        return res;
    }
};