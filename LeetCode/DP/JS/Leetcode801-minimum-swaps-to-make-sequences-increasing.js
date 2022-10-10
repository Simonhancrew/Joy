var minSwap = function (nums1, nums2) {
  const n = nums1.length;
  let f = new Array(n).fill(0).map(() => new Array(2).fill(parseInt(1e9)));
  [f[0][0], f[0][1]] = [0, 1];
  for (let i = 1; i < n; i++) {
    if (nums1[i] > nums1[i - 1] && nums2[i] > nums2[i - 1]) {
      f[i][0] = Math.min(f[i][0], f[i - 1][0]);
      f[i][1] = Math.min(f[i][1], f[i - 1][1] + 1);
    }

    if (nums1[i] > nums2[i - 1] && nums2[i] > nums1[i - 1]) {
      f[i][0] = Math.min(f[i][0], f[i - 1][1]);
      f[i][1] = Math.min(f[i][1], f[i - 1][0] + 1);
    }
  }
  return Math.min(f[n - 1][0], f[n - 1][1]);
};