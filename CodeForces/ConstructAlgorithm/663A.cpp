#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

int t,n;

int main(){
    // freopen("input.txt","r",stdin);
    cin.sync_with_stdio(false);
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1;i <= n;i++) cout << i << ' ';
        cout << endl;
    }
    return 0;
}