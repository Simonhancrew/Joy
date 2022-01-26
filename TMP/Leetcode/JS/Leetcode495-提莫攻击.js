/**
 * @param {number[]} timeSeries
 * @param {number} duration
 * @return {number}
 */
 var findPoisonedDuration = function(timeSeries, duration) {
    let ans = 0,last = -1;
    for(const x of timeSeries){
        let t = x + duration - 1;
        ans += last < x ? duration : t - last;
        last = t;
    }
    return ans;
};