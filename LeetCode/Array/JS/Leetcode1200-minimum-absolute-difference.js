var minimumAbsDifference = function (arr) {
    arr.sort((a, b) => a - b);
    let [res, n, mini] = [[], arr.length, 1 << 30];
    for (let i = 0; i < n - 1; i++) {
        let diff = arr[i + 1] - arr[i];
        if (diff == mini) {
            res.push([arr[i], arr[i + 1]]);
        } else if (diff < mini) {
            mini = diff;
            res = [[arr[i], arr[i + 1]]];
        }
    }
    return res;
};