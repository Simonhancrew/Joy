#include <iostream>
#include <algorithm>
#include <cstring>

// Created by Simonhancrew on 2021/11/26

using namespace std;

typedef long long LL;

int t,a,b;

// 证明一个充要条件
/*
    a + b >= 4 * t,其中t是可以凑成的组数
    显然知道充分性容易直接得出，
    （3*x + 2 * y + 1 * z + bias1） + （x + 2 * y + 3 * z + bias2） >= 4t
    x + y + z  + bias1_2 >= t
    充要成立
*/

bool check(int x){
    if(a < x || b < x) return false;
    if(a - x + b - x >= 2 * x) return true;
    return false;
}

int main(){
    cin >> t;
    while(t--){
        cin >> a >> b;
        int res = 0;
        int mn = min(a,b);
        int l = 0,r = mn;
        while(l < r){
            int mid = l + r + 1 >> 1;
            if(check(mid)) l = mid;
            else r = mid - 1;
        }
        cout << l << endl;
    }
    return 0;
}