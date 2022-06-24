var largestValues = function (root) {
    let ans = [];
    if (!root) return ans;
    let q = [root];
    while (q.length) {
        let [n, cur] = [q.length, 1 << 31];
        for (let i = 0; i < n; i++) {
            let t = q.shift();
            cur = Math.max(cur, t.val);
            if (t.left) q.push(t.left);
            if (t.right) q.push(t.right);
        }
        ans.push(cur);
    }
    return ans;
};