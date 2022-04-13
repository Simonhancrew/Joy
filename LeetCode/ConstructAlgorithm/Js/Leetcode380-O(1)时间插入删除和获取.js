var RandomizedSet = function () {
    this.mp = new Map();
    this.nums = [];
};

/** 
 * @param {number} val
 * @return {boolean}
 */
RandomizedSet.prototype.insert = function (val) {
    if (this.mp.has(val)) return false;
    this.nums.push(val);
    this.mp.set(val, this.nums.length - 1);
    return true;
};

/** 
 * @param {number} val
 * @return {boolean}
 */
RandomizedSet.prototype.remove = function (val) {
    if (!this.mp.has(val)) return false;
    let tar = this.nums[this.nums.length - 1];
    let [px, py] = [this.mp.get(val), this.mp.get(tar)];
    let t = this.nums[px];
    this.nums[px] = this.nums[py], this.nums[py] = t;
    t = this.mp.get(val);
    this.mp.set(tar, t);
    this.nums.pop();
    this.mp.delete(val);
    return true;
};

/**
 * @return {number}
 */
RandomizedSet.prototype.getRandom = function () {
    return this.nums[Math.floor(Math.random() * this.nums.length)];
};
