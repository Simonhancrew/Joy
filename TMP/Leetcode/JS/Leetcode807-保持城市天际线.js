var maxIncreaseKeepingSkyline = function(grid) {
    let n = grid.length,m = grid[0].length;
    let row = new Array(n).fill(0),col = new Array(m).fill(0);
    for(let i = 0;i < n;i++){
        for(let j = 0;j < m;j++){
            row[i] = Math.max(row[i],grid[i][j]);
            col[j] = Math.max(col[j],grid[i][j]);
        }
    }
    let res = 0;
    for(let i = 0;i < n;i++){
        for(let j = 0;j < m;j++){
            res += Math.min(col[j],row[i]) - grid[i][j];
        }
    }
    return res;
};