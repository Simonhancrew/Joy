var shuffle = function(nums, n) {
    let ans = new Array(n * 2).fill(0);
    for(let i = 0;i < n;i++) {
        ans[i * 2] = nums[i];
        ans[i * 2 + 1] = nums[i + n];
    }
    return ans;
};