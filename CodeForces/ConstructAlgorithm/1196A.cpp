#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

int t;
LL a,b,c;

int main(){
    // freopen("input.txt","r",stdin);
    cin.sync_with_stdio(false);
    cin >> t;
    while(t--){
        cin >> a >> b >> c;
        cout << (a + b + c) / 2 << endl;
    }
    return 0;
}