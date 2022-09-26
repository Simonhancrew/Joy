var missingTwo = function(nums) {
  let [ans,n,acc] = [[0,0], nums.length + 2,0];
  for(const num of nums) {
    acc ^= num;
  }
  for(let i = 1;i <= n;i++) {
    acc ^= i;
  }
  const lowbit = acc & (-acc);
  for(const num of nums) {
    if(lowbit & num) {
      ans[0] ^= num;
    }else {
      ans[1] ^= num;
    }
  }
  for(let i = 1;i <= n;i++) {
    if (lowbit & i) {
      ans[0] ^= i;
    }else {
      ans[1] ^= i;
    }
  }
  return ans;
};
