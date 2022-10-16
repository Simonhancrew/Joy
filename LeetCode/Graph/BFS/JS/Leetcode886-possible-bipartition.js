var possibleBipartition = function (n, dislikes) {
  let g = new Array(n + 1).fill(0).map(() => new Array());
  for (const d of dislikes) {
    g[d[0]].push(d[1]);
    g[d[1]].push(d[0]);
  }
  let color = new Array(n + 1).fill(0);
  let dfs = (u, c) => {
    color[u] = c;
    for (const v of g[u]) {
      if (color[v]) {
        if (color[v] == color[u]) {
          return false;
        }
      } else if (!dfs(v, 3 - c)) {
        return false;
      }
    }
    return true;
  }
  for (let i = 1; i <= n; i++) {
    if (!color[i] && !dfs(i, 1)) {
      return false;
    }
  }
  return true;
};