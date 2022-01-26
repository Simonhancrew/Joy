#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main(){
    string s;
    cin >> s;
    int res = 0;
    for(auto c : s){
        if(!isdigit(c)) res += c - 'A' + 1;
        else if(c == '1') res += 10;
        else res += c - '0';
    }
    cout << res << endl;
}