#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>

// Created by Simonhancrew on 2021/11/20

using namespace std;

int t;
string s;

int main(){
    cin >> t;
    while(t--){
        cin >> s;
        /*
            s的mex最大是2，因为序列中只有01
            全0的话mex是1，全1的话是2
            0和1恰好分成两部分，则可以是1
            否则一定大于等于2
        */
        int cnt = count(s.begin(),s.end(),'0');
        if(cnt == 0) cout << '0' << endl;
        else{
            int l = s.find('0'),r = s.rfind('0');
            if(r - l + 1 == cnt) cout << '1' << endl;
            else cout << '2' << endl;
        }
    }    
    return 0;
}