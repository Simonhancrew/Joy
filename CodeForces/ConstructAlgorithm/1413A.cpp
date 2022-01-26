#include <iostream>
#include <algorithm>
#include <cstring>

// Created by Simonhancrew on 2021/11/23

using namespace std;

const int N = 110;

int t,n;
int a[N];

int main(){
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1;i <= n;i++) cin >> a[i];
        for(int i = n;i > n / 2;i--) cout << -a[i] << ' ';
        for(int i = n / 2;i >= 1;i--) cout << a[i] << ' '; 
        cout << '\n';
    }
    return 0;
}