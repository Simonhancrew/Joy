var inorderSuccessor = function (root, p) {
    let [stk, cur, pre] = [[], root, null];
    while (stk.length || cur) {
        while (cur) {
            stk.push(cur);
            cur = cur.left;
        }
        cur = stk.pop();
        if (pre === p) return cur;
        pre = cur;
        cur = cur.right;
    }
    return null;
};