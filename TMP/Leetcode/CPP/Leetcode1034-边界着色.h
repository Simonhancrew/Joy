class Solution {
public:
    const int dx[4] = {0,1,0,-1},dy[4] = {1,0,-1,0}; 
    vector<vector<int>> st; // 0 没搜过，1 搜过，2 搜过且是边界
    int m,n;
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        n = grid.size(),m = grid[0].size();
        st = vector<vector<int>> (n,vector<int> (m,0));
        st[row][col] = 1;
        dfs(grid,row,col,color);
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(st[i][j] == 2) grid[i][j] = color;
            }
        }
        return grid;
    }
    void dfs(vector<vector<int>>& grid,int x,int y,int c){
        bool is_bd = false;
        for(int i = 0;i < 4;i++){
            int nx = dx[i] + x,ny = dy[i] + y;
            if(nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid[0].size() && grid[nx][ny] == grid[x][y]){
                if(!st[nx][ny]) {
                    st[nx][ny] = 1;
                    dfs(grid,nx,ny,c);
                }
            }else is_bd = true;
        }
        if(is_bd) st[x][y] = 2;
    }
};