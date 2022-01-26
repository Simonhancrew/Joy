#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 60,INF = 0x3f3f3f3f;
typedef pair<int, int> PII;

int n;
int a,b,x,y;
char g[N][N];
int st[N][N];
vector<PII> p1,p2;

int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

void dfs(int x,int y,vector<PII>& p){
    if(st[x][y] != 0){
        return;
    }   
    st[x][y] = 1;
    p.push_back({x,y});
    for(int i = 0;i < 4;i++){
        int nx = x + dx[i],ny = y + dy[i];
        if(nx >= 0 && nx < n && ny >= 0 && ny < n && !st[nx][ny] && g[nx][ny] == '0'){
            dfs(nx,ny,p);
        }
    }
}

int main(){
    cin >> n >> a >> b >> x >> y;
    for(int i = 0;i < n;i++){
        cin >> g[i];
    }
    dfs(a - 1,b - 1,p1);
    if(st[a - 1][b - 1] == st[x - 1][y - 1]){
        cout << 0 << endl;
        return 0;
    }
    dfs(x - 1,y - 1,p2);
    int res = INF;
    for(auto& [x1,y1] : p1){
        for(auto& [x2,y2] : p2){
            res = min((x1 - x2)*(x1 - x2) + (y1 - y2) * (y1- y2),res);
        }
    }
    cout << res <<endl;
    return 0;
}