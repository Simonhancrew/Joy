#include <iostream>
#include <algorithm>
#include <cstring>

// Created by Simonhancrew on 2021/11/11

using namespace std;

int t,n;

int main(){
    cin >> t;
    while(t--){
        cin >> n;
        /*
            构造体，最开始()()()()
            之后前四个合并（（））。。。。
            再之后前6个合并。。。。。
        */
        for(int i = 0;i < n;i++){
            for(int j = 0;j < i;j++) cout << "()";
            for(int j = 0;j < n - i;j++) cout << "(";
            for(int j = 0;j < n - i;j++) cout << ")";
            cout << endl;
        }
    }    
    return 0;
}