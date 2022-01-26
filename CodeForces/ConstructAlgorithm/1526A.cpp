#include <iostream>
#include <algorithm>
#include <cstring>

// Created by Simonhancrew on 2021/11/04

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

const int INF = 0x3f3f3f3f,N = 60;

int t,n;
int a[N];

int main(){
    // #define _DEBUG
    #ifdef _DEBUG
        freopen("input.txt","r",stdin);
        //freopen("output.txt","w",stdout);
    #endif
    fast_cin();
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0;i < 2 * n;i++) cin >> a[i];
        sort(a,a + 2 * n);
        for(int i = 0;i < n;i++) cout << a[i] << ' ' << a[i + n] << ' ';
        cout << endl;
    }   
    return 0;
}