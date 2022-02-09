var countKDifference = function(nums, k) {
    const mp = new Map();
    let ans = 0;
    for(const num of nums) {
        if(mp.has(num + k)) ans += mp.get(num + k);
        if(mp.has(num - k)) ans += mp.get(num - k);
        mp.set(num,(mp.get(num) || 0) + 1);
    }
    return ans;
};