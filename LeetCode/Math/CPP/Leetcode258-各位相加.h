/*
    同余，num = (a1 + a2 * 10 + a3 * 100 ...)
    num % 9 = (a1 + a2 * 1 + a3 * 1 ...)
*/
class Solution
{
public:
    int addDigits(int num)
    {
        if (!num)
            return 0;
        if (num % 9)
            return num % 9;
        return 9;
    }
};