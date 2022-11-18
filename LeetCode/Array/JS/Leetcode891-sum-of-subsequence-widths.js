var sumSubseqWidths = function(nums) {
    let [P, n] = [parseInt(1e9 + 7), nums.length];
    let p = new Array(n + 1).fill(0);
    p[0] = 1;
    for(let i = 1;i <= n;i++) {
        p[i] = p[i - 1] * 2 % P;
    }
    nums.sort((a,b)=> a - b);
    let res = 0;
    for(let i = 0;i < n;i++) {
        res = (res + nums[i] * p[i] - nums[i] * p[n - i - 1]) % P;
    }
    return res;
};
