#include <iostream>
#include <algorithm>
#include <cstring>

// Created by Simonhancrew on 2021/11/08

using namespace std;

const int N = 110;

int n,a,b;
int st[N];

int main(){
    cin >> n >> a >> b;
    for(int i = 1;i <= a;i++){
        int t;
        cin >> t;
        st[t] = 1;
    }    
    for(int i = 1;i <= b;i++){
        int t;
        cin >> t;
        if(!st[t]) st[t] = 2;
    }
    for(int i = 1;i <= n;i++){
        cout << st[i] << ' '; 
    }
    cout << endl;
    return 0;
}