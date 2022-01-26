#include <iostream>
#include <algorithm>
#include <cstring>

// Created by Simonhancrew on 2021/10/28

using namespace std;

int k,r;

int main(){
    cin.sync_with_stdio(false);
    cin >> k >> r;
    int res = 1;
    int t = k;
    while(k % 10 != r && k % 10 != 0){
        res++;
        k += t;
    }
    cout << res << endl;
    return 0;
}