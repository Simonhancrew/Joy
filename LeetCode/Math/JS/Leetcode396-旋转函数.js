var maxRotateFunction = function (nums) {
    const acc = nums.reduce((tot, cur) => {
        tot += cur;
        return tot;
    });
    const n = nums.length;
    let res = 0;
    for (let i = 0; i < n; i++) {
        res += i * nums[i];
    }
    let f = res;
    for (let i = n - 1; i >= 0; i--) {
        f += acc - n * nums[i];
        res = Math.max(res, f);
    }
    return res;
};