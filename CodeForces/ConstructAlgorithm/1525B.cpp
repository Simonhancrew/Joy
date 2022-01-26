#include <iostream>
#include <algorithm>

// Created by Simonhancrew on 2021/12/15

using namespace std;

const int N = 60;

int t,n;
int a[N];

int main(){
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0;i < n;i++) cin >> a[i];
        int ans = 2;
        if(is_sorted(a,a + n)) ans = 0;
        else if(a[0] == 1 || a[n - 1] == n) ans = 1;
        else if(a[0] == n && a[n - 1] == 1) ans = 3;
        cout << ans << endl;
    }
    return 0;
}