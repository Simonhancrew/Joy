class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int n = grid.size(),m = grid[0].size();
        vector<int> ans;
        for(int i = 0;i < m;i++) {
            int x = 0,y = i,z = 0;
            while(x < n) {
                if(!z) {
                    if(grid[x][y] == 1) {
                        if(y + 1 >= m || grid[x][y + 1] == -1) y = -1;
                        else y++,z = 1;
                    }else{
                        if(y - 1 < 0 || grid[x][y - 1] == 1) y = -1;
                        else y--,z = 1;
                    }
                }else{
                    x++,z = 0;
                }
                if(y == -1) break;
            }
            ans.push_back(y);
        }
        return ans;
    }
};