#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>

// Created by Simonhancrew on 2021/10/27

using namespace std;

string s;
int a[26];

// 有空格的时候getline读一整行放到string中

int main(){
    cin.sync_with_stdio(false);
    getline(cin,s);
    int n = s.size();
    for(int i = 1;i < n - 1;i++){
        if(s[i] >= 'a' && s[i] <= 'z'){
            a[s[i] - 'a']++;
        }
    }
    int res = 0;
    for(int i = 0;i < 26;i++){
        if(a[i] != 0) res++;
    } 
    cout << res << endl;
    return 0;
}