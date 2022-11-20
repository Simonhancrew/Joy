var champagneTower = function (poured, query_row, query_glass) {
  let f = new Array(query_row + 1).fill(0).map(() => new Array(query_row + 1).fill(0));
  f[0][0] = poured;
  for (let i = 0; i < query_row; i++) {
    for (let j = 0; j <= i; j++) {
      if (f[i][j] > 1) {
        const x = (f[i][j] - 1) / 2;
        f[i + 1][j] += x;
        f[i + 1][j + 1] += x;
      }
    }
  }
  console.log(f);
  return Math.min(f[query_row][query_glass], 1.0);
};