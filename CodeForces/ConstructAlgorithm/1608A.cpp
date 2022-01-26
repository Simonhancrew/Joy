#include <iostream>
#include <algorithm>
#include <cstring>

// Created by Simonhancrew on 2021/12/15

using namespace std;

int t,n;

int main(){
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 2;i <= n + 1;i++) cout << i << ' ';
        cout << '\n';
    }
    return 0;
}