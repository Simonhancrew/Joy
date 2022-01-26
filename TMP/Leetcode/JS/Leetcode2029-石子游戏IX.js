var stoneGameIX = function(stones) {
    const cnt = [0,0,0];
    for(const st of stones) cnt[st % 3]++;
    return cnt[0] % 2 == 0 ? cnt[1] >= 1 && cnt[2] >= 1 : Math.abs(cnt[1] - cnt[2]) > 2;
};