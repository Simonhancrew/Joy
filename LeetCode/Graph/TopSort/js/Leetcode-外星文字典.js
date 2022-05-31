var alienOrder = function (words) {
    let [mp, din, n] = [new Map(), new Map(), words.length];
    let flag = true;
    for (const word of words) {
        for (let i = 0; i < word.length; i++) {
            let c = word[i];
            if (!mp.has(c)) mp.set(c, []);
        }
    }
    let build = function (l, r) {
        const n = Math.min(l.length, r.length);
        let i = 0;
        while (i < n) {
            const [a, b] = [l[i], r[i]];
            if (a != b) {
                mp.get(a).push(b);
                din.set(b, (din.get(b) || 0) + 1);
                break;
            }
            i++;
        }
        if (i == n && l.length > r.length) {
            flag = false;
        }
    };

    for (let i = 1; i < n && flag; i++) {
        build(words[i - 1], words[i]);
    }

    // console.log(din);

    if (!flag) return "";
    let res = [];
    let topsort = function () {
        let q = [];
        for (let k of mp.keys()) {
            if (!din.has(k)) q.push(k);
        }

        let cnt = 0;

        while (q.length) {
            let t = q.shift();
            cnt++;
            // console.log("-----",t);
            res.push(t);
            for (let ne of mp.get(t)) {
                din.set(ne, din.get(ne) - 1);
                // console.log(ne,din.get(ne));
                if (din.get(ne) === 0) {
                    q.push(ne);
                }
            }
        }
        if (cnt != mp.size) return false;
        return true;
    }

    if (!topsort()) return ""
    return res.join('');
};