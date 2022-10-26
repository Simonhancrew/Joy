var shortestSubarray = function (nums, k) {
  const n = nums.length;
  let s = new Array(n + 1).fill(0);
  for (let i = 1; i <= n; i++) {
    s[i] = s[i - 1] + nums[i - 1];
  }
  let q = [0];
  let res = 10000000;
  for (let i = 1; i <= n; i++) {
    while (q.length && s[q[0]] + k <= s[i]) {
      res = Math.min(res, i - q[0]);
      q.shift();
    }
    while (q.length && s[q[q.length - 1]] >= s[i]) {
      q.pop();
    }
    q.push(i);
  }
  if (res == 10000000) return -1;
  return res;
};