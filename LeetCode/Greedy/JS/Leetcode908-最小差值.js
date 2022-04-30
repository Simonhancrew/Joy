var smallestRangeI = function (nums, k) {
    let x = 100000, y = -1
    for (const e of nums) {
        x = Math.min(x, e);
        y = Math.max(y, e);
    }
    return Math.max(0, y - x - 2 * k);
};