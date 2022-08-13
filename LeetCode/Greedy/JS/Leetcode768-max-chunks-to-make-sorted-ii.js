var maxChunksToSorted = function (arr) {
    let b = new Array(arr.length).fill(0);
    b.splice(0, arr.length, ...arr);
    b.sort((a, b) => a - b);
    let mp = new Map();
    let [res, s] = [0, 0];
    for (let i = 0; i < arr.length; i++) {
        if ((mp.get(arr[i]) || 0) === 1) s--;
        else if ((mp.get(arr[i]) || 0) === 0) s++;
        mp.set(arr[i], (mp.get(arr[i]) || 0) - 1);
        if ((mp.get(b[i]) || 0) === -1) s--;
        else if ((mp.get(b[i]) || 0) === 0) s++;
        mp.set(b[i], (mp.get(b[i]) || 0) + 1);
        if (!s) res++;
    }
    return res;
};