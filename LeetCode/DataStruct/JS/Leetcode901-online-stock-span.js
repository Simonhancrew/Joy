var StockSpanner = function() {
    this.stk = [[-1, parseInt(1e6)]];
    this.idx = 0;
};

/** 
 * @param {number} price
 * @return {number}
 */
StockSpanner.prototype.next = function(price) {
    while(price >= this.stk[this.stk.length - 1][1]) {
        this.stk.pop();
    }
    let res = this.idx - this.stk[this.stk.length - 1][0];
    this.stk.push([this.idx, price]);
    this.idx += 1;
    return res;
};
