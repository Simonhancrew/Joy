#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
using ll = long long;

ll a,m;

ll gcd(ll a,ll b){
    return b?gcd(b,a % b) : a;
}

ll phi(ll x){
    ll res = x;
    for(int i = 2;i <= x / i;i++){
        if(x % i == 0) {
            res = res / i * (i - 1);
            while(x % i == 0) x /= i;
        }
    }
    if(x > 1) res = res / x * (x - 1);
    return res; 
}

// 分析一下，gcd(a,b) = gcd (a+c,b) = x
// 等价于gcd(aa,bb) = gcd(aa + cc,bb) = 1
// aa + cc 与 bb互质，bb = b / x,求[aa,aa + bb)中有多少数和bb互质
// 等价于[0,bb)中有多少数和bb互质

int main()
{
    int t;
    cin >> t;
    while(t--){
        cin >> a >> m;
        ll t = gcd(a,m);
        ll mm = m / t;
        cout << phi(mm) << endl; 
    }
}