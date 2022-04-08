var levelOrder = function (root) {
    const res = [], q = [root];
    if (!root) return res;
    while (q.length != 0) {
        const n = q.length, cur = [];
        for (let i = 0; i < n; i++) {
            const t = q.shift();
            cur.push(t.val);
            for (const ne of t.children) q.push(ne);
        }
        res.push(cur);
    }
    return res;
};