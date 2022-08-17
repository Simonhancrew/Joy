var deepestLeavesSum = function (root) {
    let [ans, q] = [0, []];
    q.push(root);
    while (q.length) {
        let n = q.length;
        ans = 0;
        for (let i = 0; i < n; i++) {
            let t = q.shift();
            ans += t.val;
            if (t.left) {
                q.push(t.left);
            }
            if (t.right) {
                q.push(t.right);
            }
        }
    }
    return ans;
};