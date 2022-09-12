var specialArray = function(nums) {
  nums.sort((a,b) => b - a);
  const n = nums.length;
  for(let i = 1;i <= n;i++) {
      if(nums[i - 1] >= i && (i == n || nums[i] < i)) {
          return i;
      }
  }
  return -1;
};