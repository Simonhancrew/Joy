/**
 * @param {number} n
 */
var OrderedStream = function (n) {
    this.mp = new Map();
    this.ptr = 1;
};

/** 
 * @param {number} idKey 
 * @param {string} value
 * @return {string[]}
 */
OrderedStream.prototype.insert = function (idKey, value) {
    this.mp.set(idKey, value);
    let ans = [];
    if (!this.mp.has(this.ptr)) return ans;
    while (this.mp.has(this.ptr)) {
        ans.push(this.mp.get(this.ptr));
        this.ptr++;
    }
    return ans;
};