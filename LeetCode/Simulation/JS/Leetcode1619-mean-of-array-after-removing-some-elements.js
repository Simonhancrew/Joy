var trimMean = function(arr) {
    arr.sort((a,b) => a - b);
    const n = arr.length;
    let acc = 0;
    for(let i = Math.floor(n / 20);i < Math.floor((n * 19) / 20);i++) {
        acc += arr[i];
    }
    return acc / (0.9 * n);
};
