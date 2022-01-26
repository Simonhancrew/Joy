#include <iostream>
#include <algorithm>
#include <cstring>

// Created by Simonhancrew on 2021/12/01

using namespace std;

int t,n,a,b;

int main(){
    cin >> t;
    while(t--){
        cin >> n >> a >> b;
        for(int i = 0;i < n;i++){
            cout << char('a' + i % b);
        }
        cout << endl;
    }
    return 0;
}