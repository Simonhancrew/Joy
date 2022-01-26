#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

// 高精度 + 优化
void add(string& s){
    int carry = 1;
    for(int i = s.size() - 1;i >= 0;i--){
        int cur = carry + s[i] - '0';
        s[i] = cur % 2 + '0';
        carry = cur / 2;
        if(carry == 0) break;
    }
    if(carry) s.insert(0,1,'1');
}

using LL = long long;

int main(){
    string s;
    cin >> s;
    LL cnt = 0;
    while(s.size() > 1 || (s.size() == 1 && s[0] != '1')){
        if(s.back() == '1') add(s);
        else s.pop_back();
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}

