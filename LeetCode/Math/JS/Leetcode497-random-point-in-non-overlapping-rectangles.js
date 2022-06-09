Array.prototype.top = function () {
    return this[this.length - 1];
}
var Solution = function (rects) {
    this.areas = [0];
    this.rects = rects;
    for (let [x1, y1, x2, y2] of rects) {
        let dx = x2 - x1 + 1, dy = y2 - y1 + 1;
        this.areas.push(this.areas.top() + dx * dy);
    }
};
Solution.prototype.pick = function () {
    let x = Math.random() * this.areas.top() >> 0;
    let l = 1, r = this.areas.length;
    while (l < r) {
        let mid = l + r >> 1;
        if (this.areas[mid] >= x) r = mid;
        else l = mid + 1;
    }
    const rect = this.rects[r - 1];
    let dx = rect[2] - rect[0] + 1, dy = rect[3] - rect[1] + 1;
    let a = (Math.random() * dx >> 0) + rect[0], b = (Math.random() * dy >> 0) + rect[1];
    return [a, b];
};