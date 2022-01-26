var Solution = function(nums) {
    this.memo = nums;
};

/**
 * @return {number[]}
 */
Solution.prototype.reset = function() {
    return this.memo;
};

/**
 * @return {number[]}
 */
Solution.prototype.shuffle = function() {
    let cp = this.memo.slice();
    let n = cp.length;
    for(let i = 0;i < n;i++){
        let  t = Math.floor(Math.random() * 200 + 1) % (n - i);
        [cp[i],cp[i + t]] = [cp[i + t],cp[i]];
    }
    return cp;
};
