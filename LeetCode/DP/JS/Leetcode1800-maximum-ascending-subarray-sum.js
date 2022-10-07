var maxAscendingSum = function (nums) {
  let n = nums.length;
  let [f, ans] = [new Array(n).fill(0), nums[0]];
  f[0] = nums[0];
  for (let i = 1; i < n; i++) {
    if (nums[i] > nums[i - 1]) {
      f[i] = nums[i] + f[i - 1];
    } else {
      f[i] = nums[i];
    }
    ans = Math.max(ans, f[i]);
  }
  return ans;
};