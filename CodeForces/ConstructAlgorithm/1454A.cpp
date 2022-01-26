#include <iostream>
#include <algorithm>
#include <cstring>

// Created by Simonhancrew on 2021/10/29

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

const int INF = 0x3f3f3f3f;

int n;

int main(){
    // #define _DEBUG
    #ifdef _DEBUG
        freopen("input.txt","r",stdin);
        //freopen("output.txt","w",stdout);
    #endif
    fast_cin();
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 2;i <= n;i++){
            cout << i << ' ';
        }
        cout << 1 <<endl;
    }
    return 0;
}