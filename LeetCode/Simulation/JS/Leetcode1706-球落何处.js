var findBall = function(grid) {
    const n = grid.length,m = grid[0].length,ans = [];
    for(let i = 0;i < m;i++) {
        let x = 0,y = i,z = 0;
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
        ans.push(y);
    }
    return ans;
};