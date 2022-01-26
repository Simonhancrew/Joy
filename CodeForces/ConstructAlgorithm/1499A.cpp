#include <iostream>
#include <algorithm>
#include <cstring>

// Created by Simonhancrew on 2021/11/06

using namespace std;

int t,n,k1,k2,w,b;

// 推一下怎么放，可以知道2 * w <= k1 + k2;就成立

int main(){
    cin >> t;
    while(t--){
        cin >> n >> k1 >> k2;
        cin >> w >> b;
        if(k1 + k2 >= 2 * w && (n - k1) + (n - k2) >= 2 * b) cout << "YES" <<endl;
        else cout << "NO" << endl;
    }    
    return 0;
}