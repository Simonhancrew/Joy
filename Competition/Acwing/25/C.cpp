#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 2e5 + 10;

int m,n,k;
int cnt[N],c[N],p[N];
vector<int> S[N];

int find(int x){
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main(){
    cin >> n >> m >> k;
    for(int i = 1;i <= n;i++) {
        cin >> c[i];
        p[i] = i;
    }
    while(m--){
        int l,r;
        cin >> l >> r;
        p[find(l)] = find(r);
    }

    for(int i = 1;i <= n;i++) S[find(i)].push_back(i);
    int res = 0;
    for(int i = 1;i <= n;i++){
        int t = 0;
        if(S[i].size()){
            for(auto x : S[i]) t = max(t,++cnt[c[x]]);
            res += S[i].size() - t;
            // memset会超时
            for(auto x : S[i]) --cnt[c[x]];
        }
    }
    cout << res  << endl;
    return 0;
}