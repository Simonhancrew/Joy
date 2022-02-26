var maximumDifference = function(nums) {
    const n = nums.length;
    let ans = -1,mn = nums[0];
    for(let i = 1;i < n;i++) {
        if(nums[i] > mn) ans = Math.max(ans,nums[i] - mn);
        else mn = nums[i];
    }
    return ans;
};