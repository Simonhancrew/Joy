var longestUnivaluePath = function(root) {
  let res = 0;
  let dfs = (node) => {
    if(!node) {
      return 0;
    }
    const [l,r] = [dfs(node.left),dfs(node.right)];
    let [ll,rr] = [0,0];
    if(node.left && node.left.val == node.val) ll = l + 1;
    if(node.right && node.right.val == node.val) rr = r + 1;
    res = Math.max(res,ll + rr);
    return Math.max(ll,rr);
  }
};
