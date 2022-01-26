#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
using LL = long long;

// 组合数，脑筋急转弯 

const int mod = 1e9 + 7;
const int N = 1e4 + 10;
int fact[N],infact[N];

int qmi(int a, int k, int p)  // 求a^k mod p
{
    int res = 1 % p;
    while (k)
    {
        if (k & 1) res = (LL)res * a % p;
        a = (LL)a * a % p;
        k >>= 1;
    }
    return res;
}

// 等价于把a数组reverse一下接到b后面，形成一个长度为2 * m的递减数组
// 等价于从n中挑选2 * m个数，转换成2 * m个数放进n个盒子中
// 组合数学的原理，用隔板法解决，因为允许为空，所以先给每个盒子放一个球
// 则总共需要放（2m + n）个球，一共有（2m + n - 1）个空隙，将n - 1个隔板放如这些空隙
// 组合数的公式就是C(2m + n - 1,n - 1)

int main(){
    int n,m;
    cin.sync_with_stdio(false);
    cin >> n >> m;
    int a = 2 * m + n - 1,b = n - 1;
    fact[0] = 1,infact[0] = 1;
    for(int i = 1;i < N;i++){
        fact[i] = (LL)fact[i - 1] * i % mod;
        // 乘法逆元a / b = a * x 
        // b * x = 1 % mod=>费马小定理=> b * x = b ^ (mod - 1) % mod => x = b ^ (mod - 2) % mod
        infact[i] = (LL)infact[i - 1] * qmi(i,mod - 2,mod) % mod;
    }
    auto f = [](int a,int b) {
        return (LL)fact[a] * infact[b] % mod * infact[a - b] % mod;
    };
    cout << f(a,b) << endl;
}