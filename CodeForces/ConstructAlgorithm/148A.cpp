#include <iostream>
#include <algorithm>
#include <cstring>

// Created by Simonhancrew on 2021/10/27

using namespace std;

int k,l,m,n,d;

int main(){
    cin.sync_with_stdio(false);
    cin >> k >> l >> m >> n >> d;
    int res = 0;
    for(int i = 1;i <= d;i++)
        if(i % k == 0 || i % l == 0 || i % m == 0 || i % m == 0 || i % n == 0) ++res;
    cout << res << endl;
    return 0;
}