var shortestBridge = function (grid) {
  let [n, m] = [grid.length, grid[0].length];
  let dis = new Array(n).fill(0).map(() => new Array(m).fill(10000));
  let q = [];
  const [dx, dy] = [[0, -1, 0, 1], [1, 0, -1, 0]];
  let dfs = (x, y) => {
    q.push([x, y]);
    dis[x][y] = 0;
    grid[x][y] = 0;
    for (let i = 0; i < 4; i++) {
      let [nx, ny] = [x + dx[i], y + dy[i]];
      if (nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny]) {
        dfs(nx, ny);
      }
    }
  }
  let bfs = () => {
    while (q.length) {
      t = q.shift();
      for (let i = 0; i < 4; i++) {
        let [nx, ny] = [t[0] + dx[i], t[1] + dy[i]];
        if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
        if (grid[nx][ny] == 1) return dis[t[0]][t[1]];
        if (dis[nx][ny] > dis[t[0]][t[1]] + 1) {
          dis[nx][ny] = dis[t[0]][t[1]] + 1;
          q.push([nx, ny]);
        }
      }
    }
  }
  for (let i = 0; i < n; i++) {
    for (let j = 0; j < m; j++) {
      if (grid[i][j]) {
        dfs(i, j)
        return bfs();
      }
    }
  }
  return -1;
};