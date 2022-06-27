var findLUSlength = function (strs) {
    const n = strs.length;
    let res = -1;
    let check = function (a, b) {
        const [n, m] = [a.length, b.length];
        let i = 0;
        for (const ch of b) {
            if (i < n && ch == a[i]) i++;
        }
        return i == n;
    }
    for (let i = 0; i < n; i++) {
        let flag = false;
        for (let j = 0; j < n; j++) {
            if (i != j && check(strs[i], strs[j])) {
                flag = true;
                break;
            }
        }
        if (!flag) res = Math.max(res, strs[i].length);
    }
    return res;
};