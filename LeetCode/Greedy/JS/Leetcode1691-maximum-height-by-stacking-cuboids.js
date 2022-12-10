var maxHeight = function (cuboids) {
  for (let x of cuboids) {
    x.sort((a, b) => a - b);
  }
  cuboids.sort((a, b) => (b[0] - a[0] || b[1] - a[1] || b[2] - a[2]));
  let [n, res] = [cuboids.length, 0];
  let f = new Array(n).fill(0);
  for (let i = 0; i < n; i++) {
    f[i] = cuboids[i][2];
    for (let j = 0; j < i; j++) {
      if (cuboids[j][1] >= cuboids[i][1] && cuboids[j][2] >= cuboids[i][2]) {
        f[i] = Math.max(f[i], f[j] + cuboids[i][2]);
      }
    }
    res = Math.max(res, f[i]);
  }
  return res;
};