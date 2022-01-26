#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10,mod = 1e9 + 7;

typedef long long LL;

int t,k,l,r;
LL f[N];

/*
    首先f[i],长度为i的好字符串的数量
    i < k的时候，只能全0，所以f[i] = 1
    i >= k的时候，
        最后一个字符是0的话，数量和f[i - 1]相等
        最后一个字符是1的话，必须有k个连续的1，此时的数量和f[i - k]相等
    所以第二种情况的f[i] = f[i - 1] + f[i - k]
    处理[l,r]一共有多少个数直接前缀和就可以了
*/

void init(){
    for(int i = 0;i < N;i++){
        if(i < k) f[i] = 1;
        else{
            f[i] = (f[i - 1] + f[i - k]) % mod;
        }
    }   
    for(int i = 1;i < N;i++){
        f[i] += f[i - 1];
    }
}

int main(){
    cin >> t >> k;
    init();
    while(t--){
        cin >> l >> r;
        cout << (f[r] - f[l- 1]) % mod << endl;
    }
    return 0;
}