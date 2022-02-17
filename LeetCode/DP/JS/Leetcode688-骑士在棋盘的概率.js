var knightProbability = function(n, k, row, column) {
    const dx = [-2, -1, 1, 2, 2, 1, -1, -2],dy = [1, 2, 2, 1, -1, -2, -2, -1];
    const f = new Array(n).fill(0).map(() => new Array(n).fill(0).map(() => new Array(k + 1).fill(0)));
    for(let st = 0;st <= k;st++) {
        for(let i = 0;i < n;i++){
            for(let j = 0;j < n;j++) {
                if(st == 0) f[i][j][st] = 1;
                else{
                    for(let d = 0;d < 8;d++){
                        let ni = i + dx[d],nj = j + dy[d];
                        if(ni < 0 || ni >= n || nj < 0 || nj >= n) continue;
                        f[i][j][st] += f[ni][nj][st - 1] / 8;
                    }
                }
            }
        } 
    }
    return f[row][column][k];
};