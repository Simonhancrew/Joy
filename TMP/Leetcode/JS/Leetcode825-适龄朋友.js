var numFriendRequests = function(ages) {
    const n = ages.length;
    let res = n * n,cnt = new Array(121).fill(0);
    for(const age of ages) cnt[age]++;
    for(let i = 1;i <= 120;i++){
        for(let j = 1;j <= 120;j++){
            if(j > i || j <= 0.5 * i + 7) res -= cnt[i] * cnt[j];
            else if(i == j) res -= cnt[i];
        }
    }
    return res; 
};