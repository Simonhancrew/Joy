#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>

// Created by Simonhancrew on 2021/11/07

using namespace std;

int t;
string s;

bool ispa(const string& s){
    int l = 0,r = s.size() - 1;
    while(l < r){
        if(s[l] != s[r]) return false;
        ++l,--r;
    }
    return true;
}

int main(){
    cin >> t;
    while(t--){
        cin >> s;
        if(!ispa(s+"a")){
            cout << "YES" << endl;
            cout << s + "a" << endl;
        }else if(!ispa("a" + s)){
            cout << "YES" << endl;
            cout << "a" + s << endl;
        }else{
            cout << "NO" <<endl;
        }
    }
    return 0;
}