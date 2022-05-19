var minMoves2 = function (nums) {
    nums.sort((a, b) => a - b);
    let [res, n] = [0, nums.length];
    for (const x of nums) {
        res += Math.abs(x - nums[parseInt(n / 2)]);
    }
    return res;
};