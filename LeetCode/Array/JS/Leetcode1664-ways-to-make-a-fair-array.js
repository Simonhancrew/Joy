var waysToMakeFair = function (nums) {
  const n = nums.length;
  let [s1, s2] = [new Array(n + 1).fill(0), new Array(n + 1).fill(0)];
  for (let i = 1; i <= n; i++) {
    s1[i] = s1[i - 1];
    s2[i] = s2[i - 1];
    if (i % 2) {
      s1[i] += nums[i - 1];
    } else {
      s2[i] += nums[i - 1];
    }
  }
  let res = 0;
  for (let i = 1; i <= n; i++) {
    const [odd, even] = [s1[i - 1] + s2[n] - s2[i], s2[i - 1] + s1[n] - s1[i]];
    if (odd === even) ++res;
  }
  return res;
};