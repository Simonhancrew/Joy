#include <iostream>
#include <algorithm>
#include <cstring>

// Created by Simonhancrew on 2021/11/23

using namespace std;

int n;

int main(){
    cin >> n;
    // n <= 2的时候啥事都做不了
    // n >= 3的时候n-1不是一个n的约数，可以凑到1
    if(n == 2) cout << 2;
    else cout << 1;
    return 0;
}