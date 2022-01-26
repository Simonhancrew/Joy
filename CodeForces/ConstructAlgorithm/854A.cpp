#include <iostream>
#include <algorithm>
#include <cstring>

// Created by Simonhancrew on 2021/11/28

using namespace std;

int n;

int gcd(int a,int b){
    return b ? gcd(b,a % b) : a;
}

int main(){
    cin >> n;
    double res = 0;
    int x,y;
    for(int i = 1;i <= n / 2;i++){
        int j = n - i;
        if(j == i) break;
        if(gcd(i,j) == 1) {
            if(res < (double(i) / double(j))){
                x = i,y = j;
                res = double(i) / double(j);
            }
        }
    }
    cout << x << ' ' << y << endl;
    return 0;
}