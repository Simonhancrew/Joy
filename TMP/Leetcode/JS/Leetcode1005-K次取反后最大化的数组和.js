var largestSumAfterKNegations = function(nums, k) {
    let cnt = new Map();
    let mn = 1e9;
    for(const num of nums){
        cnt.set(num,(cnt.get(num) || 0) + 1);
        mn = Math.min(mn,Math.abs(num));
    }
    for(let i = -100;i < 0 && k;i++){
        while(k && cnt.has(i) && cnt.get(i) > 0){
            cnt.set(i,cnt.get(i)- 1);
            cnt.set(-i,(cnt.get(-i) || 0) + 1);
            k--;
        }
    }
    let res = 0;
    for(let i = -100;i <= 100;i++){
        if(cnt.has(i)){
            res += cnt.get(i) * i;
        }
    }
    if(k & 1) res -= 2 * mn;
    return res;
};