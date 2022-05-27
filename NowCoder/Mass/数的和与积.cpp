#include <iostream>
#include <algorithm>
#include <cstring>

// Created by Simonhancrew on 2022/05/27

using namespace std;

/*
    递推一下a + b + 1 + (a * b * 1) = sum(n)
    => (a + 1) * (b + 1) = sum(n)
    再找一下特殊关系
*/

typedef long long LL;
typedef pair<int, int> PII;
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr)

const int INF = 0x3f3f3f3f;

int n, t;

int main()
{
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    fast_cin();
    cin >> t;
    while (t--)
    {
        cin >> n;
        if (n == 2 || n == 4)
            cout << -1 << endl;
        else if (n == 3)
        {
            cout << 1 << endl;
            cout << 3 << endl;
        }
        else if (n & 1)
        {
            cout << 3 << endl;
            cout << 1 << ' ' << n / 2 << ' ' << n - 1 << endl;
        }
        else
        {
            cout << 3 << endl;
            cout << 1 << ' ' << (n - 2) / 2 << ' ' << n << endl;
        }
    }
    return 0;
}