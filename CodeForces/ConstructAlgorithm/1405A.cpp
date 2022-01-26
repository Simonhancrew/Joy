#include <iostream>
#include <algorithm>

// Created by Simonhancrew on 2021/11/05

using namespace std;
const int N = 110;

int t,n;
int a[N];

int main(){
    cin >> t ;
    while(t--){
        cin >> n;
        for(int i = 0;i < n;i++) cin >> a[i];
        reverse(a,a + n);
        for(int i = 0;i < n;i++) cout << a[i] << ' ';
        cout << endl;
    }
    return 0;
}