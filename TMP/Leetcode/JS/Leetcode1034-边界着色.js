var colorBorder = function(grid, row, col, color) {
    let n = grid.length,m = grid[0].length;
    let st = new Array(n).fill(0).map(() => new Array(m).fill(0));
    let dfs = function(x,y) {
        let is_bd = false;
        const dx = [0,1,0,-1],dy = [1,0,-1,0];
        for(let i = 0;i < 4;i++){
            let a = dx[i] + x,b = dy[i] + y;
            if(a >= 0 && a < n && b >= 0 && b < m && grid[x][y] == grid[a][b]) {
                if(st[a][b] == 0) {
                    st[a][b] = 1;
                    dfs(a,b);
                }
            }else{
                is_bd = true;
            }
        }
        if(is_bd) st[x][y] = 2;
    }
    st[row][col] = 1;
    dfs(row,col);
    for(let i = 0;i < n;i++){
        for(let j = 0;j < m;j++){
            if(st[i][j] == 2) grid[i][j] = color;
        }
    }
    return grid;
};