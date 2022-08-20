var constructMaximumBinaryTree = function(nums) {
    let n = nums.length;
    if(!n) return null;
    let dfs = function(num,l,r) {
        if(l == r) {
            return new TreeNode(nums[l]);
        }
        if(l > r) return null;
        let [max_v,idx] = [0,l];
        for(let i = l;i <= r;i++) {
            if(max_v < nums[i]) {
                max_v = nums[i];
                idx = i;
            }
        }
        let node = new TreeNode(max_v);
        node.left = dfs(nums,l,idx-1);
        node.right = dfs(nums,idx + 1,r);
        return node;
    }
    return dfs(nums,0,n - 1);
};