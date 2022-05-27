#include <iostream>
#include <algorithm>
#include <cstring>

// Created by Simonhancrew on 2022/05/27

using namespace std;

/*
    列一下式子，再把范围值取出来
*/

typedef long long LL;
typedef pair<int, int> PII;
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr)

const int INF = 0x3f3f3f3f;

int t;

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt","w",stdout);
    fast_cin();
    cin >> t;
    while (t--)
    {
        LL a, b, c, d, c1, c2, c3, c4;
        cin >> a >> b >> c >> d >> c1 >> c2 >> c3 >> c4;
        LL TOT = c2 * a + c3 * c + c4 * b - c * c4;
        LL var = c1 - c2 - c3 + c4;
        LL l = max(a - d, (LL)max(c - b, 0ll)), r = min(a, min(c, d + c - b));
        // cout << "------>";
        // cout << var << ' ' << l << " " << r << endl;
        if (var >= 0)
            cout << var * l + TOT << endl;
        else
            cout << var * r + TOT << endl;
    }
    return 0;
}