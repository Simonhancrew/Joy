var subArrayRanges = function (nums) {
    let res = 0;
    const n = nums.length;
    for (let i = 0; i < n; i++) {
        let mx = nums[i], mn = nums[i];
        for (let j = i + 1; j < n; j++) {
            mx = Math.max(mx, nums[j])
            mn = Math.min(mn, nums[j])
            res += mx - mn;
        }
    }
    return res;
};