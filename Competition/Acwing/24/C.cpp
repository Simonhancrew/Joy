#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair<int, int> PII;

#define x first
#define y second

const int N = 2e5 + 10;

int n,m,u;
int p[N],a[N],b[N];
int st[N];

// pop从尾部pop的
struct cmp{
    bool operator() (PII &lhs,PII &rhs) {
        return lhs.x < rhs.x;
    }
};

int main(){
    // freopen("input.txt","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i = 0;i < n;i++) cin >> p[i];
    for(int i = 0;i < n;i++) cin >> a[i];
    for(int i = 0;i < n;i++) cin >> b[i];
    
    priority_queue<PII,vector<PII>,cmp> q[3];
    for(int i = 0;i < n;i++){
        --a[i],--b[i];
        q[a[i]].push({p[i], i});
        q[b[i]].push({p[i], i});
    }
    cin >> m;
    // 延迟删除
    for(int i = 0;i < m;i++){
        cin >> u;
        u--;
        bool flag = false;
        while(q[u].size()){
            auto t = q[u].top();
            q[u].pop();
            if(st[t.y] == 1) continue;
            else{
                cout << t.x << ' ';
                flag = true;
                st[t.y] = 1;
                break;
            }
        }
        if(!flag) cout << -1 <<' ';
    }
    return 0;
}