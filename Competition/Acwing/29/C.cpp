#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

// 反向推一遍路径就可以了

typedef long long LL;

const int N = 1e5 + 10,M = 2 * N;

queue<int> q;
int n,m;
int e[M],ne[M],h[N],w[M],idx;
LL dist[N];
int pre[N],path[N];
int st[N];

void add(int a,int b,int c){
    e[idx] = b,ne[idx] = h[a],w[idx] = c,h[a] = idx++;
}


void spfa(){
    memset(pre,-1,sizeof pre);
    memset(dist,0x3f,sizeof dist);
    dist[1] = 0;
    q.push(1);
    st[1] = true;
    while(q.size())  {
        int t = q.front();
        q.pop();
        st[t] = false;
        for(int i = h[t];i != -1;i = ne[i]) {
            int j = e[i];
            if(dist[j] > dist[t] + w[i]) {
                dist[j] = dist[t] + w[i];
                pre[j] = t;
                if(!st[j]) {
                    st[j] = true;
                    q.push(j);
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n >> m;
    memset(h, -1, sizeof h);
    while(m--) {
        int a,b,c;
        cin >> a >> b >> c;
        add(a,b,c),add(b,a,c);
    }
    spfa();
    if(pre[n] == -1) cout << -1 << endl;
    else {
        int cnt = 0;
        for(int i = n;i != -1;i = pre[i]){
            path[cnt++] = i;
        }
        for(int i = cnt - 1;i >= 0;i--) cout << path[i] << ' '; 
    }
    return 0;
}