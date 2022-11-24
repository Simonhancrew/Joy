var numSubarrayBoundedMax = function (nums, left, right) {
  const n = nums.length;
  let calcu = (mx) => {
    let res = 0;
    for (let i = 0; i < n; i++) {
      if (nums[i] > mx) continue;
      let j = i + 1;
      while (j < n && nums[j] <= mx) j++;
      const dis = j - i;
      res += Math.floor((dis + 1) * dis / 2);
      i = j;
    }
    return res;
  }
  return calcu(right) - calcu(left - 1);
};