#include <iostream>
#include <algorithm>
#include <cstring>

// Created by Simonhancrew on 2021/12/29

using namespace std;

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)


int n;

int main(){
    fast_cin();
    cin >> n;
    if(n <= 2) cout << -1 << '\n';
    else{
        for(int i = n ;i >= 1;i--){
            cout << i << ' ';
        }
        cout << '\n';
    }
    return 0;
}