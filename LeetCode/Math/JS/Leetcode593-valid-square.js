var validSquare = function (p1, p2, p3, p4) {
    let p = [p1, p2, p3, p4];
    let d = [];
    let calcu = function (a, b) {
        let [dx, dy] = [a[0] - b[0], a[1] - b[1]];
        return dx * dx + dy * dy;
    }
    for (let i = 0; i < 4; i++) {
        for (let j = i + 1; j < 4; j++) {
            d.push(calcu(p[i], p[j]));
        }
    }
    d.sort((a, b) => a - b);
    if (!d[0]) return false;
    return d[0] == d[1] && d[0] == d[2] && d[0] == d[3] && d[4] == d[5];
};