var oddCells = function (m, n, indices) {
    let [row, col] = [new Array(m).fill(0), new Array(n).fill(0)];
    for (const [r, c] of indices) {
        row[r]++;
        col[c]++;
    }
    let cnt = 0;
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if ((row[i] + col[j]) & 1) cnt++;
        }
    }
    return cnt;
};