/**
 * @param {number} m
 * @param {number} n
 */
 var Solution = function(m, n) {
    this.m = m,this.n = n;
    this.k = m * n;
    this.mp = new Map();
};

/**
 * @return {number[]}
 */
Solution.prototype.flip = function() {
    let idx = Math.floor(Math.random() * (this.k - 1));
    let real = idx;
    if(this.mp.has(idx)) real = this.mp.get(idx);
    if(this.mp.has(this.k - 1)) {
        this.mp.set(idx,this.mp.get(this.k - 1));
        this.mp.delete(this.k - 1);
    }else{
        this.mp.set(idx,this.k - 1);
    }
    this.k--;
    return [Math.floor(real / this.n),real % this.n];
};  

/**
 * @return {void}
 */
Solution.prototype.reset = function() {
    this.mp = new Map();
    this.k = this.m * this.n;
};  
