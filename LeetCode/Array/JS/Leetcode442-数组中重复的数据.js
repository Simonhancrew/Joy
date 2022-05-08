var findDuplicates = function (nums) {
    const [n, ans] = [nums.length, []];
    for (let i = 0; i < n; i++) {
        const x = Math.abs(nums[i]);
        if (nums[x - 1] > 0) nums[x - 1] = -nums[x - 1];
        else ans.push(x);
    }
    return ans;
};