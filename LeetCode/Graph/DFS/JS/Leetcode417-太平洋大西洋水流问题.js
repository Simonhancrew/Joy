var pacificAtlantic = function(heights) {
    const n = heights.length,m = heights[0].length;
    let res = [],st = new Array(n).fill(0).map(()=>new Array(m).fill(0));
    const dx = [0,1,0,-1],dy = [1,0,-1,0];
    let dfs = function(x,y,t) {
        if(st[x][y] & t) return;
        st[x][y] |= t;
        for(let i = 0;i < 4;i++) {
            const nx = x + dx[i],ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(heights[nx][ny] < heights[x][y]) continue;
            dfs(nx,ny,t);
        }
    }
    for(let i = 0;i < n;i++) dfs(i,0,1),dfs(i,m - 1,2);
    for(let i = 0;i < m;i++) dfs(0,i,1),dfs(n - 1,i,2);
    for(let i = 0;i < n;i++) {
        for(let j = 0;j < m;j++) {
            if(st[i][j] == 3) res.push([i,j]); 
        }
    }
    return res;
};