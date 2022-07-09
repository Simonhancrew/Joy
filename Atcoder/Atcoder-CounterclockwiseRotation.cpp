#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>

// Created by Simonhancrew on 2022/07/09

using namespace std;

/*
    坐标轴旋转类问题，推公式就行
    s = r cos(a + b) = r cos(a)cos(b) – r sin(a)sin(b)   (1.1)
    t = r sin(a + b) = r sin(a)cos(b) + r cos(a)sin(b)   (1.2)

    其中 x = r cos(a) , y = r sin(a)
    代入(1.1), (1.2) ,

    s = x cos(b) – y sin(b)    (1.3)
    t = x sin(b) + y cos(b)    (1.4)

    其中角度和弧度需要换算
*/

typedef long long LL;
typedef pair<int, int> PII;
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr)

const int INF = 0x3f3f3f3f;
#define PI acos(-1)
double a, b, d;

int main()
{
    freopen("input.txt", "r", stdin);
    // freopen("output.txt","w",stdout);
    // fast_cin();
    cin >> a >> b >> d;
    double x = a, y = b;
    if ((!a && !b) || d == 360)
        cout << x << ' ' << y << endl;
    else
    {
        x = a * cos(d / 180.0 * PI) - b * sin(d / 180.0 * PI);
        y = a * sin(d / 180.0 * PI) + b * cos(d / 180.0 * PI);
        printf("%.20lf %.20lf\n", x, y);
    }
    return 0;
}