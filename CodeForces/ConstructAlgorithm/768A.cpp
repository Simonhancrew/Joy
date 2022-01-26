#include <iostream>
#include <algorithm>
#include <cstring>

// Created by Simonhancrew on 2021/12/17

using namespace std;

const int N = 1e5 + 10;

int n;
int a[N];

int main(){
    cin >> n;
    for(int i = 0;i < n;i++) cin >> a[i];
    if(n <= 2) cout << 0;
    else{
        int mx = -1,mn = 1e9 + 10;
        for(int i = 0;i < n;i++) {
            mx = max(mx,a[i]);
            mn = min(mn,a[i]);
        }
        int c1 = 0,c2 = 0;
        for(int i = 0;i < n;i++) {
            if(mx == a[i]) c1 ++;
            else if(mn == a[i]) c2++;
        }
        // cout << c1 << ' ' << c2 << '\n';
        cout << n - c1 - c2 << '\n';
    }
    return 0;
}