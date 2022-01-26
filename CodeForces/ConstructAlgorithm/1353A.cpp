#include <iostream>
#include <algorithm>
#include <cstring>

// Created by Simonhancrew on 2021/10/28

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

const int INF = 0x3f3f3f3f;

int t,n;
LL m;

int main(){
    // #define _DEBUG
    #ifdef _DEBUG
        freopen("input.txt","r",stdin);
        //freopen("output.txt","w",stdout);
    #endif
    fast_cin();
    cin >> t;
    while(t--){
        // 构造的时候找规律就行了，[0,m,0]
        cin >> n >> m;
        #if 0
        if(n == 1) cout << 0 << endl;
        else if(n == 2) cout << m << endl;
        else cout << m * 2 << endl;
        #endif
        cout << min(2,n - 1) * m << endl;
    }
    return 0;
}