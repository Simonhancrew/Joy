#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 410,INF = 0x3f3f3f3f;

int f[N][N],g[N][N];

int n,m;

int floyd(int d[N][N]){
    if(d[1][n] != INF) return 1;
    for(int k = 1;k <= n;k++){
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= n;j++){
                d[i][j] = min(d[i][j],d[i][k] + d[k][j]);
            }
        }
    }
    return d[1][n];
}


int main(){
    cin >> n >> m;
    memset(f,0x3f,sizeof f);
    memset(g,0x3f,sizeof g);
    for(int i = 0;i < m;i++) {
        int u,v;
        cin >> u >> v;
        f[u][v] = f[v][u] = 1;
    }
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            if(i != j && f[i][j] != 1) g[i][j] = g[j][i] = 1;
        }
    }
    int a = floyd(f),b = floyd(g);
    int res = max(a,b);
    if(res == INF) cout << -1 << endl;
    else cout << res << endl;
    return 0;
}