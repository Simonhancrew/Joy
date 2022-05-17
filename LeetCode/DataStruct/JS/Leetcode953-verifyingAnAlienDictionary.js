var isAlienSorted = function (words, order) {
    let n = order.length;
    let mp = new Map();
    for (let i = 0; i < n; i++) mp.set(order[i], i);
    for (let i = 1; i < words.length; i++) {
        const l = words[i - 1], r = words[i];
        let [x, y] = [0, 0];
        while (x < l.length && y < r.length) {
            if (mp.get(l[x]) > mp.get(r[y])) return false;
            if (mp.get(l[x]) < mp.get(r[y])) break;
            x++; y++;
        }
        if (x < l.length && y == r.length) return false;
    }
    return true;
};