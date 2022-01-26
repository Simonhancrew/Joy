#include <iostream>

// Created by Simonhancrew on 2021/11/16

using namespace std;

int t,n,k;

int main(){
    cin >> t;
    while(t--){
        cin >> n >> k;
        for(int i = 0;i < n;i++) cout << (char)('a' + i % 3);
        cout << endl;
    }
    return 0;
}