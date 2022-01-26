#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;

const int N = 2e5 + 10;

// 1e18,需要考虑快读
#define fast_cin() ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef long long LL;

// 差分的思想，记录两个端点，左加右减。
// 针对每个区间统计被覆盖的次数之后累加

int n;
map<LL,int> b;
LL ans[N];

int main(){
    fast_cin();
    cin >> n;
    for(int i = 0;i < n;i++){
        LL l,r;
        cin >> l >> r;
        b[l]++,b[r + 1]--;
    }
    LL sum = 0,last = -1;
    for(auto &[k,v] : b){
        if(last != -1) ans[sum] += k - last;
        last = k;
        sum += v;
    }
    for(int i = 1;i <= n;i++){
        cout << ans[i] << ' ';
    }
    return 0;
}