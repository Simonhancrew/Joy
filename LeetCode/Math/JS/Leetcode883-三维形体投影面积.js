var projectionArea = function(grid) {
    const n = grid.length;
    let [l,r,d] = [0,0,0];
    for(let i = 0;i < n;i++) {
        let [tl,tr] = [0,0];
        for(let j = 0;j < n;j++) {
            if(grid[i][j]) d++;
            tl = Math.max(tl,grid[i][j]);
            tr = Math.max(tr,grid[j][i]);
        }
        l += tl,r += tr;
    }
    return l + r + d;
};