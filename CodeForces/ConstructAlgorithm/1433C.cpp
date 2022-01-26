#include <iostream>
#include <algorithm>

// Created by Simonhancrew on 2021/12/04

using namespace std;

/*
    全部一样的话 -1
    否则找到最大的
*/

const int N = 3e5 + 10;

int t,n;
int a[N];

int main(){
    cin >> t;
    while(t--){
        cin >> n;
        int mx = -1;
        for(int i = 1;i <= n;i++) {
            cin >> a[i];
            mx = max(mx,a[i]);
        }   
        int res = -1;
        for(int i = 1;i <= n;i++) {
            if(a[i] != mx) continue;
            if(i >= 2 && a[i - 1] != mx) {
                res = i;
                break;
            }
            if(i < n && a[i + 1] != mx) {
                res = i;
                break;
            }            
        }
        cout << res << endl;
    }
    return 0;
}