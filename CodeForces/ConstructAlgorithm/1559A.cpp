#include <iostream>
#include <algorithm>
#include <cstring>

// Created by Simonhancrew on 2021/12/16

using namespace std;

const int N = 110;

int t,n;
int a[N];

int main(){
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0;i < n;i++) cin >> a[i];
        int res = a[0];
        for(int i = 1;i < n;i++) res &= a[i];
        cout << res << '\n';
    }
    return 0;
}