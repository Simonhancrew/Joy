var bestRotation = function (nums) {
    const n = nums.length;
    const b = new Array(n + 1).fill(0);
    for (let i = 0; i < n; i++) {
        const l = i - nums[i] + 1, r = i;
        if (l >= 0) {
            b[l]++, b[r + 1]--;
        } else {
            b[0]++, b[r + 1]--;
            b[l + n]++, b[n]--;
        }
    }
    let res = Math.floor(1e6 + 10), k = 0;
    for (let i = 0, sum = 0; i < n; i++) {
        sum += b[i];
        if (res > sum) {
            res = sum;
            k = i;
        }
    }
    return k;
};