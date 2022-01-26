#include <iostream>
#include <algorithm>
#include <cstring>

// Created by Simonhancrew on 2021/11/22

using namespace std;

const int N  = 110;

int t,n;
int a[N],b[N];


int main(){
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0;i < n;i++) cin >> a[i];
        for(int i = 0;i < n;i++) cin >> b[i];
        sort(a,a + n);
        sort(b,b + n);
        for(int i = 0;i < n;i++) cout << a[i] << ' ';
        cout << endl;
        for(int i = 0;i < n;i++) cout << b[i] << ' ';
        cout << endl;
    }
    return 0;
}