#include <iostream>
#include <algorithm>
#include <cstring>

// Created by Simonhancrew on 2021/10/29

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

const int INF = 0x3f3f3f3f;

int t,x;

int gcd(int a,int b){
    return b ? gcd(b,a % b) : a;
}

// int lcm(int a,int b){
//     return (LL)a * b / gcd(a,b);
// }

int main(){
    // #define _DEBUG
    #ifdef _DEBUG
        freopen("input.txt","r",stdin);
        //freopen("output.txt","w",stdout);
    #endif
    fast_cin();
    cin >> t;
    while(t--){
        // 1 和 x - 1是work的
        cin >> x;
        cout << 1 << ' ' << x - 1 << endl;
    }
    return 0;
}