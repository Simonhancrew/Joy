/**
 * @param {number[]} nums
 */
var NumArray = function(nums) {
    this.n = nums.length;
    this.tr = new Array(this.n + 1).fill(0);
    for(i = 0;i < this.n;i++) {
        this.add(i + 1,nums[i]);
    }
};

NumArray.prototype.lowbit = function(x){
    return x & -x;
}

NumArray.prototype.add = function(x,k) {
    for(let i = x;i <= this.n;i += this.lowbit(i)){
        this.tr[i] += k;
    }
}

NumArray.prototype.ask = function(x) {
    let sum = 0;
    for(let i = x;i != 0;i -= this.lowbit(i)) {
        sum += this.tr[i];
    }
    return sum;
}


/** 
 * @param {number} index 
 * @param {number} val
 * @return {void}
 */
NumArray.prototype.update = function(index, val) {
    const pre = this.ask(index + 1) - this.ask(index);
    const ch = val - pre;
    this.add(index + 1,ch);
};

/** 
 * @param {number} left 
 * @param {number} right
 * @return {number}
 */
NumArray.prototype.sumRange = function(left, right) {
    return this.ask(right + 1) - this.ask(left);
};  