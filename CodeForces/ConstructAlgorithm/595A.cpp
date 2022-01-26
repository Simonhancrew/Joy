#include <iostream>
#include <algorithm>
#include <cstring>

// Created by Simonhancrew on 2021/11/24

using namespace std;

int n,m;

int main(){
    cin >> n >> m;
    int res = 0;
    for(int i = 0;i < n;i++){
        for(int i = 0;i < 2 * m;i += 2){
            int l,r;
            cin >> l >> r;
            if(l || r) ++res;
        }
    }
    cout << res << endl;
    return 0;
}