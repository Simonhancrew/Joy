var CBTInserter = function(root) {
    this.rec = [new TreeNode()];
    this.root = root;
    let q = [root];
    while(q.length) {
        let t = q.shift();
        this.rec.push(t);
        if(t.left) q.push(t.left);
        if(t.right) q.push(t.right);
    }

};

/** 
 * @param {number} val
 * @return {number}
 */
CBTInserter.prototype.insert = function(val) {
    let node = new TreeNode(val);
    this.rec.push(node);
    let k = this.rec.length - 1;
    let p = parseInt(k / 2);
    if(p * 2 == k) {
        this.rec[p].left = node;
    }else{
        this.rec[p].right = node;
    }
    return this.rec[p].val;
};

/**
 * @return {TreeNode}
 */
CBTInserter.prototype.get_root = function() {
    return this.root;
};

