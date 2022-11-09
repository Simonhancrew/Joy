var orderOfLargestPlusSign = function(n, mines) {
  let f = new Array(n).fill(0).map(()=>new Array(n).fill(0));
  let g = new Array(n).fill(0).map(()=>new Array(n).fill(1));
  for (const x of mines) g[x[0]][x[1]] = 0;
  for(let i = 0;i < n;i++) {
    let s = 0;
    for(let j = 0;j < n;j++) {
      if(g[i][j]) s++;
      else s = 0;
      f[i][j] = s;
    }
  }
  for(let i = 0;i < n;i++) {
    for(let [j, s] = [n - 1, 0];j >= 0;j--) {
      if(g[i][j]) s++;
      else s = 0;
      f[i][j] = Math.min(f[i][j], s);
    }
  }
  for(let j = 0;j < n;j++) {
    for(let [i, s] = [0, 0];i < n;i++) {
      if(g[i][j]) s++;
      else s = 0;
      f[i][j] = Math.min(f[i][j], s);
    }
  }
  for(let j = 0;j < n;j++) {
    for(let [i, s] = [n - 1, 0];i >= 0;i--) {
      if(g[i][j]) s++;
      else s = 0;
      f[i][j] = Math.min(f[i][j], s);
    }
  }
  let res = 0;
  for(let i = 0;i < n;i++) {
    for(let j = 0;j < n;j++) {
      res = Math.max(f[i][j], res);
    }
  }
  return res;
};
