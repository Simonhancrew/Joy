class Solution
{
public:
    const int P = 1e9 + 7;
    using LL = long long;
    LL fact(int n)
    {
        LL res = 1;
        for (int i = 1; i <= n; i++)
            res = (LL)res * i % P;
        return res;
    }
    int numPrimeArrangements(int n)
    {
        int cnt = 0;
        vector<bool> st(n + 1);
        vector<int> primes(n + 1);
        for (int i = 2; i <= n; i++)
        {
            if (!st[i])
                primes[cnt++] = i;
            for (int j = 0; primes[j] <= n / i; j++)
            {
                st[primes[j] * i] = true;
                if (i % primes[j] == 0)
                    break;
            }
        }
        return fact(n - cnt) * fact(cnt) % P;
    }
};