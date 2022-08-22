var printTree = function(root) {
    let hei = 0;
    let dfs = function(node,level) {
        if(!node) {
            return;
        }
        if(level > hei) {
            hei = level;
        }
        dfs(node.left,level + 1);
        dfs(node.right,level + 1); 
    }
    dfs(root,0);
    const [n,m] = [hei + 1,(1 << (hei + 1)) - 1]
    let ans = new Array(n).fill(0).map(()=> new Array(m).fill(""));
    let dfs_fill = function(node,x,y) {
        if(!node) {
            return;
        }
        ans[x][y] = String(node.val);
        if(node.left) {
            dfs_fill(node.left,x + 1,y - (1 << (hei - x - 1)));
        }
        if(node.right) {
            dfs_fill(node.right,x + 1,y + (1 << (hei - x - 1)));
        }
    }
    dfs_fill(root,0,parseInt((m - 1) / 2));
    return ans;
};