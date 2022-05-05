var numSubarrayProductLessThanK = function (nums, k) {
    let [acc, res, n] = [1, 0, nums.length];
    for (let i = 0, j = 0; j < n; j++) {
        acc *= nums[j];
        while (i <= j && acc >= k) {
            acc = Math.floor(acc / nums[i]);
            i++;
        }
        res += j - i + 1;
    }
    return res;
};