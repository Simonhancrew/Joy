#include <iostream>

using namespace std;

typedef long long LL;

int t;
LL l,r;

int main(){
    // freopen("input.txt","r",stdin);
    cin.sync_with_stdio(false);
    cin >> t;
    // x < y => lcm(x,y) >= 2 * x && lcm(x,y) >= y
    // 则令x最小，则lcm最小2 * l,令y = 2 * l
    while(t--){
        cin >> l >> r;
        if(l * 2 > r) cout << -1 << ' ' << -1 << endl;
        else cout << l << ' ' << 2 * l << endl; 
    }
    return 0;
}