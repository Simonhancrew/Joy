#include <iostream>
#include <algorithm>
#include <cstring>

// Created by Simonhancrew on 2021/11/29

using namespace std;

int t,x,y;

int main(){
    cin >> t;
    while(t--){
        cin >> x >> y;
        int p = -1,q = -1;
        for(int i = 0;i < 51;i++) {
            for(int j = 0;j < 51;j++){
                if((i + j) * 2 == (x + y) && (abs(x - i) + abs(y - j)) * 2 == (x + y)) {
                    p = i,q = j;
                    break;
                }
            }
        }
        cout << p << ' ' << q << endl;
    }
    return 0;
}