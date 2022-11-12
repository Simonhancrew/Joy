var numTilings = function (n) {
  let w = [[1, 1, 1, 1], [0, 0, 1, 1], [0, 1, 0, 1], [1, 0, 0, 0]];
  let f = new Array(n + 1).fill(0).map(() => new Array(4).fill(0));
  const P = parseInt(1e9 + 7);
  f[0][0] = 1;
  for (let i = 0; i < n; i++) {
    for (let j = 0; j < 4; j++) {
      for (let k = 0; k < 4; k++) {
        f[i + 1][k] = (f[i + 1][k] + f[i][j] * w[j][k]) % P;
      }
    }
  }
  return f[n][0];
};