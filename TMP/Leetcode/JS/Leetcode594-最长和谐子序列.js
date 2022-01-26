var findLHS = function(nums) {
    let mp = new Map();
    for(const x of nums) mp.set(x,(mp.get(x) || 0) + 1);
    let res = 0;
    for(const [k,v] of mp){
        if(mp.has(k - 1)){
            res = Math.max(res,v + mp.get(k - 1));
        }
    }
    return res;
};