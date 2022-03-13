var validUtf8 = function (data) {
    const n = data.length;
    var get = function (a, b) {
        return (a >> b) & 1;
    };
    for (let i = 0; i < n; i++) {
        if (get(data[i], 7) == 0) continue;
        let cnt = 0;
        while (cnt <= 4 && get(data[i], 7 - cnt) == 1) cnt++;
        if (cnt == 1 || cnt > 4) return false;
        for (let j = 1; j < cnt; j++) {
            let t = j + i;
            if (t >= n) return false;
            if (!(get(data[t], 7) == 1 && get(data[t], 6) == 0)) return false;
        }
        i += cnt - 1;
    }
    return true;
};