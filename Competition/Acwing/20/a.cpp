#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

// 简单的ceil

int main(){
    int t;
    cin >> t;
    while(t--){
        int a,b,c,d,k;
        cin >> a >> b >> c >> d >> k;
        int na = (a + c - 1) / c,nb = (b + d - 1) / d;
        if(na + nb > k) cout << -1 << endl;
        else cout << max(k - nb,na) << ' ' << nb << endl;
    }
}