var isIdealPermutation = function(nums) {
    let [lmin, n] = [nums[nums.length - 1], nums.length];
    for(let i = n - 2;i > 0;i--) {
        if (nums[i - 1] > lmin) {
            return false;
        }
        lmin = Math.min(lmin, nums[i]);
    }
    return true;
};
