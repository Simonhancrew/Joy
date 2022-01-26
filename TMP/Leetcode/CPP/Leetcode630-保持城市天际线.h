class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int res = 0,n = grid.size(),m = grid[0].size();
        vector<int> row(n),col(m);
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                row[i] = max(row[i],grid[i][j]);
                col[j] = max(col[j],grid[i][j]);
            }
        }
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                res += min(row[i],col[j]) - grid[i][j];
            }
        }
        return res;
    }
};