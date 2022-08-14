var maxScore = function (s) {
    let [lhs, rhs] = [0, 0];
    for (const ch of s) {
        if (ch == '1') rhs++;
    }
    let [res, n] = [0, s.length];
    for (let i = 0; i < n - 1; i++) {
        if (s[i] == '1') rhs--;
        else lhs++;
        res = Math.max(res, lhs + rhs);
    }
    return res;
};