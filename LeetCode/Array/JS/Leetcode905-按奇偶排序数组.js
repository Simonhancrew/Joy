var sortArrayByParity = function (nums) {
    let [l, r] = [0, nums.length - 1];
    while (l < r) {
        while (l < r && nums[l] % 2 === 0) l++
        while (l < r && nums[r] % 2 === 1) r--
        const tmp = nums[l];
        nums[l] = nums[r], nums[r] = tmp;
        l++, r--;
    }
    return nums;
};