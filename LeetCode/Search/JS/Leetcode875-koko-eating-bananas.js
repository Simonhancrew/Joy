var minEatingSpeed = function (piles, h) {
    let [l, r] = [1, -1];
    for (const pile of piles) {
        r = Math.max(pile, r);
    }
    let check = (k) => {
        let cnt = 0;
        for (const pile of piles) {
            if (pile < k) cnt++;
            else cnt += Math.floor((pile + k - 1) / k);
        }
        return cnt <= h;
    };

    while (l < r) {
        let mid = (l + r) >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    return l;
};