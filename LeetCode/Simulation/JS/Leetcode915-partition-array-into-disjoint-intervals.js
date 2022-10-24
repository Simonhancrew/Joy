var partitionDisjoint = function(nums) {
    const n = nums.length;
    let [lmx, rmn] = [new Array(n).fill(0), new Array(n).fill(0)];
    lmx[0] = nums[0];
    rmn[n - 1] = nums[n - 1];
    for(let i = 1;i < n;i++) {
        lmx[i] = Math.max(lmx[i - 1], nums[i]);
    }
    for(let i = n - 2;i >= 0;i--) {
        rmn[i] = Math.min(rmn[i + 1], nums[i]);
    }
    let ans = 1;
    for(let i = 0;i < n - 1;i++) {
        if(lmx[i] <= rmn[i + 1]) break;
        ans++;
    }
    return ans;
};
