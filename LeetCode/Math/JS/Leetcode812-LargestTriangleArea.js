var largestTriangleArea = function (points) {
    let ans = -1;
    for (const p of points) {
        for (const p1 of points) {
            for (const p2 of points) {
                const [x1, y1] = [p[0], p[1]];
                const [x2, y2, x3, y3] = [p1[0] - x1, p1[1] - y1, p2[0] - x1, p2[1] - y1];
                ans = Math.max(ans, Math.abs(x2 * y3 - x3 * y2) / 2);
            }
        }
    }
    return ans;
};