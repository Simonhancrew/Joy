#include <iostream>
#include <algorithm>
#include <cstring>

// Created by Simonhancrew on 2021/12/02

using namespace std;

int t,n,k;

int main(){
    cin >> t;
    while(t--){
        cin >> n >> k;
        if(n  < k) cout << k - n << '\n';
        else if(n % 2 == k % 2) cout << 0 << '\n';
        else cout << 1 << '\n'; 
    }
    return 0;
}