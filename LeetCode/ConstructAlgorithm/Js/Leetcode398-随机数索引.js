var Solution = function (nums) {
    this.nums = nums;
};

Solution.prototype.pick = function (target) {
    let [cnt, res, n] = [0, 0, this.nums.length];
    for (let i = 0; i < n; i++) {
        if (this.nums[i] == target) {
            cnt++;
            if (Math.floor(Math.random() * cnt) == 0) {
                res = i;
            }
        }
    }
    return res;
};