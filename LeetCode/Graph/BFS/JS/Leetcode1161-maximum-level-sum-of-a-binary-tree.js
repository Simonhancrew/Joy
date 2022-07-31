var maxLevelSum = function (root) {
    let [ans, level, layer] = [parseInt(-1e9), 0, 0];
    let q = [root];
    while (q.length) {
        let [n, cur] = [q.length, 0];
        layer++;
        for (let i = 0; i < n; i++) {
            const t = q.shift();
            cur += t.val;
            if (t.left) q.push(t.left);
            if (t.right) q.push(t.right);
        }
        if (cur > ans) {
            ans = cur;
            level = layer;
        }
    }
    return level;
};