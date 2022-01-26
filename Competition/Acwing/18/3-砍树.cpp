#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;


// 边没开够，23333
const int M = 1e5 + 10,N = 2 * M;

int n;
int ans;
int h[N],e[N],ne[N],idx;

void add(int a,int b){
    e[idx] = b,ne[idx] = h[a],h[a]=idx++;
}


// 无向图，防止往回搜
int dfs(int u,int fa){
    int d = 1;
    for(int i = h[u];i != -1;i = ne[i]){
        int j = e[i];
        if(j == fa) continue;
        int cnt = dfs(j,u);
        if(cnt % 2 == 0) ans++;
        d += cnt;
    }
    return d;
}

int main(){
    cin >> n;
    if(n & 1) {
        cout << -1 << endl;
        return 0;
    }
    memset(h,-1,sizeof h);
    while(--n){
        int a,b;
        cin >> a >> b;
        add(a,b),add(b,a);
    }
    dfs(1,-1);
    cout << ans << endl;
}