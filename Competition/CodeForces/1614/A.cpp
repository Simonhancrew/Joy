#include <iostream>
#include <algorithm>
#include <cstring>
 
// Created by Simonhancrew on 2021/11/26
 
using namespace std;
 
const int INF = 0x3f3f3f3f,N = 110;
 
int t,n,l,r,k;
int a[N];
 
int main(){
    cin >> t;
    while(t--){
        cin >> n >> l >> r >> k;
        for(int i = 0;i < n;i++) cin >> a[i];
        sort(a,a + n);
        int res = 0;
        for(int i = 0;i < n;i++) {
            if(a[i] >= l  && a[i] <= r && k >= a[i]) {
                k -= a[i];
                res++;
            }
        }
        cout << res << endl;
    }
    return 0;
}