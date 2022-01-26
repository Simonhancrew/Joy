#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

// 状态比较有限，直接枚举所有的排列就可以了。

using namespace std;

const int N = 55;

char g[N][N];
int n,m;
string path;

int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

bool check(vector<int> &q){
    int x,y;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            if(g[i][j] == 'S'){
                x = i,y = j;
                break;
            }
        }
    }
    
    for(auto c:path){
        int t = q[c - '0'];
        x += dx[t],y += dy[t];
        if(x < 0 || x >= n || y < 0 || y >= m || g[x][y] == '#'){
            return false;
        }
        if(g[x][y] == 'E') return true;
    }
    return false;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i = 0;i < n;i++) cin >> g[i];
        cin >> path;
        vector<int> q{0,1,2,3};
        int res = 0;
        for(int i = 0;i < 24;i++){
            if(check(q)) res++;
            next_permutation(q.begin(),q.end());
        }
        cout << res << endl;
    }
    return 0;
}