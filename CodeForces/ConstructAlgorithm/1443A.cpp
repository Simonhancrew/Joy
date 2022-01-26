#include <iostream>
#include <algorithm>
#include <cstring>

// Created by Simonhancrew on 2021/11/19

using namespace std;

int t,n;

int main(){
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 4 * n;i > 2 * n;i -= 2) cout << i << ' ';
        cout << endl;
    }
    return 0;
}