#define x first
#define y second 

const int dx[4] = {0,-1,0,1},dy[4] = {-1,0,1,0};

class Solution {
public:
    using PII = pair<int,int>;
    vector<vector<int>> g;
    int n,m;

    vector<vector<bool>> st;
    vector<PII> path;
    set<PII> nei;

    int dfs(int x,int y) {
      st[x][y] = true;
      path.push_back({x,y});
      int ans = 0;
      for(int i = 0;i < 4;i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if(nx < 0 || nx >= n || ny < 0 || ny >= m) {
          continue;
        }
        if(g[nx][ny] == 0) nei.insert({nx,ny}),ans++;
        else if(g[nx][ny] == 1 && !st[nx][ny]) {
          ans += dfs(nx,ny);
        }
      }
      return ans;
    }

    int find() {
      st = vector<vector<bool>> (n,vector<bool>(m));
      int ans = 0,cnt = 0;
      vector<PII> pt;
      vector<set<PII>> neis;

      for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++) {
          if(g[i][j] == 1 && !st[i][j]) {
            path.clear(),nei.clear();
            int fire_wall = dfs(i,j);
            if(nei.size() > cnt) {
              cnt = nei.size();
              pt = path;
              ans = fire_wall;
            }
            neis.push_back(nei);
          }
        }
      }
      for(auto p : pt) {
        g[p.x][p.y] = -1;
      }
      for(auto nei : neis) {
        if(nei.size() != cnt) {
          for(auto [x,y] : nei) {
            g[x][y] = 1;
          }
        }
      }
      return ans;
    }

    int containVirus(vector<vector<int>>& isInfected) {
      g = isInfected;
      n = g.size(),m = g[0].size();
      int ans = 0;
      while(true) {
        int fire_wall = find();
        if(fire_wall == 0) break;
        ans += fire_wall;
      }
      return ans;
    }
};
