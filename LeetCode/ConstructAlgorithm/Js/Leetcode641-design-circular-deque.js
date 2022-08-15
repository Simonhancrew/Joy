/**
 * @param {number} k
 */
var MyCircularDeque = function (k) {
    [this.hh, this.tt] = [0, 0];
    this.buf = new Array(k + 1).fill(0);
};

MyCircularDeque.prototype.get = function (x) {
    return (x + this.buf.length) % this.buf.length;
}


/** 
 * @param {number} value
 * @return {boolean}
 */
MyCircularDeque.prototype.insertFront = function (value) {
    if (this.isFull()) return false;
    this.hh = this.get(this.hh - 1);
    this.buf[this.hh] = value;
    return true;
};

/** 
 * @param {number} value
 * @return {boolean}
 */
MyCircularDeque.prototype.insertLast = function (value) {
    if (this.isFull()) return false;
    this.buf[this.tt] = value;
    this.tt = this.get(this.tt + 1);
    return true;
};

/**
 * @return {boolean}
 */
MyCircularDeque.prototype.deleteFront = function () {
    if (this.isEmpty()) return false;
    this.hh = this.get(this.hh + 1);
    return true;
};

/**
 * @return {boolean}
 */
MyCircularDeque.prototype.deleteLast = function () {
    if (this.isEmpty()) return false;
    this.tt = this.get(this.tt - 1);
    return true;
};

/**
 * @return {number}
 */
MyCircularDeque.prototype.getFront = function () {
    if (this.isEmpty()) return -1;
    return this.buf[this.hh];
};

/**
 * @return {number}
 */
MyCircularDeque.prototype.getRear = function () {
    if (this.isEmpty()) return -1;
    return this.buf[this.get(this.tt - 1)];
};

/**
 * @return {boolean}
 */
MyCircularDeque.prototype.isEmpty = function () {
    return this.tt === this.hh;
};

/**
 * @return {boolean}
 */
MyCircularDeque.prototype.isFull = function () {
    return this.get(this.tt + 1) == this.hh;
};
