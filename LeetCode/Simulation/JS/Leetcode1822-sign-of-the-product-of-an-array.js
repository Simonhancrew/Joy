var arraySign = function (nums) {
  let [nag, n] = [0, nums.length];
  for (let i = 0; i < n; i++) {
    if (nums[i] == 0) return 0;
    if (nums[i] < 0) nag++;
  }
  return nag % 2 ? -1 : 1;
};