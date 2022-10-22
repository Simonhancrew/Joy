var jobScheduling = function (startTime, endTime, profit) {
  let [n, arr] = [startTime.length, []];
  for (let i = 0; i < n; i++) arr.push([startTime[i], endTime[i], profit[i]]);
  arr.sort((a, b) => a[1] - b[1]);
  let f = new Array(n).fill(0);
  f[0] = arr[0][2];
  for (let i = 1; i < n; i++) {
    f[i] = Math.max(f[i - 1], arr[i][2]);
    if (arr[i][0] >= arr[0][1]) {
      let [l, r] = [0, i - 1];
      while (l < r) {
        const mid = l + r + 1 >> 1;
        if (arr[mid][1] <= arr[i][0]) l = mid;
        else r = mid - 1;
      }
      f[i] = Math.max(f[i], f[r] + arr[i][2]);
    }
  }
  return f[n - 1];
};