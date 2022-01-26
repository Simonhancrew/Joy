#include <iostream>
#include <algorithm>
#include <cstring>

// Created by Simonhancrew on 2021/11/25

using namespace std;


int main(){
    int n,k;
    cin >> n >> k;
    int idx = 0;
    for(int i = 0;i < n;i++){
        bool flag = true;
        for(int j = 0;j < n;j++){
            if(flag && j == idx) flag = false,idx++,cout << k << ' ';
            else cout << 0 << ' ';
        }
        cout << endl;
    }
    return 0;
}