var getMaximumGold = function(grid) {
    const dx = [0,1,0,-1],dy = [1,0,-1,0];
    const n = grid.length,m = grid[0].length;
    let ans = 0;
    let dfs = function(x,y,beg) {
        beg += grid[x][y];
        ans = Math.max(ans,beg);
        const rec = grid[x][y];
        grid[x][y] = 0;
        for(let i = 0;i < 4;i++) {
            const nx = x + dx[i],ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(grid[nx][ny] == 0) continue;
            dfs(nx,ny,beg);
        }
        grid[x][y] = rec;
    }
    for(let i = 0;i < n;i++) {
        for(let j = 0;j < m;j++) {
            if(grid[i][j] != 0) dfs(i,j,0);
        }
    }
    return ans;
};