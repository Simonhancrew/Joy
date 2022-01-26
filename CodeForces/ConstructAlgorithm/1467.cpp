#include <iostream>
#include <algorithm>
#include <cstring>

// Created by Simonhancrew on 2021/12/12

using namespace std;

// 直接改第二位是8的时候就行了，保证左边的最大

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

int t,n;

int main(){
    fast_cin();
    cin >> t;
    while(t--){
        cin >> n;
        string s = "989";
        if(n <= 3) cout << s.substr(0,n);
        else{
            cout << s;
            for(int i = 0;i < n - 3;i++){
                cout << i % 10;
            }
        }
        cout << '\n';
    }
    return 0;
}