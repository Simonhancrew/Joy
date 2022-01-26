#include <iostream>
#include <algorithm>
#include <cstring>

// Created by Simonhancrew on 2021/11/09

using namespace std;

const int N =  2e5 + 10;

int n;
int a[N];

int main(){
    cin >> n;
    int st1 = 0,st2 = 0;
    for(int i = 0;i < n;i++){
        int t;
        cin >> t;
        if(t == 1) st1++;
        else st2++;
    }
    int res = 0;
    if(st1 && st2){
        int mn = min(st1,st2);
        res+=mn;
        st1-=mn;
        st2-=mn;
    }
    if(st1 >= 3) res += st1 / 3;
    cout << res << endl;
    return 0;
}