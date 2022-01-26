#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e3 + 10;

int n,m;
char g[N][N];
int f[N][N],st[N][N];
bool is_inf;
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};


int dp(int x,int y){
    // 有环就没必要做了，状态只能一个个的转移，有无穷的一定后续不必判断
    if(is_inf) return -1;
    // 搜过就不搜了
    int& v = f[x][y];
    if(v != -1) return v;
    // 当前没搜过
    v = 1;
    // 开始搜索，为了判环，需要记录起始位置。
    // 接下来就是一个记忆化的板子
    st[x][y] = true;
    for(int i = 0;i < 4;i++){
        int nx = x + dx[i],ny = y + dy[i];
        if(nx >= 0 && nx < n && ny >= 0 && ny < m && g[nx][ny] == (g[x][y] + 1) % 4){
            if(st[nx][ny]){
                is_inf = true;
                return -1;
            }
            v = max(v,dp(nx,ny) + 1);
        }
    }
    st[x][y] = false;
    return v;
}


int main()
{
    cin >> n >> m;
    for(int i = 0;i < n;i++) cin >> g[i];
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            auto &t = g[i][j];
            if(t == 'Q') t = 0;
            else if(t == 'W') t = 1;
            else if(t == 'E') t = 2;
            else t = 3;
        }
    }
    
    memset(f,-1,sizeof f);
    
    int res = 0;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            // 这里从每个位置开始搜，结果去去掉前面的。
            int t = dp(i,j);
            if(g[i][j]) t -= 4 - g[i][j];
            res = max(res,t / 4);
        }
    }
    if(is_inf) puts("infinity");
    else if(res == 0) puts("none");
    else cout << res << endl;
}