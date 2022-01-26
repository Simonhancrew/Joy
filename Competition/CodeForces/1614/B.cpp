#include <iostream>
#include <algorithm>
#include <cstring>
 
// Created by Simonhancrew on 2021/11/26
 
using namespace std;
 
typedef long long LL;
typedef pair<int,int> PII;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
 
const int N = 2e5 + 10,INF = 0x3f3f3f3f;
 
int t,n;
PII a[N];
int b[N];
 
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
        for(int i = 1;i <= n;i++) {
            int tmp;
            cin >> tmp;
            a[i] = {i,tmp};
        }
        sort(a + 1,a + n + 1,[](PII lhs,PII rhs){
            return lhs.second > rhs.second;
        });
        LL res = 0;
        for(int i = 1;i <= n;i++){
            int flag = 1;
            if((i & 1) == 0) flag = -1;
            int idx = flag * ((i + 1) / 2),time = a[i].second;
            res += 2 * (LL)abs(idx) * time;
            b[a[i].first] = idx;  
        }
        cout << res << endl;
        cout << 0 << ' ';
        for(int i = 1;i <= n;i++) cout << b[i] << ' ';
        cout << endl;
    }
    return 0;
}