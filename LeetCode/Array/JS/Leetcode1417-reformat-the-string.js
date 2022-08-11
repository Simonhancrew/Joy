var reformat = function (s) {
    const isdigit = (x) => {
        return parseFloat(x).toString() == "NaN" ? false : true;
    }
    let [cnt, n] = [0, s.length];
    for (let i = 0; i < n; i++) {
        if (isdigit(s[i])) cnt++;
    }
    if (Math.abs(cnt - n + cnt) > 1) return "";
    let flag = cnt > n - cnt;
    let arr = [...s];
    for (let i = 0, j = 1; i < n; i += 2) {
        if (isdigit(arr[i]) != flag) {
            while (isdigit(arr[j]) != flag) {
                j += 2;
            }
            [arr[i], arr[j]] = [arr[j], arr[i]];
        }
    }
    return arr.join('');
};