#include <iostream>
#include <algorithm>

// Created by Simonhancrew on 2021/11/25

using namespace std;

const int N = 110;

int a[N];

int main(){
    int n;
    cin >> n;
    int l,r;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        if(a[i] == 1) l = i;
        else if(a[i] == n) r = i;
    }
    if(abs(l - r) == n - 1) cout << n - 1;
    else{
        int res = abs(r - l);
        res = max(res,abs(r - 1));
        res = max(res,abs(r - n));
        res = max(res,abs(l - 1));
        res = max(res,abs(l - n));
        cout << res << endl;
    }
    return 0;
}