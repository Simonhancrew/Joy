#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>

// Created by Simonhancrew on 2021/11/18

using namespace std;

/*
    找规律，trygub不是字典序，直接让s字典序就ok
*/

int t,n;
string s;

int main(){
    cin >> t;
    while(t--){
        cin >> n >> s;
        sort(s.begin(),s.end());
        cout << s << endl;
    }    
    return 0;
}