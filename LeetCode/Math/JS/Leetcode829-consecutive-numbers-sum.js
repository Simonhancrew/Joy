var consecutiveNumbersSum = function (_n) {
    let [n, res] = [_n * 2, 0];
    for (let b = 1; b <= n / b; b++) {
        if (n % b == 0) {
            if ((n / b - b + 1) % 2 == 0) res++;
        }
    }
    return res;
};