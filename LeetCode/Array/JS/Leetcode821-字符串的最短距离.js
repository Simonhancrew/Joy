var shortestToChar = function (s, c) {
    const n = s.length;
    const res = new Array(n).fill(100000);
    for (let i = 0, j = -1; i < n; i++) {
        if (s[i] == c) j = i;
        if (j != -1) res[i] = i - j;
    }
    for (let i = n - 1, j = -1; i >= 0; i--) {
        if (s[i] == c) j = i;
        if (j != -1) res[i] = Math.min(res[i], j - i);
    }
    return res;
};