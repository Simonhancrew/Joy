var largestSumOfAverages = function (nums, k) {
  const n = nums.length;
  let [f, s] = [new Array(n + 1).fill(0).map(() => new Array(k + 1).fill(-10000)), new Array(n + 1).fill(0)];
  for (let i = 1; i <= n; i++) s[i] = s[i - 1] + nums[i - 1];
  f[0][0] = 0;
  for (let i = 1; i <= n; i++) {
    for (let j = 1; j <= k; j++) {
      for (let q = 0; q < i; q++) {
        f[i][j] = Math.max(f[i][j], f[q][j - 1] + (s[i] - s[q]) / (i - q));
      }
    }
  }
  return f[n][k];
};