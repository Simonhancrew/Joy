#include <iostream>
#include <algorithm>
#include <cstring>

// Created by Simonhancrew on 2021/11/10

using namespace std;

const int N = 110;

int t,n;
int a[N];
bool f;

int main(){
    cin >> t;
    while(t--){
        cin >> n;
        f = false;
        for(int i = 0;i < n;i++) {
            cin >> a[i];
            if(a[i] < 0){
                f = true;
            }
        }
        if(f) cout << "NO" << endl;
        else{
            cout << "YES" << endl;
            cout << 101 << endl;
            for(int i = 0;i <= 100;i++){
                cout << i << ' ';
            }
            cout << endl;
        }
    }
    return 0;
}