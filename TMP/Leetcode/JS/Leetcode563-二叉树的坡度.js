var findTilt = function(root) {
    let ans = 0;
    const dfs = function(root){
        if(!root) return 0;
        let lhs = dfs(root.left),rhs = dfs(root.right);
        ans += Math.abs(lhs - rhs)
        return lhs + rhs + root.val;
    };
    dfs(root);
    return ans;
};