#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int gcd(int a,int b) {
    return b == 0 ? a : gcd(b,a % b);
}

int main(){
    int a,b,q;
    cin >> a >> b >> q;
    int g = gcd(a,b);
    vector<int> ans;
    for(int i = 1;i <= g / i;i++) {
        if(g % i == 0) {
            ans.push_back(i);
            if(i != g / i) {
                ans.push_back(g / i);
            }
        }
    }
    sort(ans.begin(),ans.end());
    while(q--){
        int l,r;
        cin >> l >> r;
        int pos = upper_bound(ans.begin(),ans.end(),r) - ans.begin();
        pos--;
        if(pos >= 0 && pos < ans.size() && ans[pos] >= l) {
            cout << ans[pos] << endl;
        }else {
            cout << -1 << endl;
        }
    }
}