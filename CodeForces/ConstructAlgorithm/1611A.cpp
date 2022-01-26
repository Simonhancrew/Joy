#include <iostream>
#include <algorithm>
#include <cstring>

// Created by Simonhancrew on 2021/11/27

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

const int INF = 0x3f3f3f3f;

int t;
string s;

int main(){
    fast_cin();
    cin >> t;
    while(t--){
        cin >> s;
        int n = s.size();
        int l = s.front() - '0',r = s.back() - '0';
        if(r % 2 == 0) cout << 0 << endl;
        else{
            if(l % 2 == 0) cout << 1 << endl;
            else {
                if(n == 1) cout << -1 << endl;
                else{
                    bool flag = false;
                    for(int i = 1;i < n - 1;i++){
                        int tmp = s[i] - '0';
                        if(tmp % 2 == 0){
                            flag = true;
                            break;
                        } 
                    }
                    if(flag) cout << 2 << endl;
                    else cout << - 1 << endl;
                }
            } 
        }
    }
    return 0;
}