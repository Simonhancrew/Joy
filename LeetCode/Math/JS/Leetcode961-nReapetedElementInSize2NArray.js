var repeatedNTimes = function (nums) {
    const n = nums.length;
    while (true) {
        const [x, y] = [parseInt(Math.random() * n), parseInt(Math.random() * n)];
        if (x != y && nums[x] == nums[y]) return nums[x];
    }
};