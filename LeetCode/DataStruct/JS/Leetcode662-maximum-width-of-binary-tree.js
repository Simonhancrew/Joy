var widthOfBinaryTree = function(root) {
    let mx = 0;
    let q = [[root,1]];
    while(q.length) {
        const [l,n] = [q[0][1],q.length];
        let r = 0;
        for(let i = 0;i < n;i++) {
            let [node,p] = [q[0][0],q[0][1] - l + 1];
            r = q[0][1];
            q.shift();
            if(node.left != null) {
                q.push([node.left,p * 2]);
            }
            if(node.right != null) {
                q.push([node.right,p * 2 + 1]);
            }
        }
        mx = Math.max(mx,r - l + 1);
    }
    return mx;
};
