#include <iostream>
#include <algorithm>
#include <cstring>

/*
    环形分组，一个N的时候无法完全拆环
    至少两个N
*/

using namespace std;

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

int t;
string s;

int main(){
    fast_cin();
    cin >> t;
    while(t--){
        cin >> s;
        if(count(s.begin(),s.end(),'N') != 1) cout << "YES"<<endl;
        else cout << "NO" <<endl;
    }
    return 0;
}