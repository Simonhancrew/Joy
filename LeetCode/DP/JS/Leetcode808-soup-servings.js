
var soupServings = function (n) {
  n = parseInt((n + 24) / 25);
  if (n >= 200) return 1;
  let f = new Array(n + 1).fill(0).map(() => new Array(n + 1).fill(0));
  let gen = (x) => Math.max(x, 0);
  for (let i = 0; i <= n; i++) {
    for (let j = 0; j <= n; j++) {
      if (!i && !j) f[i][j] = 0.5;
      else if (i && !j) f[i][j] = 0;
      else if (!i && j) f[i][j] = 1;
      else {
        f[i][j] = (f[gen(i - 4)][j] + f[gen(i - 3)][gen(j - 1)] + f[gen(i - 2)][gen(j - 2)] + f[gen(i - 1)][gen(j - 3)]) / 4;
      }
    }
  }
  return f[n][n];
};