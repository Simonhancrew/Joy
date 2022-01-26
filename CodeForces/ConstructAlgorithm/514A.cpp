#include <iostream>

// Created by Simonhancrew on 2021/11/15

using namespace std;

int n1,n2,k1,k2;

int main(){
    cin >> n1 >> n2 >> k1 >> k2;
    if(n1 <= n2) cout << "Second";
    else cout << "First";
    return 0;
}