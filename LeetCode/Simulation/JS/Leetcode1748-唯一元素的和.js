var sumOfUnique = function(nums) {
    let st = new Array(101).fill(0);
    for(const num of nums) st[num] += 1;
    let ans = 0;
    for(let i = 1;i <= 100;i++) {
        if(st[i] == 1) ans += i
    }
    return ans;
};  