#include <iostream>
#include <algorithm>
#include <cstring>

// Created by Simonhancrew on 2021/11/07

using namespace std;

string s;

bool ispa(string& s){
    for(int i = 0,j = s.size() - 1;i < j;i++,j--){
        if(s[i] != s[j]) return false;
    }
    return true;
}

int main(){
    cin >> s;
    if(ispa(s)) cout << s << endl;
    else{
        cout << s ;
        reverse(s.begin(),s.end());
        cout << s;
    }
    return 0;
}