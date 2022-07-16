var MovingAverage = function (size) {
    this.size = size;
    this.sum = 0;
    this.arr = [];
};

MovingAverage.prototype.next = function (val) {
    this.arr.push(val);
    this.sum += val;
    if (this.arr.length > this.size) this.sum -= this.arr.shift();
    return this.sum / this.arr.length;
};