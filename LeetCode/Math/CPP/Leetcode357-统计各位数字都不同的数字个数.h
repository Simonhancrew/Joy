class Solution
{
public:
    int countNumbersWithUniqueDigits(int n)
    {
        if (n == 0)
            return 1;
        if (n == 1)
            return 10;
        int base = 9, mul = 9, res = 10;
        for (int i = 0; i < n - 1; i++)
        {
            base *= (mul - i);
            res += base;
        }
        return res;
    }
};