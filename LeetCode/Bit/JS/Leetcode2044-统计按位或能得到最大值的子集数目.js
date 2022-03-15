var countMaxOrSubsets = function (nums) {
    const n = nums.length;
    let mxor = 0, ans = 0;
    for (let i = 1; i < 1 << n; i++) {
        let cur = 0
        for (let j = 0; j < n; j++) {
            if (i >> j & 1) cur |= nums[j];
        }
        if (cur == mxor) {
            ans++;
        } else if (cur > mxor) {
            ans = 1;
            mxor = cur;
        }
    }
    return ans;
};