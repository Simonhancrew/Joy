var maxDepth = function(root) {
    if(!root) return 0;
    let res = 0;
    for(const node of root.children){
        res = Math.max(res,maxDepth(node));
    }
    return res + 1;
};