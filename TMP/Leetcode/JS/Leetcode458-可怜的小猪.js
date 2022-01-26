var poorPigs = function(buckets, minutesToDie, minutesToTest) {
    let k = minutesToTest / minutesToDie;
    // console.log(k);
    return Math.ceil(Math.log(buckets) / Math.log(k + 1));
};