var Solution = function (radius, x_center, y_center) {
    [this.x, this.y, this.r] = [x_center, y_center, radius];
};

Solution.prototype.randPoint = function () {
    let [a, b] = [Math.random() * 2 - 1, Math.random() * 2 - 1];
    if (a * a + b * b > 1) return this.randPoint();
    return [this.x + a * this.r, this.y + b * this.r];
};