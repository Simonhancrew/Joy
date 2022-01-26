var isEvenOddTree = function(root) {
    const q = [];
    let st = true;
    q.push(root);
    while(q.length){
        const n = q.length;
        let pre = -1,cur = 0;
        for(let i = 0;i < n;i++){
            let t = q.shift();
            pre = cur,cur = t.val;
            if(t.left) q.push(t.left);
            if(t.right) q.push(t.right);
            if(st){
                if(cur % 2 == 0) return false;
                if(i > 0 && pre >= cur) return false;
            }else{
                if(cur % 2 == 1) return false;
                if(i > 0 && pre <= cur) return false;
            }
        }
        st = !st;
    }
    return true;
};