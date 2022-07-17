var arrayNesting = function (nums) {
    const n = nums.length;
    let ans = 0;
    for (let i = 0; i < n; i++) {
        if (nums[i] == -1) continue;
        let [ne, cur] = [i, 0];
        while (nums[ne] != -1) {
            cur += 1;
            const t = ne;
            ne = nums[ne];
            nums[t] = -1;
        }
        ans = Math.max(ans, cur);
    }
    return ans;
};