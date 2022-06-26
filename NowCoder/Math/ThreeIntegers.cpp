#include <iostream>
#include <algorithm>
#include <cstring>

// Created by Simonhancrew on 2022/06/26

using namespace std;

/*
    sort + greedy
*/

typedef long long LL;
typedef pair<int, int> PII;
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr)

const int INF = 0x3f3f3f3f;

LL in[4];

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt","w",stdout);
    fast_cin();

    for (int i = 0; i < 3; i++)
        cin >> in[i];
    sort(in, in + 3);
    if (in[2] - in[1] > in[0])
        cout << -1 << endl;
    else
    {
        cout << in[2] << endl;
    }

    return 0;
}