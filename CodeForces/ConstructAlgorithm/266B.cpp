#include <iostream>
#include <algorithm>
#include <cstring>

// Created by Simonhancrew on 2021/10/27

using namespace std;

const int N = 60;

string s;
int n,t;

int main(){
    cin.sync_with_stdio(false);
    cin >> n >> t;

    cin >> s;
    while(t--){
        for(int i = 0;i < n - 1;i++){
            if(s[i] == 'B' && s[i + 1] =='G'){
                swap(s[i],s[i + 1]);
                i++;
            }
        }
    }    
    cout << s << endl;
    return 0;
}