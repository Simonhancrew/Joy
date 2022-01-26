var increasingTriplet = function(nums) {
    const INF = Number.MAX_VALUE;
    // console.log(INF);
    const f = [INF,INF];
    for(const num of nums){
        let k = 2;
        while(k > 0 && f[k - 1] >= num) k--;
        if(k == 2) return true;
        f[k] = num;
    }
    return false;
};