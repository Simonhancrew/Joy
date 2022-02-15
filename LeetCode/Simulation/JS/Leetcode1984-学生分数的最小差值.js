var minimumDifference = function(nums, k) {
    nums.sort((a,b) => a - b);
    const n = nums.length;
    let ans = Math.floor(1e8);
    for(let i = 0;i <= n - k;i++) {
        if(nums[i + k - 1] - nums[i] < ans) ans = nums[i + k - 1] - nums[i];
    }
    return ans;
};