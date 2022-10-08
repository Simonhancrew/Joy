var advantageCount = function(nums1, nums2) {
  const n = nums1.length;
  nums1.sort((a,b) => a - b);
  let id = new Array(n).fill(0);
  for(let i = 0;i < n;i++) id[i] = i;
  id.sort((a,b) => nums2[a] - nums2[b]);
  let [l,r] = [0,n - 1];
  let ans = new Array(n).fill(0);
  for(let i = 0;i < n;i++) {
    if(nums1[i] > nums2[id[l]]) {
      ans[id[l]] = nums1[i];
      l++;
    }else {
      ans[id[r]] = nums1[i];
      r--;
    }
  }
  return ans;
};
