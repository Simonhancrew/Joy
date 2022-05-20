var findRightInterval = function (intervals) {
    const n = intervals.length;
    let res = new Array(n).fill(-1);
    for (let i = 0; i < n; i++) intervals[i].push(i);
    intervals.sort((a, b) => a[0] - b[0]);
    for (const x of intervals) {
        let [l, r] = [0, n - 1];
        while (l < r) {
            const mid = (l + r) >> 1;
            if (intervals[mid][0] >= x[1]) r = mid;
            else l = mid + 1;
        }
        if (intervals[l][0] >= x[1]) res[x[2]] = intervals[l][2];
    }
    return res;
};