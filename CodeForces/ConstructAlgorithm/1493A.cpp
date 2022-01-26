#include <iostream>
#include <algorithm>
#include <cstring>

// Created by Simonhancrew on 2021/11/14

using namespace std;

int n,k,t;

int main(){
    cin >> t;
    while(t--){
        cin >> n >> k;
        // [k + 1,n] + 后一半的[1,k - 1]
        cout << n - k + k / 2 << endl;
        for(int i = k + 1;i <= n;i++) cout << i << ' ';
        for(int i = (k + 1) / 2;i <= k - 1;i++) cout << i << ' ';
        cout << endl;
    }
    return 0;
}