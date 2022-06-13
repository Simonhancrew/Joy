var heightChecker = function (heights) {
    let [rec, n] = [[...heights], heights.length];
    let ans = 0;
    rec.sort((a, b) => a - b);
    for (let i = 0; i < n; i++) {
        if (rec[i] != heights[i]) ans++;
    }
    return ans;
};