var maximumSum = function (arr) {
  const n = arr.length;
  let [f, g] = [new Array(n).fill(0), new Array(n).fill(0)];
  [f[0], g[0]] = [arr[0], -1e5];
  let ans = arr[0];
  for (let i = 1; i < n; i++) {
    f[i] = Math.max(f[i - 1] + arr[i], arr[i]);
    g[i] = Math.max(g[i - 1] + arr[i], f[i - 1]);
    ans = Math.max(ans, f[i], g[i]);
  }
  return ans;
};
